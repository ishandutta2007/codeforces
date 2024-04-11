// Author: Little09
// Problem: F. Bags with Balls
// Contest: Educational Codeforces Round 133 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1716/problem/F
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define mem(x) memset(x,0,sizeof(x))
#define printYes cout << "Yes" << endl
#define printYES cout << "YES" << endl
#define printNo cout << "No" << endl
#define printNO cout << "NO" << endl
#define lowbit(x) (x&(-x))

const ll inf=1000000000000000000; 
//const ll inf=1000000000;
const ll mod=998244353;
//const ll mod=1000000007;

const int N=2005;
int n,m,k; 
ll s[N][N];

ll ksm(ll x,ll y)
{
	ll res=1;
	while (y)
	{
		if (y&1) res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
ll jc[N+5],inv[N+5];
inline ll C(ll x,ll y)
{
	if (y>x) return 0;
	return jc[x]*inv[y]%mod*inv[x-y]%mod;
}
void init()
{
	jc[0]=1;
	for (int i=1;i<=N;i++) jc[i]=jc[i-1]*i%mod;
	inv[N]=ksm(jc[N],mod-2);
	for (int i=N-1;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
}
void work()
{
	cin >> n >> m >> k;
	ll ans=0;
	ll m0=m/2,m1=m-m0,tot=1,u=1;
	for (int i=1;i<=k;i++)
	{
		if (i>n) break;
		tot=tot*(n+1-i)%mod;
		u=u*m1%mod;
		ans=(ans+jc[i]*s[k][i]%mod*u%mod*tot%mod*inv[i]%mod*ksm(m,n-i)%mod)%mod;
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	for (int i=0;i<=2000;i++) s[i][0]=(i==0);
	for (int i=1;i<=2000;i++)
	{
		for (int j=1;j<=i;j++)
		{
			s[i][j]=(s[i-1][j-1]+1ll*j*s[i-1][j]%mod)%mod;
		}
	}
	int T;
	cin >> T;
	while (T--) work();
	return 0;
}