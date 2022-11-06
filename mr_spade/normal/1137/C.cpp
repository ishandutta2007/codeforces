#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<stack>
using std::max;
using std::min;
using std::__gcd;
using std::vector;
using std::stack;
const int N=1e5+5,D=55,inf=0x3f3f3f3f;
int n,m,d,idx,cnt,ans;
vector<int> e[N],f[N];
char s[N][D];
int dfn[N],low[N],com[N];
int deep[N];
stack<int> st;
bool inst[N];
int base[N];
int id[N];
bool vis[N][D];
int dp[N][D],epc[N][D];
int tmp[D];
bool book[N];
void dfs(int x)
{
	dfn[x]=low[x]=++idx;
	st.push(x);inst[x]=1;
	for(auto y:e[x])
		if(!dfn[y])
		{
			deep[y]=deep[x]+1;dfs(y);
			low[x]=min(low[x],low[y]);
		}
		else if(inst[y])
			low[x]=min(low[x],dfn[y]);
	if(dfn[x]==low[x])
	{
		com[x]=++cnt;
		while(st.top()!=x)
			com[st.top()]=cnt,inst[st.top()]=0,st.pop();
		inst[x]=0;st.pop();
	}
	return;
}
void dfs2(int x,int x2)
{
	vis[x][x2]=1;
	for(auto y:e[x])
		if(com[x]==com[y]&&!vis[y][(x2+1)%d])
			dfs2(y,(x2+1)%d);
	return;
}
signed main()
{
	int x,y;
	register int i,j;
	scanf("%d%d%d",&n,&m,&d);
	for(i=1;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
	}
	for(i=1;i<=n;i++)
		scanf("%s",s[i]);
	dfs(1);
	for(i=1;i<=n;i++)
		if(dfn[i]&&!book[com[i]])
		{
			book[com[i]]=1;
			dfs2(i,0);
		}
	for(i=1;i<=cnt;i++)
		base[i]=d;
	for(i=1;i<=n;i++)
		if(dfn[i])
		{
			for(j=0;j<d;j++)
				if(vis[i][j])
				{
					id[i]=j;
					break;
				}
			for(j=id[i]+1;j<d;j++)
				if(vis[i][j])
				{
					base[com[i]]=__gcd(base[com[i]],j-id[i]);
					break;
				}
		}
	for(i=1;i<=n;i++)
		if(dfn[i])
			f[com[i]].push_back(i);
	for(i=1;i<=n;i++)
		if(dfn[i])
		{
			memset(tmp,0,sizeof(tmp));
			for(j=0;j<d;j++)
				if(s[i][j]=='1')
					tmp[j%base[com[i]]]=1;
			for(j=0;j<base[com[i]];j++)
				epc[com[i]][(base[com[i]]-id[i]+j)%base[com[i]]]+=tmp[j];
		}
	memset(dp,0xc0,sizeof(dp));
	dp[com[1]][0]=0;
	for(i=cnt;i>=1;i--)
	{
		memset(tmp,0xc0,sizeof(tmp));
		for(j=0;j<d;j++)
			tmp[j%base[i]]=max(tmp[j%base[i]],dp[i][j]);
		for(j=0;j<base[i];j++)
			if(tmp[j]!=~inf)
				tmp[j]+=epc[i][j],ans=max(ans,tmp[j]);
		for(j=0;j<d;j++)
			dp[i][j]=tmp[j%base[i]];
		for(auto x:f[i])
		{
			for(auto y:e[x])
				if(dfn[y]&&com[x]!=com[y])
				{
					for(j=0;j<d;j++)
						dp[com[y]][((j+id[x]+1)%d+d-id[y])%d]=max(dp[com[y]][((j+id[x]+1)%d+d-id[y])%d],dp[i][j]);
				}
		}
	}
	printf("%d\n",ans);
	return 0;
}