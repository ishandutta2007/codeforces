// Lynkcat.
// Problem: C. Card Game
// Contest: Codeforces - Educational Codeforces Round 136 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1739/problem/C
// Memory Limit: 512 MB
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
#define N 105
using namespace std;
int f[N];
int fac[N],inv[N];
int n;
int quickPower(int x,int y)
{
	int res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
inline int C(int x,int y)
{
	if (x<y||y<0) return 0;
	return fac[x]*inv[y]%mod*inv[x-y]%mod;
}
void BellaKira()
{
	cin>>n;
	f[0]=0;
	for (int i=2;i<=n;i+=2)
		f[i]=((C(i-2,i/2-1)-f[i-2]+mod-1+mod)%mod+C(i-1,i/2))%mod;
		// cout<<"?"<<C(1,1)<<" "<<f[n]<<endl;
	cout<<f[n]<<" "<<(C(n,n/2)-f[n]+mod-1+mod)%mod<<" "<<1<<endl;
}
signed main()
{
	fac[0]=1;for (int i=1;i<N;i++) fac[i]=fac[i-1]*i%mod;
	inv[N-1]=quickPower(fac[N-1],mod-2);
	for (int i=N-1;i>=1;i--) inv[i-1]=inv[i]*i%mod;
	IOS;cin.tie(0); 
	int T=1;
	cin>>T;
	while (T--)
	{
		BellaKira();
	}
}