#include<cstdio>
#include<vector>
#include<utility>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
const int N=4e5+5;
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
int n,m,t[N][27],k,fail[N],q[N],qf,qr,id[N],ans[N],dfn[N],tm,st[N],c[N],siz[N];
char tt[N];
vector<pair<char,int> > str[N];
vector<int> son[N],qy[N];
int insert(const char *s)
{
	int j=0;
	for(;*s;++s)
	{
		int x=*s-'a';
		if(!t[j][x])t[j][x]=++k;
		j=t[j][x];
	}
	return j;
}
void build()
{
	F(i,0,26)if(t[0][i])q[qr++]=t[0][i];
	while(qf<qr)
	{
		int u=q[qf++];
		son[fail[u]].emplace_back(u);
		F(i,0,26)(t[u][i]?fail[q[qr++]=t[u][i]]:t[u][i])=t[fail[u]][i];
	}
}
void add(int x,int y){for(++x;x<=k;x+=x&-x)c[x]+=y;}
int sum(int x)
{
	int a=0;
	for(;x;x-=x&-x)a+=c[x];
	return a;
}
void dfs1(int u)
{
	dfn[u]=tm++;siz[u]=1;
	for(int v:son[u])dfs1(v),siz[u]+=siz[v];
}
void dfs(int u)
{
	add(dfn[st[u]],1);
	for(int p:qy[u])ans[p]=sum(dfn[id[p]]+siz[id[p]])-sum(dfn[id[p]]);
	for(pair<char,int> r:str[u])
	{
		int v=r.second;
		st[v]=t[st[u]][r.first-'a'];
		dfs(v);
	}
	add(dfn[st[u]],-1);
}
int main()
{
	read(n);
	F(i,1,n+1)
	{
		int opt,x;
		char cc[2];
		read(opt);
		if(opt==2)read(x);else x=0;
		scanf("%s",cc);
		str[x].emplace_back(cc[0],i);
	}
	read(m);
	F(i,0,m)
	{
		int txt;
		read(txt);
		scanf("%s",tt);
		id[i]=insert(tt);
		qy[txt].emplace_back(i);
	}
	++k;
	build();
	dfs1(0);
	dfs(0);
	F(i,0,m)printf("%d\n",ans[i]);
	return 0;
}