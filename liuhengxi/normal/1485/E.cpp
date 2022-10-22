#include<cstdio>
#include<vector>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
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
int tt,n,fa[N],a[N],dep[N],d,mn[N],mx[N],mnw[N],mxw[N];
long long f[N];
vector<int> ch[N],node[N];
void dfs(int u)
{
	d=max(d,dep[u]);
	for(int v:ch[u])
	{
		dep[v]=dep[u]+1;
		dfs(v);
	}
}
int main()
{
	for(read(tt);tt;tt--)
	{
		read(n);
		F(i,1,n)ch[--read(fa[i])].push_back(i);
		F(i,1,n)read(a[i]);
		F(i,0,n)f[i]=0;
		dfs(0);
		F(i,0,n)node[dep[i]].push_back(i);
		F(i,0,d+1)mn[i]=mx[i]=mnw[i]=mxw[i]=node[i][0];
		F(i,0,n)if(a[i]<a[mn[dep[i]]])mn[dep[i]]=i;
		F(i,0,n)if(a[i]>a[mx[dep[i]]])mx[dep[i]]=i;
		for(int u:node[d])
		{
			if(-a[u]>-a[mnw[d]])mnw[d]=u;
			if(+a[u]>+a[mxw[d]])mxw[d]=u;
		}
		for(int i=d;~--i;)
		{
			for(int u:node[i])
			{
				for(int v:ch[u])
				{
					f[u]=max(f[u],f[v]+a[v]-a[mn[i+1]]);
					f[u]=max(f[u],f[v]-a[v]+a[mx[i+1]]);
					f[u]=max(f[u],f[mnw[i+1]]+a[v]-a[mnw[i+1]]);
					f[u]=max(f[u],f[mxw[i+1]]-a[v]+a[mxw[i+1]]);
				}
				if(f[u]-a[u]>f[mnw[i]]-a[mnw[i]])mnw[i]=u;
				if(f[u]+a[u]>f[mxw[i]]+a[mxw[i]])mxw[i]=u;
			}
		}
		printf("%lld\n",f[0]);
		F(i,0,d+1)node[i].clear();
		F(i,0,n)ch[i].clear();
	}
	return 0;
}