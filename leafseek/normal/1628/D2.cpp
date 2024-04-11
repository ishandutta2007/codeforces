#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=3000000+5,Mod=1000000007;
inline int QuickPow(const int wei,const int lvl)
{
	if(!lvl) return 1;
	if(lvl&1) return ((long long)QuickPow(wei,lvl^1)*wei)%Mod;
	const int Half=QuickPow(wei,lvl>>1);
	return ((long long)Half*Half)%Mod;
}
int Coe[MaxN],CoeInv[MaxN];
inline void Initalize(const int n)
{
	Coe[0]=1;
	rep(i,1,n)
		Coe[i]=((long long)Coe[i-1]*i)%Mod;
	CoeInv[n]=QuickPow(Coe[n],Mod-2);
	dow(i,n,1)
		CoeInv[i-1]=((long long)CoeInv[i]*i)%Mod;
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	Initalize(3000000);
	int T;
	cin>>T;
	while(T--)
	{
		int n,m,k;
		cin>>n>>m>>k;
		int Answer=0;
		rep(i,0,m)
			if(n>=(m-i))
			Answer=(Answer+(((((long long)(i<<1)*k)%Mod*Coe[n])%Mod*CoeInv[n-(m-i)])%Mod*CoeInv[m-i]))%Mod;
		Answer=((long long)Answer*QuickPow(2,Mod-1-n))%Mod;
		cout<<Answer<<'\n';
	}
	return 0;
}