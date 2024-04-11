#include <bits/stdc++.h>
#define ll long long 
const int mod=998244353;
using namespace std;
inline void chadd(int &x,int b) {x+=b-mod;x+=(x>>31) & mod;}
int n,a0,x,y,M,k,L;
int a[10000005];

inline int fastpow(ll basic,int x)
{
	ll res=1;
	while(x)
	{
		if(x&1) (res*=basic)%=mod;
		(basic*=basic)%=mod;
		x>>=1;
	}
	return res;
}

int dp[720720+5];
int cnt[720720+5];
int main()
{
	// freopen("input.txt","r",stdin);
	cin>>n>>a0>>x>>y>>k>>M;
	a[0]=a0;
	for(int i=1;i<n;i++)
	{
		a[i]=(1LL*a[i-1]*x+y)%M;
	}
	L=1;
	for(int i=1;i<=16;i++)
	{
		L=L/__gcd(L,i)*i;
	}
	int res=0;
	for(int i=0;i<n;i++)
	{
		chadd(res,a[i]-a[i]%L);
		a[i]%=L;
		cnt[a[i]]++;
	}
	res=1LL*res*fastpow(n,k-1)%mod*k%mod;
	for(int i=0;i<L;i++) dp[i]=cnt[i];
	for(int t=0;t<k;t++)
	{
		int coe=fastpow(n,k-1-t);
		int s=0,pre=0;
		for(int i=0;i<L;i++)
		{
			if(i-pre==t+1) pre=i;
			int w=dp[i];
			if(!w) continue;
			dp[i]=1LL*w*(n-1)%mod;
			chadd(dp[pre],w);
			s=(1LL*w*i+s)%mod;
		}
		res=(1LL*s*coe+res)%mod;
	}
	cout<<res<<endl;
	return 0;
}