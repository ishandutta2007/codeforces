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
	cout.tie(0);
	
	string s;
	cin>>s;
	int cnt=1, ans=1;
	
	for (int i=1; i<s.size(); i++) 
	{
		if (s[i]==s[i-1]) cnt=1;
		else 
		{
			cnt++;
			ans=max(ans, cnt);
		}
	}
	
	if (s[0]!=s[s.size()-1])
	{
		int t1=1, t2=1;
		for (int i=1; i<s.size(); i++) 
		{
			if (s[i]==s[i-1]) break;
			t1++;
		}
		for (int i=s.size()-2; i>=0; i--)
		{
			if (s[i]==s[i+1]) break;
			t2++;
		}
		
		ans=max(ans, min((int)s.size(), t1+t2));
	}
	
	cout<<ans;
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: