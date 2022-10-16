#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
	int total;
	cin >> total;
	if (total == 1)
	{
		cout << "YES\n";
		return 0;
	}
	
	string s;
	cin >> s;
	char a = s[0];
	char b = s[1];
	if (a == b)
	{
		cout << "NO\n";
		return 0;}
	for (int i = 1; i < total - 1; i++)
	{
		if (s[i] != b)
		{
			cout << "NO\n";
			return 0;
		}
	}
	if (s[total - 1] != a)
	{
		cout << "NO\n";
		return 0;
	}
	for (int i = 1; i < total; i++)
	{
		cin >> s;
		for (int j = 0; j < total; j++)
		{
			if (j == i || j == total - i - 1)
			{
				if (s[j] != a)
				{
					cout << "NO\n";
					return 0;
				}
			}
			else
			{
				if (s[j] != b)
				{
					cout << "NO\n";
					return 0;
				}
			}
		}
	}
	cout << "YES\n";
	return 0;
}