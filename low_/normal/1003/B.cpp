#include<iostream>
#include<fstream>
#include<vector>
#include<queue>
#include<deque>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<cstdio>
using namespace std;
#define int long long
#define inf 9223372036854775799
#define mn 100005
#define FLN "test"

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int a, b, x;
	cin>>a>>b>>x;
	
	string ans="";
	if (a>b)
	{
		ans="0";
		a--;
		while (x>1)
		{
			ans.push_back('0'+(ans.back()=='0'));
			if (ans.back()=='1') b--;
			else a--;
			x--;
		}
		
		if (ans.back()=='1')
		{
			while (b--) ans.push_back('1');
			while (a--) ans.push_back('0');
		}
		else
		{
			while (a--) ans.push_back('0');
			while (b--) ans.push_back('1');
		}
	}
	else
	{
		ans="1";
		b--;
		while (x>1)
		{
			ans.push_back('0'+(ans.back()=='0'));
			if (ans.back()=='1') b--;
			else a--;
			x--;
		}
		
		if (ans.back()=='1')
		{
			while (b--) ans.push_back('1');
			while (a--) ans.push_back('0');
		}
		else
		{
			while (a--) ans.push_back('0');
			while (b--) ans.push_back('1');
		}
	}
	
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: