#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=2e5+5;
template<typename T>void readmain(T &x)
{
	bool neg=false;
	unsigned char c=getchar();
	for(;(c^48)>9;c=getchar())if(c=='-')neg=true;
	for(x=0;(c^48)<10;c=getchar())x=(x<<3)+(x<<1)+(c^48);
	if(neg)x=-x;
}
struct line
{
	int next,to,id,sign;
}e[2*N];
template<typename T>T& read(T &x){readmain(x);return x;}
template<typename T,typename ...Tr>void read(T &x,Tr&... r){readmain(x);read(r...);}
int n,m,s[N],hd[N],cnt,x[N],y[N],f[N],ans[N];
bool fail;
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
inline void adline(int u,int v,int id,int sign)
{e[cnt].to=v;e[cnt].id=id;e[cnt].sign=sign;e[cnt].next=hd[u];hd[u]=cnt++;}
void dfs(int u,int fa)
{
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;if(v==fa)continue;
		dfs(v,u);
		ans[e[i].id]=e[i].sign*s[v];
		s[u]+=s[v];
	}
}
int main()
{
	F(i,0,read(n))read(s[i]);
	F(i,0,read(m))--read(x[i]),--read(y[i]);
	F(i,0,n)f[i]=i;
	F(i,0,n)hd[i]=-1;
	F(i,0,m)if(find(x[i])!=find(y[i]))
	{
		f[find(x[i])]=find(y[i]);
		adline(x[i],y[i],i,1);
		adline(y[i],x[i],i,-1);
	}
	F(i,0,n)if(find(i)==i)
	{
		dfs(i,i);
		if(s[i])fail=true;
	}
	if(fail)puts("Impossible");
	else
	{
		puts("Possible");
		F(i,0,m)printf("%d\n",ans[i]);
	}
	return 0;
}