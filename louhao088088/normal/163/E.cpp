#include<bits/stdc++.h>
#define lowbit(x) x&(-x)
using namespace std;
const int maxn=1e6+5;
inline int read()
{
	char ch=getchar();bool f=0;int x=0;
	for(;!isdigit(ch);ch=getchar())if(ch=='-')f=1;
	for(;isdigit(ch);ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	if(f==1)x=-x;return x;
}
int n,c[maxn],m,tot=0,dfn[maxn],low[maxn],cnt=0,idx=0,id[maxn],head[maxn],x,Rt;
char ch,s[maxn];
bool vis[maxn];
void change(int x,int num){for(int i=x;i<=idx;i+=lowbit(i))c[i]+=num;}
int query(int x){int res=0;for(int i=x;i;i-=lowbit(i))res+=c[i];return res;}
struct tire{int son[26],fail;}tr[maxn];
struct edge{int v,nex;}e[maxn];
void add(int u,int v){e[++cnt].v=v,e[cnt].nex=head[u],head[u]=cnt;}
void ins(int x)
{
	int len=strlen(s),u=0;
	for(int i=0;i<len;i++)
	{
		if(!tr[u].son[s[i]-'a'])tr[u].son[s[i]-'a']=++tot;
		u=tr[u].son[s[i]-'a'];
	}id[x]=u;
}
void getfail()
{
	queue<int>q;
	for(int i=0;i<26;i++)if(tr[0].son[i])q.push(tr[0].son[i]),add(0,tr[0].son[i]);
	while(!q.empty())
	{
		int u=q.front();q.pop();
		for(int i=0;i<26;i++)
		{
			int v=tr[u].son[i];
			if(v)tr[v].fail=tr[tr[u].fail].son[i],q.push(v),add(tr[v].fail,v);
			else tr[u].son[i]=tr[tr[u].fail].son[i];
		}
	}
}
void dfs(int x)
{
	//cout<<x<<endl;
	dfn[x]=++idx;
	for(int i=head[x];i;i=e[i].nex)
		dfs(e[i].v);low[x]=idx;
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);ins(i);
	}getfail();dfs(0);//cout<<"G";
	for(int i=1;i<=n;i++)
		change(dfn[id[i]],1),change(low[id[i]]+1,-1),vis[i]=1;//cout<<dfn[id[i]]<<" "<<low[id[i]]<<endl;//cout<<"A";
	for(int i=1;i<=m;i++)
	{
		ch=getchar();while(ch!='?'&&ch!='-'&&ch!='+')ch=getchar();
		if(ch=='?')
		{
			scanf("%s",s);int len=strlen(s);int ans=0,u=0;
			for(int i=0;i<len;i++)u=tr[u].son[s[i]-'a'],ans+=query(dfn[u]);//cout<<dfn[u]<<" "<<query(dfn[u])<<endl;
			printf("%d\n",ans);
		}
		else if(ch=='+')
		{
			x=read();if(vis[x])continue;vis[x]=1;
			change(dfn[id[x]],1),change(low[id[x]]+1,-1);
		}
		else
		{x=read();
			if(!vis[x])continue;vis[x]=0;
			change(dfn[id[x]],-1),change(low[id[x]]+1,1);
		}ch=0;
	}
	return 0;
}