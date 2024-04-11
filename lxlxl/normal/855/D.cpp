#include<set>
#include<map>
#include<deque>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<string>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<climits>
#include<complex>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

const int maxn = 210000;
const int maxd = 18;

int n,m;
struct edge
{
	int y,c,nex;
	edge(){}
	edge(const int _y,const int _c,const int _nex){y=_y;c=_c;nex=_nex;}
}a[maxn<<1]; int len,fir[maxn];
inline void ins(const int x,const int y,const int c){a[++len]=edge(y,c,fir[x]);fir[x]=len;}

int fa[maxn];
int find_(const int x){ return fa[x]==x?x:fa[x]=find_(fa[x]); }

int top[maxn],td[maxn],dep[maxn];
int f[maxn][maxd],tf[maxn][maxd];
void dfs(const int x)
{
	for(int i=1;i<maxd;i++) 
		f[x][i]=f[f[x][i-1]][i-1],
		tf[x][i]=tf[tf[x][i-1]][i-1];
	for(int k=fir[x];k;k=a[k].nex)
	{
		const int y=a[k].y;
		if(a[k].c==0) 
		{
			//for(int l=0;l<maxd;l++) f[y][l]=f[x][l];
			tf[y][0]=x;
			top[y]=top[x],td[y]=td[x]+1,dep[y]=dep[x],dfs(y);
		}
		else top[y]=y,td[y]=1,dep[y]=dep[x]+1,f[y][0]=x,dfs(y);
	}
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int type,x; scanf("%d%d",&x,&type);
		if(type==-1) fa[i]=i;
		else fa[i]=x,ins(x,i,type);
	}
	for(int i=1;i<=n;i++) find_(i);
	for(int i=1;i<=n;i++) if(fa[i]==i) dep[i]=1,top[i]=i,td[i]=1,dfs(i);
	
	scanf("%d",&m);
	while(m--)
	{
		int type,u,v; scanf("%d%d%d",&type,&u,&v);
		if(u==v||fa[u]!=fa[v]) puts("NO");
		else
		{
			if(type==1)
			{
				if(dep[v]==dep[u]&&top[v]==top[u]&&td[u]<td[v]) 
				{
					for(int i=maxd-1;i>=0;i--) if(td[v]-td[u]>=(1<<i)) v=tf[v][i];
					if(v==u) puts("YES");
					else puts("NO");
				}
				else puts("NO");
			}
			else
			{
				if(dep[v]<=dep[u]) puts("NO");
				else
				{
					for(int i=maxd-1;i>=0;i--) if(dep[v]-dep[u]>=(1<<i)) v=f[v][i];
					if(top[v]==top[u]) 
					{
						for(int i=maxd-1;i>=0;i--) if(td[u]-td[v]>=(1<<i)) u=tf[u][i];
						if(u==v) puts("YES");
						else puts("NO");
					}
					else puts("NO");
				}
			}
		}
	}
	
    return 0;
}