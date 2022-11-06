#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
	int x;
	cin >> x;
	cout << ((x % 9 == 0) ? 9 : x % 9);

	return 0;
}