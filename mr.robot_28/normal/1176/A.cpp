#include<iostream>
#include <bits/stdc++.h> 
#include<vector>
#include<set>
using namespace std;
int main()
{
	#define int long long
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
	{
		int a;
		cin >> a;
		int b = a;
		while(true)
		{
			if(b % 2 == 0)
			{
				b = b /2;
			}
			if(b % 3 == 0)
			{
				b = b / 3;
			}
			if(b % 5 == 0)
			{
				b = b / 5;
			}
			if(b % 2 != 0 && b % 3 != 0 && b % 5 != 0)
			{
				break;
			}
		}
		if(b != 1)
		{
			cout << -1 << endl;
		}
		else
		{
			int cnt = 0;
			while(a > 1)
			{
				if(a % 5 == 0)
				{
					cnt++;
					a = a * 4 / 5;
				}
				if(a % 3 == 0)
				{
					cnt++;
					a = a * 2 / 3;
				}
				if(a % 2 == 0)
				{
					a = a / 2;
					cnt++;
				}
			}
			cout << cnt << endl;
		}
	}
	return 0;
}