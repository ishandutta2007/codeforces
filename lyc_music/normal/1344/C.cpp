#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int read()
{
	int s=0;
	char c=getchar(),lc='+';
	while (c<'0'||'9'<c) lc=c,c=getchar();
	while ('0'<=c&&c<='9') s=s*10+c-'0',c=getchar();
	return lc=='-'?-s:s;
}
void write(int x)
{
	if (x<0)
	{
		putchar('-');
		x=-x;
	}
	if (x<10) putchar(x+'0');
	else
	{
		write(x/10);
		putchar(x%10+'0');
	}
}
void print(int x,char c='\n')
{
	write(x);
	putchar(c);
}
struct edge
{
	int to,nxt;
}e[N];
int head[N],cnt=0;
void add(int u,int v)
{
	e[++cnt].to=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
int siz[N],Min1[N],Min2[N];
bool vis[N];
int q[N],h=1,t=0;
bool check(int n)
{
	for (int i=1;i<=n;i++)
	if (siz[i]==0)
	q[++t]=i;
	while (h<=t)
	{
		int now=q[h];
		for (int i=head[now];i;i=e[i].nxt)
		{
			int to=e[i].to;
			siz[to]--;
			if (!siz[to]) q[++t]=to;
		}
		h++;
	}
	return t!=n;
}
vector<int>in[N],out[N];

signed main()
{
	memset(vis,0,sizeof(vis));
	memset(siz,0,sizeof(siz));
	int n=read(),m=read(),ans=0;
	for (int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		add(u,v);
		siz[v]++;
		vis[max(u,v)]=1;
		in[v].push_back(u);
		out[u].push_back(v);
	}
	if (check(n)) return puts("-1"),0;
	for (int i=1;i<=n;i++) Min1[i]=Min2[i]=i;
	for (int i=1;i<=n;i++)
	{
		int now=q[i];
		for (int j=0;j<in[now].size();j++)
		Min1[now]=min(Min1[now],Min1[in[now][j]]);
	}
	for (int i=n;i>=1;i--)
	{
		int now=q[i];
		for (int j=0;j<out[now].size();j++)
		Min2[now]=min(Min2[now],Min2[out[now][j]]);
	}
	for (int i=1;i<=n;i++) vis[i]=Min1[i]>=i&&Min2[i]>=i;
	for (int i=1;i<=n;i++) ans+=vis[i];
	print(ans);
	for (int i=1;i<=n;i++) putchar(vis[i]?'A':'E');

	return 0;
}