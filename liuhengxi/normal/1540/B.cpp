#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=205,MOD=1000000007,INV2=500000004;
template<typename T>void read(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct line
{
	int next,to;
}e[2*N];
int n,hd[N],cnt,ans,dep[N],dfn[N],siz[N],ind,seq[N],f[N][N];
inline void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
inline int pow(int aa,int b)
{
	long long a=aa,c=1;
	while(b)
	{
		if(b&1)(c*=a)%=MOD;
		b>>=1;(a*=a)%=MOD;
	}
	return (int)c;
}
inline int inv(int x){return pow(x,MOD-2);}
int dfs(int u,int fa)
{
	int ans=0,du;
	siz[u]=1;
	du=dep[dfn[u]];
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		seq[ind]=v;
		dep[dfn[v]=ind++]=du+1;
		ans+=dfs(v,u);if(ans>=MOD)ans-=MOD;
		F(i,dfn[u],dfn[u]+siz[u])F(j,dfn[v],dfn[v]+siz[v])
		{
			if(seq[i]>seq[j])ans+=f[dep[i]-du][dep[j]-du];
			else ans+=f[dep[j]-du][dep[i]-du];
			if(ans>=MOD)ans-=MOD;
		}
		siz[u]+=siz[v];
	}
	return ans;
}
int calc(int rt)
{
	seq[dep[dfn[rt]=(ind=0)++]=0]=rt;
	return dfs(rt,rt);
}
int main()
{
	read(n);
	F(i,0,n)hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v;read(u);read(v);
		adline(--u,--v);adline(v,u);
	}
	F(i,0,n)f[i][0]=0;
	F(j,0,n)f[0][j]=1;
	F(i,1,n)F(j,1,n)f[i][j]=(f[i-1][j]+f[i][j-1])*(long long)INV2%MOD;
	F(i,0,n)(ans+=calc(i))%=MOD;
	ans=ans*(long long)inv(n)%MOD;
	printf("%d\n",ans);
	return 0;
}