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

const int maxn = 110000;
const int maxN = 205;

int n,m,sum;
vector<int>V[maxn];
queue<int>q;
char str[maxn]; int Len[maxn]; 
int Nid[maxn],nid;
ll Npre[maxN][maxn];
struct Trie
{
	int root,tot;
	int son[maxn][26],fail[maxn];
	void Init() { root=tot=0; }
	void Ins(int i)
	{
		int x=root;
		for(int j=0;j<Len[i];j++)
		{
			const int w=str[j]-'a';
			if(!son[x][w]) son[x][w]=++tot;
			V[i].push_back(x=son[x][w]);
		}
	}
	void Build()
	{
		q.push(root);
		while(!q.empty())
		{
			int x=q.front(); q.pop();
			int fl=fail[x];
			for(int j=0;j<26;j++)
			{
				int &y=son[x][j];
				if(!y) y=son[fl][j];
				else
				{
					if(x!=root) fail[y]=son[fl][j];
					q.push(y);
				}
			}
		}
	}
}Tr;
struct edge{int y,nex;}a[maxn<<1]; int len,fir[maxn];
inline void ins(const int x,const int y){a[++len]=(edge){y,fir[x]};fir[x]=len;}
struct FailTree
{
	int dfn[maxn],dfi,siz[maxn];
	int L[maxn],id[maxn],N,u;
	int s[maxn],flag[maxN];
	void dfs(const int x)
	{
		dfn[x]=++dfi; siz[x]=1;
		for(int k=fir[x],y=a[k].y;k;k=a[k].nex,y=a[k].y)
			dfs(y),siz[x]+=siz[y];
	}
	void Build()
	{
		u=Tr.tot+1; N=500;
		for(int i=1;i<=u;i++) id[i]=(i-1)/N+1; id[u+1]=id[u]+1;
		for(int i=1;i<=id[u];i++) L[i]=(i-1)*N+1; L[id[u+1]]=u+1;
		
		for(int i=1;i<=Tr.tot;i++) ins(Tr.fail[i],i);
		dfs(Tr.root);
	}
	void Add(int i)
	{
		int x=V[i][(int)V[i].size()-1];
		int l=dfn[x],r=dfn[x]+siz[x]-1;
		if(id[l]==id[r])
		{
			for(int i=l;i<=r;i++) s[i]++;
		}
		else
		{
			for(int i=l;i<L[id[l]+1];i++) s[i]++;
			for(int i=id[l]+1;i<id[r];i++) flag[i]++;
			for(int i=L[id[r]];i<=r;i++) s[i]++;
		}
	}
	ll Query(int i)
	{
		ll re=0;
		for(int j=0;j<(int)V[i].size();j++)
		{
			int x=dfn[V[i][j]];
			re+=flag[id[x]]+s[x];
		}
		return re;
	}
}Tree;

int t[maxn];

int op[maxn][3];
ll ans[maxn];
vector<int>ansi[maxn];

int main()
{
	//freopen("tmp.in","r",stdin);
	//freopen("tmp.out","w",stdout);
	
	Tr.Init();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",str); Len[i]=strlen(str);
		sum+=Len[i];
		Tr.Ins(i);
	}
	Tr.Build();
	Tree.Build();
	for(int i=1;i<=n;i++) if(Len[i]*500>sum)
	{
		Nid[i]=++nid;
		for(int j=1;j<=Tree.u;j++) t[j]=0;
		for(int j=0;j<(int)V[i].size();j++) t[Tree.dfn[V[i][j]]]++;
		for(int j=1;j<=Tree.u;j++) t[j]+=t[j-1];
		for(int j=1;j<=n;j++)
		{
			int x=V[j][(int)V[j].size()-1];
			Npre[nid][j]=Npre[nid][j-1]+t[Tree.dfn[x]+Tree.siz[x]-1]-t[Tree.dfn[x]-1];
		}
	}
	
	for(int i=1;i<=m;i++)
	{
		int l,r,k; scanf("%d%d%d",&l,&r,&k);
		op[i][0]=l,op[i][1]=r,op[i][2]=k;
		if(Nid[k]) ans[i]=Npre[Nid[k]][r]-Npre[Nid[k]][l-1];
		else ansi[l-1].push_back(i),ansi[r].push_back(i);
	}
	for(int i=1;i<=n;i++)
	{
		Tree.Add(i);
		for(int j=0;j<(int)ansi[i].size();j++)
		{
			int ii=ansi[i][j];
			if(i==op[ii][1]) ans[ii]+=Tree.Query(op[ii][2]);
			else ans[ii]-=Tree.Query(op[ii][2]);
		}
	}
	for(int i=1;i<=m;i++) printf("%lld\n",ans[i]);
	
	return 0;
}