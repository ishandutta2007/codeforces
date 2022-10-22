#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
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
int n,m,hd[N],cnt,deg[N],g[4005][4005],h[N],f[N],ans[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
int main()
{
	int k=0;
	read(n);read(m);
	F(i,0,n)hd[f[i]=i]=-1;
	F(i,0,m)
	{
		int u,v;read(u);read(v);
		++deg[--u];++deg[--v];
		if(n<4000)g[u][v]=g[v][u]=1;
		else adline(u,v),adline(v,u);
	}
	if(n>=4000)
	{
		int first=-1;
		F(u,0,n)if(deg[u]<3000)
		{
			if(~first)f[u]=first;
			else first=u;
		}
		F(u,0,n)if(deg[u]>=3000)
		{
			F(v,0,n)h[v]=0;
			for(int i=hd[u];~i;i=e[i].next)h[e[i].to]=1;
			F(v,0,n)if(!h[v])f[find(u)]=find(v);
		}
	}
	else F(u,0,n)F(v,0,u)if(!g[u][v])f[find(u)]=find(v);
	F(i,0,n)++ans[find(i)];
	sort(ans,ans+n,greater<int>());
	while(ans[k])++k;
	printf("%d\n",k);
	F(i,0,k)printf("%d ",ans[k-1-i]);
	printf("\n");
	return 0;
}