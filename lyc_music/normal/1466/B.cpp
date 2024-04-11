// Lynkcat.
// Problem: B. Last minute enhancements
// URL: https://codeforces.com/contest/1466/problem/B
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
#define int ll
#define N 200005
using namespace std;
int n,a[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	a[n+1]=inf;
	for (int i=1;i<=n;i++)
		if (a[i]==a[i-1]&&a[i+1]!=a[i])
		{
			a[i]++;
		}
	map<int,int>Mp;
	for (int i=1;i<=n;i++)
		Mp[a[i]]++;
	cout<<Mp.size()<<endl;
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