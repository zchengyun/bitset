#include <bitset>
#include <cassert>
#include <iostream>

//标准逻辑运算符操作bitset，并将它与字符串和整数相互转换。
int main()
{
	// 构造函数：
	constexpr std::bitset<4> b1; //constexpr编译器可计算出值，4代表4bit，默认为0
	constexpr std::bitset<8> b2{ 0xAA }; // == 0B1010
	std::bitset<4> b3{ "0011" }; // 尚不能为 constexpr
	std::bitset<8> b4{ "ACCA",4, 'A', 'C' }; // == 0B0000'0110,A对应0,C对应1
	std::cout << "b1:" << b1 << "; b2:" << b2 << "; b3:" << b3 << "; b4:" << b4 << '\n';

	// 逐位运算：
	std::cout << "逐位运算：" << std::endl;
	b3 |= 0b0100; 
	std::cout << "b3:" << b3 <<std::endl;//0111
	b3 &= 0b0011; 
	std::cout << "b3:" << b3 << std::endl;//0011
	b3 ^= std::bitset<4>{0b1100}; 
	std::cout << "b3:" << b3 << std::endl;//1111

	// 集合操作：
	std::cout << "集合操作：" << std::endl;
	b3.reset(); //全部置为0
	std::cout << "b3:" << b3 << std::endl;//0000
	b3.set(); //全部置为1
	std::cout << "b3:" << b3 << std::endl;//1111
	b3.flip(); //按位取反
	std::cout << "b3:" << b3 << std::endl;//0000

	// 单独位操作
	std::cout << "单独位操作：" << std::endl;
	b3.set( 1, true);  
	std::cout << "b3:" << b3 << std::endl;//0010
	b3.set( 1, false); 
	std::cout << "b3:" << b3 << std::endl;//0000
	b3.flip(2); 
	std::cout << "b3:" << b3 << std::endl;//0100
	b3.reset( 2); 
	std::cout << "b3:" << b3 << std::endl;//0000

	// 支持下标 operator[] ：
	b3[2] = true; 
	b3[1] = true;

	// 其他操作：
	std::cout << "b3.count=" << b3.count() << std::endl;//为1的数目 2
	std::cout << "b3.size=" << b3.size() << std::endl;//位数 4
	std::cout << "b3.to_ullong=" << b3.to_ullong() << std::endl;//转成unsigned long long 6
	std::cout << "b3.to_string=" << b3.to_string() << std::endl;//转成string 0110

}
