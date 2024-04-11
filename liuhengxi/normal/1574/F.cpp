#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=3e5+5,MOD=998244353;
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
int n,m,k,nex[N],pre[N],fa[N],siz[N],f[N],d[N],s,t[N],tt;
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int main()
{
	read(n,m,k);while(s*s<=m)++s;
	F(i,0,k)nex[i]=pre[i]=-1,fa[i]=i;
	F(i,0,n)
	{
		int c,u,v=-1;
		read(c);
		F(j,0,c)
		{
			--read(u);
			if(~v)
			{
				nex[u]=~nex[u]&&nex[u]!=v?-2:v;
				pre[v]=~pre[v]&&pre[v]!=u?-2:u;
				fa[find(u)]=find(v);
			}
			v=u;
		}
	}
	F(i,0,k)++siz[find(i)];
	F(i,0,k)if(nex[i]==-2||pre[i]==-2)siz[find(i)]=0;
	F(i,0,k)if(siz[i]&&~nex[i])
	{
		int j=nex[i];
		while(~nex[j]&&j!=i)j=nex[j];
		if(j==i)siz[i]=0;
	}
	f[0]=1;
	F(i,0,k)if(siz[i])
	{
		if(siz[i]<s)++d[siz[i]];
		else t[tt++]=siz[i];
	}
	F(i,1,m+1)
	{
		F(j,1,s)if(j<=i)f[i]=(int)((f[i]+(long long)d[j]*f[i-j])%MOD);
		F(j,0,tt)if(t[j]<=i)f[i]+=f[i-t[j]],(f[i]>=MOD)&&(f[i]-=MOD);
	}
	printf("%d\n",f[m]);
	return 0;
}