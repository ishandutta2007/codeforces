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
int n,m,k;
vector<pair<int,int> >g[200005];
set<pair<int,int> >rg[200005];
bool ban[11][11][11][11];
void del(set<pair<int,int> >s){
	for(auto p1:s){
//		cerr<<p1.first<<" "<<p1.second<<endl;
		for(auto p2:s){
			ban[p1.first][p1.second][p2.first][p2.second]=1;
		}
	}
//	cerr<<"------"<<endl;
}
int ans[66],res,Ban[66][66];
void dfs(int x){
	if(x==k+1){
//		for(int i=1;i<=k;i++)cerr<<ans[i]<<" ";cerr<<endl;
		res++;
		return;
	}
	for(int i=1;i<=x;i++){
		if(Ban[x][i])continue;
		ans[x]=i;
		bool can=1;
		for(int j=x-1;j>=1;j--){
			if(ban[j][ans[j]][x][ans[x]])can=0;
		}
		if(can)dfs(x+1);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin>>n>>m>>k;
	for(int i=1;i<=m;i++){
		int x,y,z;cin>>x>>y>>z;
		g[x].push_back(make_pair(z,y));
	}
	for(int i=1;i<=n;i++)sort(g[i].begin(),g[i].end());
	for(int i=1;i<=n;i++){
		int pos=1;
		for(auto p:g[i]){
//			cerr<<"edge: "<<p.second<<" "<<g[i].size()<<" "<<pos<<endl;
			if(rg[p.second].count(make_pair((int)g[i].size(),pos))){
				Ban[(int)g[i].size()][pos]=1;
			}
			rg[p.second].insert(make_pair((int)g[i].size(),pos));
			pos++;
		}
	}
	for(int i=1;i<=n;i++){
		del(rg[i]);
	}
	dfs(1);
	cout<<res<<endl;
	return 0;
}