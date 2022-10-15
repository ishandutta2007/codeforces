// Lynkcat.
// Problem: G. White-Black Balanced Subtrees
// URL: https://codeforces.com/contest/1676/problem/G
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
int n,sum[N],fa[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++) sum[i]=0;
	for (int i=2;i<=n;i++)
	{
		cin>>fa[i];
	}
	string st;
	cin>>st;
	int ans=0;
	st=' '+st;
	for (int i=n;i>=1;i--)
	{
		if (st[i]=='B')
		sum[i]++;
		else sum[i]--;
		if (sum[i]==0) ans++;
		sum[fa[i]]+=sum[i];
	}
	cout<<ans<<endl;
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