/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-9;
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
vector<int>g[100005];
vector<int>val[100005];
int ord[100005],pos[100005];
bool cmp(int x,int y){return val[x]<val[y];}
int sz[100005],ban[100005],ans[100005];
void dfs_sz(int x,int par){
	sz[x]=1;
	for(auto to:g[x])if(to!=par&&!ban[to]){
		dfs_sz(to,x);sz[x]+=sz[to];
	}
}
void solve(int x,int lvl=1){
	dfs_sz(x,-1);
	int cur=x;
	while(1){
		bool chg=0;
		for(auto to:g[cur])if(sz[to]*2>sz[x]&&sz[to]<sz[cur]){
			cur=to;chg=1;break;
		}
		if(!chg)break;
	}
	ans[cur]=lvl;ban[cur]=1;
	for(auto to:g[cur])if(!ban[to])solve(to,lvl+1);
}
vector<int>vec[100005],rvec[100005];
int par[100005];
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int a,b;cin>>a>>b;
		if(a>b)swap(a,b);
		vec[a].push_back(b);
		rvec[b].push_back(a);
	}
	int cur=1;int tot=1;
	for(int i=1;i<=n;i++){
		sort(rvec[i].rbegin(),rvec[i].rend());
		for(auto u:rvec[i]){
			val[cur].push_back(i);
			cur=par[cur];
		}
		val[cur].push_back(i); 
		sort(vec[i].begin(),vec[i].end());
		for(auto u:vec[i]){
			g[cur].push_back(++tot);
			g[tot].push_back(cur);
			val[tot].push_back(i);par[tot]=cur;
			cur=tot;
		}
	}
	for(int i=1;i<=tot;i++)sort(val[i].begin(),val[i].end()),reverse(val[i].begin(),val[i].end());
	for(int i=1;i<=tot;i++)ord[i]=i;
	sort(ord+1,ord+tot+1,cmp);
//	for(int i=1;i<=tot;i++)for(auto to:g[i])cerr<<i<<" "<<to<<endl;
	solve(1);
	for(int i=1;i<=tot;i++)cout<<ans[ord[i]]<<" ";
	return 0;
}