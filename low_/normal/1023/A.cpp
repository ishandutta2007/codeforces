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

deque <char> s1, s2;
int n, m;

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	char c;
	for (int i=0; i<n; i++)
	{
		cin>>c;
		s1.push_back(c);
	}
	for (int i=0; i<m; i++)
	{
		cin>>c;
		s2.push_back(c);
	}
	
	for (int i=0; i<s1.size(); i++) 
	{
		if (s1[i]=='*') break;
		if (i==s1.size()-1)
		{
			if (s1==s2) cout<<"YES";
			else cout<<"NO";
			return 0;
		}
	}
	
	while (s1.front()!='*')
	{
		if (s2.empty())
		{
			cout<<"NO";
			return 0;
		}
		if (s2.front()!=s1.front())
		{
			cout<<"NO";
			return 0;
		}
		s1.pop_front(), s2.pop_front();
	}
	
	while (s1.back()!='*')
	{
		if (s2.empty())
		{
			cout<<"NO";
			return 0;
		}
		if (s2.back()!=s1.back())
		{
			cout<<"NO";
			return 0;
		}
		s1.pop_back(), s2.pop_back();
	}
	
	cout<<"YES";
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: