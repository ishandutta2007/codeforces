#include<cstdio>
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
int n,k,l[N],r[N],a[N],aa,fa[N];
char c[N];
bool b[N],d[N];
void flatten(int u)
{
	if(~l[u])flatten(l[u]);
	a[aa++]=u;
	if(~r[u])flatten(r[u]);
}
void dfs(int u,int need)
{
	if(~l[u])dfs(l[u],need+1);
	if(b[u])
	{
		if(!d[u]&&need<=k)
		{
			for(int v=u;~v&&!d[v];v=fa[v])d[v]=true;
			k-=need;
		}
	}
	if(d[u])need=0;
	if((b[u]||d[u])&&~r[u])dfs(r[u],need+1);
}
int main()
{
	read(n,k);
	scanf("%s",c);
	F(i,0,n)--read(l[i]),--read(r[i]);
	fa[0]=-1;
	F(i,0,n)
	{
		if(~l[i])fa[l[i]]=i;
		if(~r[i])fa[r[i]]=i;
	}
	flatten(0);
	for(int i=n,last=0;~--i;)
	{
		if(i+1<n&&c[a[i]]!=c[a[i+1]])last=c[a[i+1]];
		b[a[i]]=c[a[i]]<last;
	}
	dfs(0,1);
	F(i,0,n)putchar(c[a[i]]),d[a[i]]&&putchar(c[a[i]]);
	puts("");
	return 0;
}