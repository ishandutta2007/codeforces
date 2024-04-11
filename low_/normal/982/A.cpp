#include<iostream>
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

main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n; string s;
	cin>>n>>s;
	
	if (n==1) 
	{
		if (s[0]=='1') cout<<"Yes";
		else cout<<"No";
		return 0;
	}
	
	for (int i=0; i<s.size()-1; i++) if (s[i]=='1' && s[i+1]=='1')
	{
		cout<<"No";
		return 0;
	}
	
	if (s[0]=='0' && s[1]=='0')
	{
		cout<<"No";
		return 0;
	}
	
	if (s.back()=='0' && s[s.size()-2]=='0')
	{
		cout<<"No";
		return 0;
	}
	
	for (int i=1; i<s.size()-1; i++) if (s[i]=='0' && s[i-1]=='0' && s[i-2]=='0')
	{
		cout<<"No";
		return 0;
	}
	
	cout<<"Yes";
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: