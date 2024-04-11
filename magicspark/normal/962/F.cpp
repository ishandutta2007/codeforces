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
int n,m;
vector<pair<int,int> >g[100005];
vector<int>t[100005],id[100005];
vector<int>add[100005],del[100005];
bool vis[100005];
int ans[100005];
int dep[100005];
void dfs(int x,int p){
	vis[x]=1;
	for(auto to:g[x])if(to.first!=p){
		if(!vis[to.first]){
			dep[to.first]=dep[x]+1;
			t[x].push_back(to.first);
			id[x].push_back(to.second);
			dfs(to.first,x);
		}else if(dep[to.first]<dep[x]){
			ans[to.second]=1;
			add[x].push_back(to.second);
			del[to.first].push_back(to.second);
		}
	}
}
set<int>s[100005];
set<int>st[100005];
void go(int x){
	pair<int,int>best(-1,-1);
	for(auto to:t[x]){
		go(to);best=max(best,make_pair((int)s[to].size(),to));
	}
	if(best.first!=-1)s[x].swap(s[best.second]),st[x].swap(st[best.second]);
	for(auto to:t[x]){
		if(to!=best.second){
			for(auto vv:s[to])s[x].insert(vv);
			for(auto vv:st[to])st[x].insert(vv);
		}
	}
	for(auto vv:del[x])s[x].erase(vv);
	for(auto vv:del[x])if(st[x].count(vv))st[x].erase(vv);
	for(auto vv:add[x])s[x].insert(vv),st[x].insert(vv);
	if(s[x].size()>1){
		for(auto vv:st[x]){
			cerr<<"erase:"<<vv<<endl;ans[vv]=0;
		}
		st[x].clear();
	}
//	cerr<<x<<" "<<s[x].size()<<" "<<st[x].size()<<endl;
}
int X[100005],Y[100005];
int f[100005];
void func(int x){
//	cerr<<x<<" "<<f[x]<<endl;
	int pos=0;
	for(auto to:t[x]){
		func(to);//cerr<<x<<" "<<to<<" "<<f[to]<<endl;
		f[x]+=f[to];if(f[to]==1)ans[id[x][pos]]=1;pos++;
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;X[i]=x;Y[i]=y;
		g[x].push_back(make_pair(y,i));
		g[y].push_back(make_pair(x,i));
	}
	vector<int>roots;
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			dfs(i,-1);
			roots.push_back(i);
		}
	}
	for(auto vv:roots)go(vv);
	for(int i=1;i<=m;i++){
		if(ans[i]){
			if(dep[X[i]]>dep[Y[i]]){
				f[X[i]]++;f[Y[i]]--;
			}else{
				f[Y[i]]++;f[X[i]]--;
			}
		}
	}
	for(auto vv:roots)func(vv);
	int cnt=0;
	for(int i=1;i<=m;i++)if(ans[i])cnt++;
	cout<<cnt<<endl;
	for(int i=1;i<=m;i++)if(ans[i])cout<<i<<" ";
	return 0;
}