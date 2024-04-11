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
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
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
vector<int>big,small;
int n,m,q;
vector<pair<int,int> >edge[100005];
int cnt[100005];
#define MAGIC 333
map<pair<int,int>,int>ans;
vector<int>vec[100005];
pair<int,int>qry[100005];
int par[100005];
int find(int x){
	return x==par[x]?x:par[x]=find(par[x]);
}
void merge(int x,int y){
	par[find(x)]=find(y);
}
void solve_small(int c){
	set<int>V;
	for(auto p:edge[c]){
		V.insert(p.first);
		V.insert(p.second);
		merge(p.first,p.second);
	}
	set<int>have;
	for(auto x:V){
		have.insert(find(x));
		vec[find(x)].push_back(x);
	}
	for(auto x:have){
		for(auto y:vec[x]){
			for(auto z:vec[x]){
				if(y<z){
					ans[make_pair(y,z)]++;
				}
			}
		}
	}
	for(auto x:V){
		vec[find(x)].clear();
	}
	for(auto x:V)par[x]=x;
}
int res[100005];
void solve_big(int c){
	for(int i=1;i<=n;i++)par[i]=i;
	for(auto p:edge[c]){
		merge(p.first,p.second);
	}
	for(int i=1;i<=q;i++){
		if(find(qry[i].first)==find(qry[i].second))res[i]++;
	}
	for(int i=1;i<=n;i++)par[i]=i;
}
int main(){
	for(int i=1;i<=1e5;i++)par[i]=i;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);
		edge[c].push_back(make_pair(a,b));
		cnt[c]++;
	}
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&qry[i].first,&qry[i].second);
	}
	for(int i=1;i<=m;i++){
		if(cnt[i]>=MAGIC){
			solve_big(i);
		}else{
			solve_small(i);
		}
	}
	for(int i=1;i<=q;i++){
		printf("%d\n",res[i]+ans[make_pair(min(qry[i].first,qry[i].second),max(qry[i].first,qry[i].second))]);
	}
	return 0;
}