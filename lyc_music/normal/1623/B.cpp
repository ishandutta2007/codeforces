// Lynkcat.
// Problem: B. Game on Ranges
// URL: https://codeforces.com/contest/1623/problem/B
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
#define N 1005
using namespace std;
int n,s[N],l[N],r[N];
void BellaKira()
{
	cin>>n;
	for (int i=1;i<=n;i++) s[i]=0;
	for (int i=1;i<=n;i++)
		cin>>l[i]>>r[i],s[l[i]]++,s[r[i]+1]--;
	for (int i=1;i<=n;i++)
		s[i]+=s[i-1];
	for (int i=1;i<=n;i++)
	{
		int now=l[i];
		for (int j=l[i];j<=r[i];j++)
			if (s[j]<s[now]) now=j;
		cout<<l[i]<<" "<<r[i]<<" "<<now<<endl;
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