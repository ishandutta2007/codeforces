#include <iostream>
#include<vector>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include<algorithm>
using namespace std;
const int  CONST = 998244353;
#define int long long
signed main()
{
	string s = "";
	for(int i = 0; i < 300; i++)
	{
		s += 'a';
	}
	cout << s << endl;
	fflush(stdout);
	int a;
	cin >> a;
	string s1 = "";
	for(int i = 0; i < 300; i++)
	{
		s1 += 'b';
	}
	cout << s1 << endl;
	fflush(stdout);
	int a1;
	cin >> a1;
	int len = 600 - a - a1;
	int cnt = 0, cnt1 = 0;
	a -= 300 - len;
	a1 -= 300 - len;
	int b1 = a;
	for(int i = 0; i < len; i++)
	{
		if(b1 == 0)
		{
			break;
		}
		for(int j = 0; j < len; j++)
		{
			if(i == j)
			{
				cout << "b";
			}
			else
			{
				cout << s[j];
			}
		}
		cout << endl;
		fflush(stdout);
		int b;
		cin >> b;
		if(b < b1)
		{
			s[i] = 'b';
			cnt++;
		}
		else
		{
			cnt1++;
		}
		b1 = min(b, b1);
	}
	for(int j = 0; j < len; j++)
	{
		cout << s[j];
	}
	fflush(stdout);
	cout << endl;
	cin >> a;
	return 0;
}