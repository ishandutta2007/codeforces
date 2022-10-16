/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int n,m;
vector<int>g[2005];
set<int>ng[2005];
int dfn[2005],low[2005],p[2005],cnt,tot=0,ans,col[2005],vis[2005];
vector<int>hv[2005];
bool ban[2005];
stack<int>stk;
void dfs(int x){
	dfn[x]=low[x]=++cnt;
	stk.push(x);
	for(auto to:g[x])if(to!=p[x]){
		if(!dfn[to]){
			p[to]=x;
			dfs(to);low[x]=min(low[x],low[to]);
		}else{
			low[x]=min(low[x],dfn[to]);
		}
	}
	if(low[x]==dfn[x]){
		tot++;
		while(!stk.empty()){
			int y=stk.top();stk.pop();
			hv[tot].push_back(y);
			col[y]=tot;
			if(x==y)break;
			ans++;
		}
	}
}
vector<int>vec;
int get(int x){
	vec.push_back(x);vis[x]=1;
	for(auto to:ng[x])if(!vis[to])get(to);
}
int calc(int x,int par){
	int ret=1;
	for(auto to:ng[x])if(to!=par&&!ban[to]){
		ret=max(ret,calc(to,x)+1);
	}
	return ret;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	for(int i=1;i<=n;i++)if(!dfn[i])dfs(i);
	for(int i=1;i<=n;i++){
		for(auto to:g[i]){
			if(col[i]!=col[to]){
				ng[col[i]].insert(col[to]);
			}
		}
	}
	for(int i=1;i<=tot;i++){
		if(!vis[i]){
			get(i);ans++;
			ans+=vec.size();
			for(auto x:vec)if(ng[x].size()==1)ans--,ban[x]=1;
			int cur=0;
			for(auto x:vec)if(!ban[x])cur=max(cur,calc(x,-1));
			ans-=cur;
			vec.clear();
		}
	}
	cout<<ans-1<<endl;
	return 0;
}