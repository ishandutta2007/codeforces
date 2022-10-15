// Lynkcat.
// Problem: D. 13th Labour of Heracles
// URL: https://codeforces.com/contest/1466/problem/D
// Memory Limit: 256 MB
// Time Limit: 2500 ms
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
#define N 100005
using namespace std;
int n,a[N],du[N];
void BellaKira()
{
	cin>>n;
	int sm=0;
	for (int i=1;i<=n;i++)
		cin>>a[i],sm+=a[i];
	priority_queue<int>q;
	for (int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		du[x]++,du[y]++;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<du[i];j++) q.push(a[i]);
		du[i]=0;
	}
	for (int i=1;i<n;i++)
	{
		cout<<sm<<" ";
		if (!q.empty())
		{
			sm+=q.top();
			q.pop();
		}
	}
	cout<<endl;
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