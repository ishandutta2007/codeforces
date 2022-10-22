#include<bits/stdc++.h>
#define int long long
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=200000+5,Mod=998244353;
int Fac[MaxN],Inv[MaxN];
char str[MaxN];
inline int QuickPow(const int val,const int lev)
{
	if(!lev) return 1;
	if(lev&1) return (QuickPow(val,lev^1)*val)%Mod;
	const int Half=QuickPow(val,lev>>1);
	return (Half*Half)%Mod;
}
signed main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int T,N=200000;
	cin>>T,Fac[0]=1;
	rep(i,1,N)
		Fac[i]=(Fac[i-1]*i)%Mod;
	Inv[N]=QuickPow(Fac[N],Mod-2);
	dow(i,N,1)
		Inv[i-1]=(Inv[i]*i)%Mod;
	int n;
	while(T--)
	{
		cin>>n>>(str+1);
		str[n+1]='0';
		int Sum=0,cnt=0,Last=0;
		rep(i,1,n)
		{
			if(str[i]=='0')
				Last=i;
			else
			{
				++Sum;
				if((str[i+1]=='0')&&((i^Last)&1))
					++cnt;
			}
		}
		const int Alpha=((Sum-cnt)>>1),Beta=(n-Sum);
		const int Record=(Fac[Alpha+Beta]*((Inv[Alpha]*Inv[Beta])%Mod))%Mod;
		cout<<Record<<endl;
	}
	return 0;
}