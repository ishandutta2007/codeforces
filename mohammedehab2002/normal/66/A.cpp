#include <iostream>
using namespace std;
int main()
{
	long double n;
	cin >> n;
	if (n<128)
	cout << "byte";
	else if (n<32768)
	cout << "short";
	else if (n<2147483648)
	cout << "int";
	else if (n<9223372036854775808)
	cout << "long\n";
	else
	cout << "BigInteger";
}