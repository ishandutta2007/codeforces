#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=6005;
const short SINF=0x3fff;
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
int n,r[N],v[N],ans,hd[N],cnt,fa1[N];
short a[N],f[N][N],g[N][N],ff[N],gg[N];
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int fa)
{
	f[u][0]=a[u];
	g[u][0]=a[u];
	fa1[u]=fa;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs(v,u);
		F(j,0,n)
		{
			if(f[v][j]!=SINF)
			{
				f[u][j]=f[u][j]<f[v][j]?f[u][j]:f[v][j];
				if(j<n-1&&f[v][j]<a[u])
					f[u][j+1]=f[u][j+1]<a[u]?f[u][j+1]:a[u];
			}
			if(g[v][j])
			{
				g[u][j]=g[u][j]>g[v][j]?g[u][j]:g[v][j];
				if(j<n-1&&g[v][j]>a[u])
					g[u][j+1]=g[u][j+1]>a[u]?g[u][j+1]:a[u];
			}
		}
	}
}
int main()
{
	read(n);
	F(i,0,n)read(r[i]),v[i]=r[i];
	sort(v,v+n);
	F(i,0,n)F(j,0,n)if(r[j]==v[i])a[j]=i+1;
	F(i,0,n)hd[i]=-1;
	F(i,0,n-1)
	{
		int u,v;read(u);read(v);
		adline(--u,--v);adline(v,u);
	}
	F(i,0,n)F(j,0,n)f[i][j]=SINF;
	dfs(0,0);
	F(i,0,n)F(j,0,n)if(f[i][j]!=SINF||g[i][j])ans=ans>j?ans:j;
	F(u,0,n)
	{
		F(j,0,n)ff[j]=SINF,gg[j]=0;
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;if(v==fa1[u])continue;
			F(j,0,n)if(f[v][j]!=SINF)
				while(ans<n&&f[v][j]<gg[ans-j])++ans;
			F(j,0,n)if(g[v][j])
				while(ans<n&&g[v][j]>ff[ans-j])++ans;
			F(j,0,n)
			{
				if(f[v][j]!=SINF)
				{
					ff[j]=ff[j]<f[v][j]?ff[j]:f[v][j];
					if(j<n-1&&f[v][j]<a[u])
						ff[j+1]=ff[j+1]<a[u]?ff[j+1]:a[u];
				}
				if(g[v][j])
				{
					gg[j]=gg[j]>g[v][j]?gg[j]:g[v][j];
					if(j<n-1&&g[v][j]>a[u])
						gg[j+1]=gg[j+1]>a[u]?gg[j+1]:a[u];
				}
			}
		}
	}
	printf("%d\n",++ans);
	return 0;
}