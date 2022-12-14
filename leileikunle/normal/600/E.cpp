#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int ios = [](){ios::sync_with_stdio(false),cin.tie(0),cout.tie(0); return 0;}();
const int N = 1e6+10,inf = 0x3f3f3f3f;
int col[N],cnt[N];
// cnt"" 
int ans[N],maxc; 
int h[N],e[N*2],ne[N*2],idx;
int flag,sum;
void add(int a,int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
int sz[N],son[N];
void dfs1(int u,int f)
{
	sz[u] = 1;
	for(int i=h[u];~i;i=ne[i])
	{
		int v = e[i];
		if(v==f) continue;
		dfs1(v,u);
		sz[u] += sz[v];
		if(sz[v]>sz[son[u]]) son[u] = v;
	}
}

//TODO 
void count(int u,int f,int val)
{
	cnt[col[u]] += val;  // val 1/-1  
	if(cnt[col[u]]>maxc) 
	{
		maxc = cnt[col[u]];
		sum = col[u]; 
	}else if(cnt[col[u]]==maxc) sum+=col[u];
	
	for(int i=h[u];~i;i=ne[i])
	{
		int v = e[i];
		if(v==f||v==flag) continue;
		count(v,u,val);
	}
}

// dsu on tree
void dfs2(int u,int f,bool del)
{
	//* 
	for(int i=h[u];~i;i=ne[i])
	{
		int v = e[i];
		if(v==f||v==son[u]) continue;
		dfs2(v,u,false);
	}
	
	//* 
	if(son[u])
	{
		dfs2(son[u],u,true);
		flag = son[u];
	}
	
	//* u
	count(u,f,1);
	ans[u] = sum;
	flag = 0;
	if(!del)
	{
		count(u,f,-1);
		sum = 0;
		maxc = -inf; 
	}
}
void solve()
{
	memset(h,-1,sizeof h);
	int n; cin>>n;
	for(int i=1;i<=n;i++) cin>>col[i];
	for(int i=1,u,v;i<n;i++)
	{
		cin>>u>>v;
		add(u,v); add(v,u);
	}
	dfs1(1,-1);
	dfs2(1,-1,0);
	for(int i=1;i<=n;i++)
	{
		cout<<ans[i]<<" ";
	}
}
signed main()
{
	int tt=1; 
//	cin>>tt;
	while(tt--){
		solve();//TODO
	}
	
}