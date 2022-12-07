#include <bits/stdc++.h>
#define N 100010
using namespace std;

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

int vis[1000010];
int n,m,q,ans;
struct Node
{
	int opt, x, y, id;
}A[N];
int Ans[N];
vector<int> G[N];
void dfs(int u)
{
	Ans[A[u].id]=ans;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		if(A[v].opt==1)
		{
			int x=(A[v].x-1)*m+A[v].y;
			bool flag=0;
			if(!vis[x])flag=1;
			if(flag)vis[x]=1,ans++;
			dfs(v);
			if(flag)vis[x]=0,ans--;
		}
		if(A[v].opt==2)
		{
			int x=(A[v].x-1)*m+A[v].y;
			bool flag=0;
			if(vis[x])flag=1;
			if(flag)vis[x]=0,ans--;
			dfs(v);
			if(flag)vis[x]=1,ans++;
		}
		if(A[v].opt==3)
		{
			int l=(A[v].x-1)*m+1,r=A[v].x*m;
			for(int i=l;i<=r;i++)
				if(vis[i])vis[i]=0,ans--;else vis[i]=1,ans++;
			dfs(v);
			for(int i=l;i<=r;i++)
				if(vis[i])vis[i]=0,ans--;else vis[i]=1,ans++;
		}
		if(A[v].opt==4) dfs(v);
	}
}

void insert(int u,int v)
{
	G[u].push_back(v);
}

int main()
{
	n = read();
	m = read();
	q = read();
	for(int i=1;i<=q;i++)
	{
		A[i].opt = read();
		A[i].id = i;
		if(A[i].opt==1||A[i].opt==2) A[i].x = read(), A[i].y = read();
		else A[i].x = read();
		if(A[i].opt==4) insert(A[i].x,i);
		else insert(i - 1, i);
	}
	dfs(0);
	for(int i=1;i<=q;i++)printf("%d\n",Ans[i]);
	return 0;
}