// Lynkcat.
// Problem: C. Helping the Nature
// Contest: Codeforces - Codeforces Round #802 (Div. 2)
// URL: https://codeforces.com/contest/1700/problem/C
// Memory Limit: 256 MB
// Time Limit: 2000 ms

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
#define N 2000005
using namespace std;
int a[N];
int n;
void BellaKira()
{
	int ans=0;
	cin>>n;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=n;i>=1;i--) a[i]-=a[i-1];
	for (int i=2;i<=n;i++)
		if (a[i]>0) ans+=a[i],a[i]=0;
		else a[1]+=a[i],ans-=a[i],a[i]=0;
	ans+=abs(a[1]);
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