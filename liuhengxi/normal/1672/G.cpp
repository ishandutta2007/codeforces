#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned int c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
constexpr int N=2005,MOD=998244353;
int n,m,ans,f[N<<1],c[N<<1],s[N<<1],v[N<<1],e[N<<1];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
char b[N][N];
int main()
{
	read(n,m);
	F(i,0,n)scanf("%s",b[i]);
	if((n&1)&&(m&1))
	{
		F(i,0,n+m)f[i]=i;
		F(i,0,n)F(j,0,m)if(b[i][j]=='?')f[find(i)]=f[find(j+n)];
		else c[i]^=b[i][j]&1,c[j+n]^=b[i][j]&1;
		F(i,0,n+m)++v[find(i)],s[f[i]]^=c[i];
		F(i,0,n)F(j,0,m)if(b[i][j]=='?')++e[find(i)];
		int prod=1;
		F(i,0,n+m)if(f[i]==i)
		{
			prod*=!s[i];
			F(_,0,e[i]-v[i]+1)(prod<<=1),(prod>=MOD)&&(prod-=MOD);
		}
		ans+=prod;
		F(i,0,n+m)s[i]=0,c[i]^=1;
		F(i,0,n+m)s[f[i]]^=c[i];
		prod=1;
		F(i,0,n+m)if(f[i]==i)
		{
			prod*=!s[i];
			F(_,0,e[i]-v[i]+1)(prod<<=1),(prod>=MOD)&&(prod-=MOD);
		}
		ans+=prod;(ans>=MOD)&&(ans-=MOD);
	}
	else if(n&1)
	{
		int prod=1;
		F(i,0,m)
		{
			int xs=0,uk=0;
			F(j,0,n)if(b[j][i]=='?')++uk;else xs^=b[j][i]&1;
			if(uk)F(j,1,uk)(prod<<=1),(prod>=MOD)&&(prod-=MOD);
			else prod*=!xs;
		}
		ans+=prod;
		prod=1;
		F(i,0,m)
		{
			int xs=0,uk=0;
			F(j,0,n)if(b[j][i]=='?')++uk;else xs^=b[j][i]&1;
			if(uk)F(j,1,uk)(prod<<=1),(prod>=MOD)&&(prod-=MOD);
			else prod*=xs;
		}
		ans+=prod;(ans>=MOD)&&(ans-=MOD);
	}
	else if(m&1)
	{
		int prod=1;
		F(i,0,n)
		{
			int xs=0,uk=0;
			F(j,0,m)if(b[i][j]=='?')++uk;else xs^=b[i][j]&1;
			if(uk)F(j,1,uk)(prod<<=1),(prod>=MOD)&&(prod-=MOD);
			else prod*=!xs;
		}
		ans+=prod;
		prod=1;
		F(i,0,n)
		{
			int xs=0,uk=0;
			F(j,0,m)if(b[i][j]=='?')++uk;else xs^=b[i][j]&1;
			if(uk)F(j,1,uk)(prod<<=1),(prod>=MOD)&&(prod-=MOD);
			else prod*=xs;
		}
		ans+=prod;(ans>=MOD)&&(ans-=MOD);
	}
	else
	{
		ans=1;
		F(i,0,n)F(j,0,m)if(b[i][j]=='?')(ans<<=1),(ans>=MOD)&&(ans-=MOD);
	}
	printf("%d\n",ans);
	return 0;
}