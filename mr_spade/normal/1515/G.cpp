#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#define mp make_pair
#define fi first
#define se second
#define int long long
#define abs(x) ((x)<0?(-(x)):(x))
using std::pair;
using std::mp;
using std::max;
using std::min;
using std::__gcd;
using std::vector;
using std::stack;
const int N=1e6+5;
int n,m,idx,cnt,ans;
int w[N],w2[N],dp[N];
vector<pair<int,int> > e[N],e2[N];
int dfn[N],low[N],com[N];
vector<int> Com[N];
stack<int> st;
bool inst[N];
void dfs(int x)
{
	register int i;
	dfn[x]=low[x]=++idx;
	st.push(x);inst[x]=1;
	for(auto p:e[x])
	{
		int y=p.fi;
		if(!dfn[y])
			dfs(y),low[x]=min(low[x],low[y]);
		else if(inst[y])
			low[x]=min(low[x],low[y]);
	}
	if(dfn[x]==low[x])
	{
		for(com[x]=++cnt;st.top()!=x;st.pop())
			com[st.top()]=cnt,Com[cnt].push_back(st.top()),inst[st.top()]=0;
		inst[x]=0;st.pop();Com[cnt].push_back(x);
	}
	return;
}
int epc[N],Mod[N];
bool flag;
int v;
void dfs(int x,int cur,int mod)
{
	if(epc[x]!=-1&&cur!=epc[x])
	{
		flag=1;v=abs(cur-epc[x]);
		return;
	}
	if(epc[x]!=-1)
		return;
	epc[x]=cur;
	for(auto p:e2[x])
	{
		int y=p.fi;
		dfs(y,mod==-1?cur+p.se:(cur+p.se)%mod,mod);
		if(flag)
			return;
	}
}
inline void get(int x)
{
	int s=0;
	flag=0;
	for(int y:Com[x])
		epc[y]=-1;
	dfs(Com[x][0],0,-1);
	while(flag)
	{
		s=__gcd(s,v);
		flag=0;
		for(int y:Com[x])
			epc[y]=-1;
		dfs(Com[x][0],0,s);
	}
	Mod[x]=s;
	return;
}
signed main()
{
	int u,v,w,q,s,t;
	register int i;
	scanf("%lld%lld",&n,&m);
	while(m--)
		scanf("%lld%lld%lld",&u,&v,&w),e[u].push_back(mp(v,w));
	for(i=1;i<=n;i++)
		if(!dfn[i])
			dfs(i);
	for(i=1;i<=n;i++)
		for(auto p:e[i])
		{
			int j=p.fi;
			if(com[i]==com[j])
				e2[i].push_back(p);
		}
	for(i=1;i<=cnt;i++)
		get(i);
	scanf("%lld",&q);
	while(q--)
	{
		scanf("%lld%lld%lld",&v,&s,&t);
		if(s%__gcd(Mod[com[v]],t)==0)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}