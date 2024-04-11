#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
#define quit(str) return puts(str),0;
using namespace std;
const int N=2505;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct edge
{
	int u,v,w;
	bool operator<(edge b)const{return w<b.w;}
}ee[N*N/2];
struct line
{
	int next,to,dis;
}e[2*N];
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,a[N][N],cnt,f[N],hd[N],b[N][N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void adline(int u,int v,int w)
{
	e[cnt].to=v;
	e[cnt].dis=w;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void dfs(int u,int fa,int source,int now)
{
	b[source][u]=now;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs(v,u,source,max(now,e[i].dis));
	}
}
int main()
{
	F(i,0,read(n))F(j,0,n)read(a[i][j]);
	F(i,0,n)if(a[i][i]!=0)quit("NOT MAGIC");
	F(i,0,n)F(j,0,i)if(a[i][j]!=a[j][i])quit("NOT MAGIC");
	F(i,0,n)F(j,0,i)ee[cnt].u=i,ee[cnt].v=j,ee[cnt++].w=a[i][j];
	sort(ee,ee+cnt);
	F(i,cnt=0,n)hd[f[i]=i]=-1;
	F(i,0,n*(n-1)/2)if(find(ee[i].u)!=find(ee[i].v))
	{
		f[find(ee[i].u)]=find(ee[i].v);
		adline(ee[i].u,ee[i].v,ee[i].w);
		adline(ee[i].v,ee[i].u,ee[i].w);
	}
	F(i,0,n)dfs(i,i,i,0);
	F(i,0,n)F(j,0,n)if(a[i][j]!=b[i][j])quit("NOT MAGIC");
	quit("MAGIC");
}