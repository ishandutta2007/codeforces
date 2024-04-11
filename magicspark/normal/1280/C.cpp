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
#define int long long
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
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
//1500pts
int T,n,Min,Max;
vector<pair<int,int> >g[200005];
int sz[200005];
void dfs_sz(int x,int par){
	sz[x]=1;
	for(auto p:g[x]){
		if(p.first!=par){
			dfs_sz(p.first,x);
			sz[x]+=sz[p.first];
		}
	}
}
void dfs_min(int x,int par){
	for(auto p:g[x]){
		int to=p.first,cost=p.second;
		if(to==par)continue;
		dfs_min(to,x);
		if(sz[to]&1)Min+=cost;
	}
}
void dfs_max(int x,int par,int rest){
//	cerr<<x<<" "<<par<<" "<<rest<<endl;
	vector<pair<int,int> >sons;//size,len
	for(auto p:g[x]){
		int to=p.first;if(to==par)continue;
		sons.push_back(make_pair(sz[to],p.second));
	}
	if(!sons.size())return;
	sort(sons.begin(),sons.end());
	reverse(sons.begin(),sons.end());
	int must_up=sz[x]-rest;
	if((sons[0].first-must_up)*2<=rest){
		for(auto p:g[x]){
			int to=p.first;if(to==par)continue;
			Max+=sz[to]*p.second;
			dfs_max(to,x,0);
		}
	}else{
		int unmatch=(sons[0].first-must_up-1);
		for(int i=1;i<sons.size();i++)unmatch-=sons[i].first;
		for(auto p:g[x]){
			int to=p.first;if(to==par)continue;
			if(sz[to]==sons[0].first&&p.second==sons[0].second){
				dfs_max(to,x,unmatch);
				Max+=(sz[to]-unmatch)*p.second;
			}else{
				dfs_max(to,x,0);
				Max+=sz[to]*p.second;
			}
		}
	}
}
signed main(){
	scanf("%I64d",&T);
	while(T--){
		scanf("%I64d",&n);n*=2;Min=0;Max=0;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<n;i++){
			int a,b,c;scanf("%I64d%I64d%I64d",&a,&b,&c);
			g[a].push_back(make_pair(b,c));
			g[b].push_back(make_pair(a,c));
		}
		dfs_sz(1,-1);
		//solve min
		dfs_min(1,-1);
		//solve max
		dfs_max(1,-1,n);
		printf("%I64d %I64d\n",Min,Max);
	}
	return 0;
}