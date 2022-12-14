// Lynkcat.
// Problem: B. Jumbo Extra Cheese 2
// Contest: Codeforces - Codeforces Round #831 (Div. 1 + Div. 2)
// URL: https://codeforces.com/contest/1740/problem/B
// Memory Limit: 256 MB
// Time Limit: 1000 ms

#include<bits/stdc++.h>
#define poly vector<int>
#define IOS ios::sync_with_stdio(false)
#define ll long long
#define mp make_pair
#define mt make_tuple
#define pa pair < int,int >
#define fi first
#define se second
#define inf 1e9
#define mod 998244353
#define int ll
#define N 200005
using namespace std;
int n,a[N],b[N];
void BellaKira()
{
	cin>>n;
	int L=0;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		L=max(max(a[i],b[i]),L);
	}
	int ans=L;
	for (int i=1;i<=n;i++)
		if (a[i]<=L&&b[i]<=L) ans+=min(a[i],b[i]);
		else if (a[i]<=L) ans+=b[i];
		else ans+=a[i];
	// cout<<"?"<<ans<<" "<<L<<endl;
	cout<<ans*2<<'\n';
	
}
signed main()
{
	IOS;
	cin.tie(0);
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}