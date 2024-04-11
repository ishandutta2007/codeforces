#include<bits/stdc++.h>
#define rep(a,b,c) for(register int a=(b);a<=(c);++a)
#define dow(a,b,c) for(register int a=(b);a>=(c);--a)
using namespace std;
constexpr int MaxN=2000+5,MaxM=2000+5,Mod=998244353;
inline void SimpleMod(int &wei)
	{(wei>=Mod)&&(wei-=Mod);}
struct Disjoint_ConnectionSet
{
	int Fa[MaxN+MaxM],siz[MaxN+MaxM];
	inline void Initalize(const int n,const int m)
		{rep(i,1,n+m) Fa[i]=i,siz[i]=1;}
	inline int getf(const int u)
	{
		if(u!=Fa[u]) Fa[u]=getf(Fa[u]);
		return Fa[u];
	}
	inline bool Merge(const int u,const int v)
	{
		int Fu=getf(u),Fv=getf(v);
		if(Fu==Fv) return false;
		if(siz[Fu]<siz[Fv]) swap(Fu,Fv);
		return ((Fa[Fv]=Fu,siz[Fu]+=siz[Fv]),true);
	}
};
Disjoint_ConnectionSet Con;
int Pow_2[MaxN*MaxM];
char arr[MaxN][MaxM];
bool A[MaxN],B[MaxM],Eps_A[MaxN],Eps_B[MaxM],Cum_1[MaxN+MaxM],Cum_H[MaxN+MaxM];
int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr);
	int n,m;
	cin>>n>>m,Pow_2[0]=1;
	rep(i,1,n*m) SimpleMod(Pow_2[i]=(Pow_2[i-1]<<1));
	rep(i,1,n) cin>>(arr[i]+1);
	const char cmd=((((n&1)<<1)|(m&1))+'0');
	int F_Cnt=0;
	if(cmd=='0')
		{rep(i,1,n) rep(j,1,m) if(arr[i][j]=='?') ++F_Cnt;}
	else if(cmd=='1')
	{
		F_Cnt-=(n-1);
		rep(i,1,n) rep(j,1,m)
		{
			if(arr[i][j]=='?') ++F_Cnt,Eps_A[i]=true,Eps_B[j]=true;
			else if(arr[i][j]=='1') A[i]^=true,B[j]^=true;
		}
		int u=0;
		rep(i,1,n)
		{
			if(Eps_A[i]) continue;
			if(!u) {u=i;continue;}
			if((++F_Cnt),(A[i]!=A[u])) {F_Cnt=INT_MIN;break;}
		}
	}
	else if(cmd=='2')
	{
		F_Cnt-=(m-1);
		rep(i,1,n) rep(j,1,m)
		{
			if(arr[i][j]=='?') ++F_Cnt,Eps_A[i]=true,Eps_B[j]=true;
			else if(arr[i][j]=='1') A[i]^=true,B[j]^=true;
		}
		int u=0;
		rep(i,1,m)
		{
			if(Eps_B[i]) continue;
			if(!u) {u=i;continue;}
			if((++F_Cnt),(B[i]!=B[u])) {F_Cnt=INT_MIN;break;}
		}
	}
	else //if(cmd=='3')
	{
		F_Cnt-=(n-1),F_Cnt-=(m-1);
		rep(i,1,n) rep(j,1,m)
		{
			if(arr[i][j]=='?') ++F_Cnt,Eps_A[i]=true,Eps_B[j]=true;
			else if(arr[i][j]=='1') A[i]^=true,B[j]^=true;
		}
		int u=0;
		rep(i,1,n-1)
		{
			if(Eps_A[i]) continue;
			if(!u) {u=i;continue;}
			if((++F_Cnt),(A[i]!=A[u])) {F_Cnt=INT_MIN;goto Dooms_Day;}
		}
		Con.Initalize(n,m);
		rep(i,1,n) rep(j,1,m)
			if(arr[i][j]=='?') Con.Merge(i,n+j);
		dow(p,m,1)
		{
			if(p!=m) Con.Merge(n,n+(p+1));
			const int S=Con.getf(n),T=Con.getf(n+p);
			if((arr[n][p]=='?')||S==T) continue;
			rep(i,1,n+m) Cum_1[i]=false,Cum_H[i]=false;
			rep(i,1,n) u=Con.getf(i),Cum_1[u]^=true,Cum_H[u]^=A[i];
			rep(i,1,m) u=Con.getf(n+i),Cum_1[u]^=true,Cum_H[u]^=B[i];
			bool Record[2][2]={};
			Record[Cum_1[S]][Cum_H[S]]=true;
			Record[Cum_1[T]][Cum_H[T]]=true;
			rep(i,1,n+m)
			{
				if(i==S||i==T||(Con.getf(i)!=i)) continue;
				rep(I,0,1) rep(J,0,1)
					if(Record[I][J]) Record[I^Cum_1[i]][J^Cum_H[i]]=true;
			}
			if(Record[0][1]) {F_Cnt=INT_MIN;goto Dooms_Day;}
			if(Record[0][0]) ++F_Cnt;
		}
	}
	Dooms_Day:cout<<((F_Cnt==INT_MIN)?0:Pow_2[F_Cnt])<<'\n';
	return 0;
}