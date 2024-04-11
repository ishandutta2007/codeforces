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
int T,n,a[200005],ans[200005];
vector<int>buc[200005];
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		map<int,int>cnt;
		for(int i=1;i<=n;i++)buc[i].clear();
		for(int i=1;i<=n;i++)cin>>a[i],cnt[a[i]]++,buc[a[i]].push_back(i);
		while(!cnt.empty()){
			vector<int>all;
			for(auto p:cnt){
				all.push_back(p.first);
			}
			for(auto u:all){
			cnt[u]--;
			if(!cnt[u])cnt.erase(cnt.find(u));
			}
			for(int i=0;i<all.size();i++){
				int x=buc[all[i]].back(),y=buc[all[(i+1)%all.size()]].back();
				ans[x]=a[y];
			}
			for(auto u:all)buc[u].pop_back();
		}
		for(int i=1;i<=n;i++)cout<<ans[i]<<" ";cout<<endl;
	}
	return 0;
}