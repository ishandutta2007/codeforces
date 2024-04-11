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
#define inf 2000000005
#define mn 100005
#define FLN "test"

map <string, pair <int, string> > MAP;
int n, q;
string s;

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	set<string> ss;
	for (int i=1; i<=n; i++)
	{
		cin>>s;
		ss.clear();
		for (int i=0; i<s.size(); i++) for (int j=i; j<s.size(); j++) ss.insert(s.substr(i, j-i+1));
		
		for (string S: ss)	
		{
			if (MAP.count(S)==0) MAP[S]={1, s};
			else MAP[S].first++;
		}
		
	}
	
	cin>>q;
	while (q--)
	{
		cin>>s;
		if (MAP.count(s)==1) cout<<MAP[s].first<<' '<<MAP[s].second<<'\n';
		else cout<<"0 - \n";
	}
}

// PLEASE REMOVE COUT DEBUG, FILE-OPENING FUNCTIONS BEFORE SUBMITTING
// Code by low_ 
// Link: https://codeforces.com/profile/low_