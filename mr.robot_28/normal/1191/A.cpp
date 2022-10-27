#include <iostream>
#include <cstdio>
#include<vector>
#include <cstring>
using namespace std;
int main()
{
	int x;
	cin >> x;
	int u = x % 4;
	if(u == 0)
	{
		cout << 1 << " " << "A";
	}
	else if(u == 1)
	{
		cout << 0 << " " << "A";
	}
	else if(u == 2)
	{
		cout << 1 << " " << "B";
	}
	else
	{
		cout << 2 << " " << "A";
	}
	return 0;
}