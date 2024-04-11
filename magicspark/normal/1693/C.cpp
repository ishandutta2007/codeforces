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
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1e9+7;
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
vector<int>g[200005];
int dist[200005],deg[200005];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;cin>>x>>y;
		g[y].push_back(x);
		deg[x]++;
	}
	memset(dist,inf,sizeof dist);
	dist[n]=0;
	set<pair<int,int> >s;
	s.insert(make_pair(0,n));
	while(!s.empty()){
		int x=s.begin()->second,len=s.begin()->first;s.erase(s.begin());
		if(len!=dist[x])continue;
		for(auto to:g[x]){
			if(dist[to]>dist[x]+deg[to]){
				dist[to]=dist[x]+deg[to];
				s.insert(make_pair(dist[to],to));
			}
			deg[to]--;
		}
//		for(auto to:g[x])deg[to]--;
	}
	cout<<dist[1]<<endl;
	return 0;
}