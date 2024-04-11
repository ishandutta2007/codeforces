// Lynkcat.
// Problem: B. Shoe Shuffling
// URL: https://codeforces.com/contest/1691/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms
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
//#define int ll
#define N 100005
using namespace std;
int n;
int p[N];
void BellaKira()
{
	map<int,poly>Mp;
	cin>>n;
	for (int i=1;i<=n;i++)
	{
		int y;
		cin>>y;
		Mp[y].push_back(i);
	}
	int ans=1;
	for (auto u:Mp)
	{
		if (u.se.size()==1) ans=0;
		for (int j=0;j<u.se.size();j++)
		{
			p[u.se[j]]=u.se[(j+1)%u.se.size()];
		}
	}
	if (ans)
	{
		for (int i=1;i<=n;i++) cout<<p[i]<<" ";
		cout<<endl;
	} else cout<<-1<<endl;
		
}
signed main()
{
	IOS;
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}