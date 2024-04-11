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
int n,k;
int par[300005];
vector<int>g[300005];
vector<int>ng[300005];
vector<int>ord[300005];
int nxt[300005],deg[300005];
int find(int x){
	return x==par[x]?x:par[x]=find(par[x]);
}
void print(int x){
	for(auto v:ord[x])cout<<v<<" ";
}
int low[300005],dfn[300005],vis[300005],tot;
void tarjan(int x){
	low[x]=dfn[x]=++tot;vis[x]=1;
	for(auto to:g[x]){
//		cerr<<x<<" "<<to<<endl;
		if(!dfn[to]){
			tarjan(to);
			low[x]=min(low[x],low[to]);
		}else if(vis[to]==1){
			low[x]=min(low[x],dfn[to]);
		}
	}
	vis[x]=2;
	if(low[x]!=dfn[x]){
		puts("0");
		exit(0);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		int p;cin>>p;
		g[p].push_back(i);
	}
	for(int i=1;i<=k;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		if(nxt[x]){
			puts("0");
			return 0;
		}
		nxt[x]=y;
	}
	int root=g[0][0];
	tarjan(root);
	for(int i=1;i<=n;i++)par[i]=i;
	for(int i=1;i<=n;i++){
		if(nxt[i])par[find(nxt[i])]=find(i);
	}
	for(int i=1;i<=n;i++){
		for(auto to:g[i]){
			if(find(i)!=find(to))ng[find(to)].push_back(find(i)),deg[find(i)]++;
		}
	}
	for(int i=1;i<=n;i++)if(find(i)==i){
		int cur=i;
		int tot=0;
		while(cur){
			tot++;
			ord[i].push_back(cur);
			cur=nxt[cur];
			if(tot>=n+5){
				puts("0");
				return 0;
			}
		}
	}
	queue<int>q;vector<int>ans;
	for(int i=1;i<=n;i++)if(find(i)==i&&!deg[i])q.push(i);
	while(!q.empty()){
		int x=q.front();q.pop();
		ans.push_back(x);
		for(auto to:ng[x]){
			deg[to]--;
			if(!deg[to]){
				q.push(to);
			}
		}
	}
	for(int i=1;i<=n;i++)if(deg[i]){
		puts("0");return 0;
	}
	reverse(ans.begin(),ans.end());
	for(auto id:ans){
		print(id);
	}
	return 0;
}