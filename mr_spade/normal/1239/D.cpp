#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
using std::min;
using std::vector;
using std::stack;
const int N=1e6+5;
int n,m,idx,cnt;
int dfn[N],low[N],com[N];
bool inst[N];
vector<int> e[N];
stack<int> st;
void dfs(int x)
{
	dfn[x]=low[x]=++idx;
	st.push(x);inst[x]=1;
	for(int y:e[x])
		if(!dfn[y])
			dfs(y),low[x]=min(low[x],low[y]);
		else if(inst[y])
			low[x]=min(low[x],dfn[y]);
	if(dfn[x]==low[x])
	{
		cnt++;
		while(st.top()!=x)
			com[st.top()]=cnt,inst[st.top()]=0,st.pop();
		com[x]=cnt;inst[x]=0;st.pop();
	}
	return;
}
inline void solve()
{
	int x,y;
	register int i;
	scanf("%d%d",&n,&m);idx=cnt=0;
	for(i=1;i<=n;i++)
		e[i].clear(),dfn[i]=low[i]=com[i]=0;
	while(m--)
	{
		scanf("%d%d",&x,&y);
		e[x].push_back(y);
	}
	for(i=1;i<=n;i++)
		if(!dfn[i])
			dfs(i);
	if(cnt==1)
		return puts("No"),void();
	puts("Yes");
	int cur=0;
	for(i=1;i<=n;i++)
		if(com[i]==1)
			cur++;
	printf("%d %d\n",cur,n-cur);
	for(i=1;i<=n;i++)
		if(com[i]==1)
			printf("%d ",i);
	putchar('\n');
	for(i=1;i<=n;i++)
		if(com[i]!=1)
			printf("%d ",i);
	putchar('\n');
	return;
}
signed main()
{
	int T;
	scanf("%d",&T);
	while(T--)
		solve();
	return 0;
}