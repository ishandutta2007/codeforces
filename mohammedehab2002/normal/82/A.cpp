#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	string s[]={"Sheldon","Leonard","Penny","Rajesh","Howard"};
	int n;
	cin >> n;
	while (n>5)
	{
		n/=2;
		n-=2;
	}
	cout << s[n-1];
}