#include <iostream>
#include <cstdio>
#include<vector>
#include <cstring>
using namespace std;
int main()
{
	string a, b, c;
	cin >> a >> b >> c;
	if(a == b && b == c)
	{
		cout << 0;
		return 0;
	}
	if(a[0] > b[0])
	{
		swap(a, b);
	}
	if(a[0] > c[0])
	{
		swap(a, c);
	}
	if(b[0] > c[0])
	{
		swap(b, c);
	}
	if(a[1] == b[1] && b[1] == c[1] && a[0] +1 == b[0] && b[0] +1 == c[0])
	{
		cout << 0;
		return 0;
	}
	if(a == b || b == c || a == c)
	{
		cout << 1;
		return 0;
	}
	if((a[0] + 1 == b[0] || a[0] + 2 == b[0])&& a[1] == b[1] || (a[0] + 1 == c[0] | a[0] + 2 == c[0]) && a[1] == c[1] || (b[0] + 1== c[0] || b[0] + 2 == c[0]) &&  b[1] == c[1])
	{
		cout << 1;
		return 0;
	}
	cout << 2;
	return 0;
}