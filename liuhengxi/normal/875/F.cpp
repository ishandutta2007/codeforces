#include<cstdio>
#include<algorithm>
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
struct edge
{
	int u,v,w;
}e[N];
bool operator<(edge a,edge b){return a.w>b.w;}
int n,m,f[N],ans;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
int main()
{
	read(n,m);++n;
	F(i,0,n)f[i]=i;
	F(i,0,m)read(e[i].u,e[i].v,e[i].w);
	sort(e,e+m);
	F(i,0,m)
	{
		int u=find(e[i].u),v=find(e[i].v),z=find(0);
		if(u!=v)f[u]=v,ans+=e[i].w;
		else if(u!=z)f[u]=z,ans+=e[i].w;
	}
	printf("%d\n",ans);
	return 0;
}