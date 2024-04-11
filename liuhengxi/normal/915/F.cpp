#include<cstdio>
#include<algorithm>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=1e6+5;
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
int n,a[N],id[N],hd[N],cnt,f[N],siz[N];
long long ans[2];
bool vis[N];
bool cmpid1(int u,int v){return a[u]>a[v];}
bool cmpid2(int u,int v){return a[u]<a[v];}
bool (*cmpid[2])(int,int)={cmpid1,cmpid2};
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void solve(int k)
{
	sort(id,id+n,cmpid[k]);
	F(i,0,n)siz[f[i]=i]=1,vis[i]=false;
	F(i,0,n)
	{
		int u=id[i];
		vis[u]=true;
		for(int i=hd[u];~i;i=e[i].next)
		{
			int v=e[i].to;if(find(v)==find(u)||!vis[v])continue;
			ans[k]+=(long long)a[u]*siz[find(u)]*siz[find(v)];
			siz[find(v)]+=siz[find(u)];
			f[find(u)]=find(v);
		}
	}
}
int main()
{
	read(n);
	F(i,0,n)read(a[i]),hd[id[i]=i]=-1;
	F(i,0,n-1)
	{
		int u,v;read(u);read(v);
		adline(--u,--v);adline(v,u);
	}
	solve(0);solve(1);
	printf("%lld\n",ans[1]-ans[0]);
	return 0;
}