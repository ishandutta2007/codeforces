#include<cstdio>
#include<vector>
#define F(i,l,r) for(int i=l,i##_end=r;i<i##_end;++i)
using namespace std;
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
constexpr int N=1e6+5;
struct BITb
{
	int n,c[N];
	void init(int n_){n=n_;}
	void add(int x,int y){for(++x;x<=n;x+=x&-x)c[x]+=y;}
	int sum(int x){int ans=0;for(;x;x-=x&-x)ans+=c[x];return ans;}
}a;
int q,n,to[N][26],fail[N],ind=1,node[N],qu[N],qf,qr,dfn[N],siz[N],l[N],r[N];
bool exist[N];
vector<int> adj[N];
char s[N];
int insert()
{
	int j=0;
	for(int i=0;s[i];++i)
	{
		int x=s[i]-'a';
		if(!to[j][x])to[j][x]=ind++;
		j=to[j][x];
	}
	return j;
}
void build()
{
	F(i,0,26)if(to[0][i])qu[qr++]=to[0][i];
	while(qf<qr)
	{
		int u=qu[qf++];
		adj[fail[u]].emplace_back(u);
		F(i,0,26)(to[u][i]?fail[qu[qr++]=to[u][i]]:to[u][i])=to[fail[u]][i];
	}
}
void dfs(int u)
{
	dfn[u]=ind++;
	siz[u]=1;
	for(int v:adj[u])
	{
		dfs(v);
		siz[u]+=siz[v];
	}
}
int main()
{
	read(q,n);
	F(i,0,n)
	{
		scanf("%s",s);
		node[i]=insert();
	}
	build();
	ind=0;
	dfs(0);
	a.init(ind+1);
	F(i,0,n)l[i]=dfn[node[i]],r[i]=l[i]+siz[node[i]];
	F(i,0,n)
	{
		exist[i]=true;
		a.add(l[i],1);a.add(r[i],-1);
	}
	while(q--)
	{
		int opt=getchar();while(opt<32)opt=getchar();
		if(opt=='?')
		{
			scanf("%s",s);
			long long ans=0;
			for(int i=0,j=0;s[i];++i)
			{
				j=to[j][s[i]-'a'];
				ans+=a.sum(dfn[j]+1);
			}
			printf("%lld\n",ans);
		}
		if(opt=='+')
		{
			int x;--read(x);
			if(!exist[x])
			{
				exist[x]=true;
				a.add(l[x],1);a.add(r[x],-1);
			}
		}
		if(opt=='-')
		{
			int x;--read(x);
			if(exist[x])
			{
				exist[x]=false;
				a.add(l[x],-1);a.add(r[x],1);
			}
		}
	}
	return 0;
}