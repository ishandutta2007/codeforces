#include<cstdio>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=6e5+5;
const long long LLINF=0x3fffffff;
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
}e[N];
struct result
{
	long long r,len;
	result(long long a,long long b){r=a,len=b;}
	result(long long x=LLINF){r=len=x;}
	result operator+(result b)const{return result(r+b.r,len+b.len);}
	bool operator<(result b)const{return r!=b.r?r<b.r:len<b.len;}
}ans(0);
int m,to[N][26],num[N],ncnt,nd,essay[N],n,tmpu[N],tmpv[N],hd[N],cnt;
int dfn[N],low[N],scc[N],czq,ind,sta[N],top;
result r[N],f[N];
bool instk[N],vis[N];
char str[N];
int insert(const char *s)
{
	int j=0;
	for(int i=0;s[i];++i)
	{
		int x=(s[i]|32)^96;
		if(!to[j][x])to[j][x]=++ncnt;
		j=to[j][x];
	}
	if(!num[j])
	{
		r[nd].r=0,r[nd].len=0;
		for(int i=0;s[i];++i)++r[nd].len,r[nd].r+=(s[i]|32)=='r';
		num[j]=++nd;
	}
	return num[j]-1;
}
inline void adline(int u,int v)
{
	e[cnt].to=v;
	e[cnt].next=hd[u];
	hd[u]=cnt++;
}
void tarjan(int u)
{
	low[u]=dfn[u]=ind++;
	instk[sta[top++]=u]=true;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		if(!~dfn[v])
		{
			tarjan(v);
			if(low[v]<low[u])low[u]=low[v];
		}
		else if(instk[v])if(dfn[v]<low[u])low[u]=dfn[v];
	}
	if(dfn[u]==low[u])
	{
		while(sta[--top]!=u)instk[sta[top]]=false,scc[sta[top]]=czq;
		instk[u]=false;scc[u]=czq++;
	}
}
void dfs(int u)
{
	if(vis[u])return;
	vis[u]=true;
	for(int i=hd[u];~i;i=e[i].next)
	{
		int v=e[i].to;
		dfs(v);
		if(f[v]<f[u])f[u]=f[v];
	}
}
int main()
{
	read(m);
	F(i,0,m)scanf("%s",str),essay[i]=insert(str);
	read(n);
	F(i,0,n)
	{
		scanf("%s",str);
		tmpu[i]=insert(str);
		scanf("%s",str);
		tmpv[i]=insert(str);
	}
	F(i,0,nd)hd[i]=-1;
	F(i,0,n)adline(tmpu[i],tmpv[i]);
	F(i,0,nd)dfn[i]=-1,low[i]=-1;
	F(i,0,nd)if(!~dfn[i])tarjan(i);
	F(i,cnt=0,czq)hd[i]=-1;
	F(i,0,n)if(scc[tmpu[i]]!=scc[tmpv[i]])adline(scc[tmpu[i]],scc[tmpv[i]]);
	F(i,0,nd)if(r[i]<f[scc[i]])f[scc[i]]=r[i];
	F(i,0,czq)dfs(i);
	F(i,0,m)ans=ans+f[scc[essay[i]]];
	printf("%lld %lld\n",ans.r,ans.len);
	return 0;
}