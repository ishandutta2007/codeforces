// Lynkcat.
// Problem: F. Reverse
// URL: https://codeforces.com/contest/1618/problem/F
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// -----------------------------------------------

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e18
#define mod 998244353
#define int ll
//#define N
using namespace std;
ll x,y;
string s1,s2;
set<string>vis;
void dfs(string s)
{
	while(s.back()=='0')s.pop_back();
	if(s.size()>65||vis.count(s))return ;
	vis.insert(s);
	reverse(s.begin(),s.end());
	dfs(s);
	dfs(s+'1');
}
void BellaKira()
{
	cin>>x>>y;
	while(x) s1+=('0'+x%2),x/=2;
	while(y) s2+=('0'+y%2),y/=2;
	dfs(s1);
	if(vis.count(s2))printf("YES\n");
	else printf("NO\n");
	vis.clear();
		
}
signed main()
{
	int T=1;
	while (T--)
	{
		BellaKira();
	}
}