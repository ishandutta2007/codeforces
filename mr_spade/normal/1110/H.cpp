#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using std::max;
using std::vector;
using std::queue;
const int L=805,N=2005,M=3e4+5,inf=0x3f3f3f3f;
int root,tot;
int ch[M][10],fail[M];
int f[N][M],suc[N][M],g[M][N];
bool book[N][M];
int n;
char l[L],r[L];
int ll,lr;
vector<int> V[M];
queue<int> Q;
void dfs(int x,int s,int t,int lim)
{
	if(s==t||lim==0)
		return (t-s<=n?g[x][t-s]=1:0),void();
	int y;
	register int i; 
	if(lim==3)
	{
		if(l[s+1]==r[s+1])
		{
			if(!ch[x][l[s+1]-'0'])
				y=++tot,ch[x][l[s+1]-'0']=y;
			else
				y=ch[x][l[s+1]-'0'];
			dfs(y,s+1,t,3);
		}
		else
		{
			if(!ch[x][l[s+1]-'0'])
				y=++tot,ch[x][l[s+1]-'0']=y;
			else
				y=ch[x][l[s+1]-'0'];
			dfs(y,s+1,t,1);
			for(i=l[s+1]-'0'+1;i<r[s+1]-'0';i++)
			{
				if(!ch[x][i])
					y=++tot,ch[x][i]=y;
				else
					y=ch[x][i];
				dfs(y,s+1,t,0);
			}
			if(!ch[x][r[s+1]-'0'])
				y=++tot,ch[x][r[s+1]-'0']=y;
			else
				y=ch[x][r[s+1]-'0'];
			dfs(y,s+1,t,2);
		}
	}
	else if(lim==2)
	{
		for(i=s?0:1;i<r[s+1]-'0';i++)
		{
			if(!ch[x][i])
				y=++tot,ch[x][i]=y;
			else
				y=ch[x][i];
			dfs(y,s+1,t,0);
		}
		if(!ch[x][r[s+1]-'0'])
			y=++tot,ch[x][r[s+1]-'0']=y;
		else
			y=ch[x][r[s+1]-'0'];
		dfs(y,s+1,t,2);
	}
	else
	{
		if(!ch[x][l[s+1]-'0'])
			y=++tot,ch[x][l[s+1]-'0']=y;
		else
			y=ch[x][l[s+1]-'0'];
		dfs(y,s+1,t,1);
		for(i=l[s+1]-'0'+1;i<10;i++)
		{
			if(!ch[x][i])
				y=++tot,ch[x][i]=y;
			else
				y=ch[x][i];
			dfs(y,s+1,t,0);
		}
	}
}
inline void build_fail()
{
	int x;
	register int i;
	for(i=0;i<10;i++)
		if(ch[root][i])
			fail[ch[root][i]]=root,Q.push(ch[root][i]);
		else
			ch[root][i]=root;
	while(!Q.empty())
	{
		x=Q.front();Q.pop();
		for(i=0;i<10;i++)
			if(ch[x][i])
				fail[ch[x][i]]=ch[fail[x]][i],Q.push(ch[x][i]);
			else
				ch[x][i]=ch[fail[x]][i];
	}
	return;
}
void dfs2(int x)
{
	register int i;
	for(auto y:V[x])
	{
		for(i=0;i<=n;i++)
			g[y][i]+=g[x][i];
		dfs2(y);
	}
	return;
}
signed main()
{
	register int i,j,k;
	scanf("%s%s%d",l+1,r+1,&n);
	ll=strlen(l+1);lr=strlen(r+1);
	root=++tot;
	if(ll==lr)
		dfs(root,0,ll,3);
	else
	{
		dfs(root,0,ll,1);
		for(i=ll+1;i<lr;i++)
			dfs(root,0,i,0);
		dfs(root,0,lr,2);
	}
	build_fail();
	for(i=2;i<=tot;i++)
		V[fail[i]].push_back(i);
	dfs2(root);
	for(i=1;i<=tot;i++)
		for(j=1;j<=n;j++)
			g[i][j]+=g[i][j-1];
	memset(f,0xc0,sizeof(f));
	f[0][root]=g[root][n];
	for(i=0;i<n;i++)
	{
		for(j=1;j<=tot;j++)
			if(f[i][j]>~inf)
			{
				for(k=0;k<10;k++)
					if(f[i][j]+g[ch[j][k]][n-i-1]>f[i+1][ch[j][k]])
						f[i+1][ch[j][k]]=f[i][j]+g[ch[j][k]][n-i-1];
			}
	}
	int ans=0,x;
	for(j=1;j<=tot;j++)
		if(f[n][j]>ans)
			ans=f[n][j];
	for(j=1;j<=tot;j++)
		if(f[n][j]==ans)
			book[n][j]=1;
	for(i=n-1;i>=0;i--)
	{
		for(j=1;j<=tot;j++)
		{
			suc[i][j]=-1;
			for(k=9;k>=0;k--)
				if(book[i+1][ch[j][k]]&&f[i][j]+g[ch[j][k]][n-i-1]==f[i+1][ch[j][k]])
					book[i][j]=1,suc[i][j]=k;
		}
	}
	printf("%d\n",ans);
	x=root;
	for(i=0;i<n;i++)
	{
		putchar(suc[i][x]+'0');
		x=ch[x][suc[i][x]];
	}
	putchar('\n');
	return 0;
}