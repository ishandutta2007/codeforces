#include<iostream>
#include<cstdio>
#define mp make_pair
using namespace std;
const int naive=300;
int n,m,q,x,y,fuc,vis[111111][15];
pair<int,int> go[111111][15],ans;
char a[111111][15],c,p;
pair<int,int> dfs(int i,int j,int b,int st)
{
	if (j==0 || j==m+1 || i<st) return mp(i,j);
	if (vis[i][j]==b) return go[i][j];
	vis[i][j]=b;
	if (a[i][j]=='^') go[i][j]=dfs(i-1,j,b,st);
	else if (a[i][j]=='<') go[i][j]=dfs(i,j-1,b,st);
	else go[i][j]=dfs(i,j+1,b,st);
	return go[i][j];
}
void update(int bot,int fuc)
{
	int st=max(1,bot-naive+1);
	for (int i=st;i<=bot;i++)
	{
		for (int j=1;j<=m;j++)
		{
			vis[i][j]=0;
		}
	}
	for (int i=st;i<=bot;i++)
	{
		for (int j=1;j<m;j++)
		{
			if (a[i][j]=='>' && a[i][j+1]=='<')
			{
				go[i][j]=go[i][j+1]=mp(-1,-1);
			 } 
		}
	}
	for (int i=st;i<=bot;i++)
	{
		for (int j=1;j<=m;j++)
		{
			dfs(i,j,fuc,st);
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	getchar();
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=m;j++)
		{
			scanf("%c",&a[i][j]);
		}
		getchar();
	}
	fuc=1;
	for (int i=n;i>=1;i-=naive)
	{
		update(i,fuc++);
	}
	while(q--)
	{
		scanf("%c",&c);
		if (c=='A')
		{
			scanf("%d%d",&x,&y);
			ans=go[x][y];
			while(ans.first>0 && ans.second>0 && ans.second<=m)
			ans=go[ans.first][ans.second];
			printf("%d %d\n",ans.first,ans.second);
		}
		else
		{
			scanf("%d%d %c",&x,&y,&p);
			a[x][y]=p;
			while(x%naive!=n%naive) x++;
			update(x,(n-x)/naive+1);
		}
		getchar();
	}
	return 0;
}