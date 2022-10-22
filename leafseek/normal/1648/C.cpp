#include<bits/stdc++.h>
#define int long long
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=200000+5,Limit=(1<<18),Mod=998244353;
int Coe[MaxN],Inv[MaxN],CoeInv[MaxN];
struct Tree_Array
{
	int c[Limit|5];
	inline void Update(const int pos,const int wei)
	{
		for(int i=pos;i<=Limit;i+=(i&(-i))) c[i]+=wei;
	}
	inline int Query(const int pos)
	{
		int C=0;
		for(int i=pos;i;i^=(i&(-i))) C+=c[i];
		return C;
	}
};
Tree_Array Tr;
int a[MaxN],b[MaxN],cnt[MaxN];
signed main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n_0,n_1;
	const int m=200001;
	cin>>n_0>>n_1;
	rep(i,1,n_0) cin>>a[i],++cnt[a[i]];
	rep(i,1,n_1) cin>>b[i];
	Coe[0]=1; rep(i,1,m) Coe[i]=(Coe[i-1]*i)%Mod;
	Inv[1]=1; rep(i,2,m) Inv[i]=((Mod-(Mod/i))*Inv[Mod%i])%Mod;
	CoeInv[0]=1; rep(i,1,m) CoeInv[i]=(CoeInv[i-1]*Inv[i])%Mod;
	int S=1; rep(i,1,m) S=(S*CoeInv[cnt[i]])%Mod;
	rep(i,1,m) Tr.Update(i,cnt[i]);
	int Answer=0;
	bool Flag=true;
	rep(i,1,min(n_0,n_1))
	{
		const int Mult=(Coe[n_0-i]*S)%Mod;
		Answer=(Answer+(Mult*Tr.Query(b[i]-1)))%Mod;
		S=(S*cnt[b[i]])%Mod;
		if((--cnt[b[i]])<0){Flag=false;break;}
		Tr.Update(b[i],-1);
	}
	if(Flag&&(n_0<n_1)) Answer=(Answer+1)%Mod;
	cout<<Answer<<'\n';
	return 0;
}