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
vector<int>g[200005],ng[200005];
int deg[200005];
char ans[200005];
bool ban[200005],ban_down[200005],ban_up[200005];
void dfs_down(int x){
	for(auto to:g[x]){
		if(ban_down[to])continue;
		dfs_down(to);
	}
	ban_down[x]=ban[x]=1;
}
void dfs_up(int x){
	for(auto to:ng[x]){
		if(ban_up[to])continue;
		dfs_up(to);
	}
	ban_up[x]=ban[x]=1;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		ng[y].push_back(x);
		deg[x]++;
	}
	queue<int>q;int tot=0;
	for(int i=1;i<=n;i++)if(!deg[i])q.push(i);
	while(!q.empty()){
		int x=q.front();
		q.pop();tot++;
		for(auto to:ng[x]){
			deg[to]--;if(!deg[to])q.push(to);
		}
	}
	if(tot!=n){
		puts("-1");
		return 0;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(!ban[i]){
			ans[i]='A';cnt++;
		}else ans[i]='E';
		dfs_down(i);
		dfs_up(i);
	}
	cout<<cnt<<endl;
	for(int i=1;i<=n;i++)cout<<ans[i];
	return 0;
}