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
int t,n,a[200005],b[200005],tot,ban;
vector<int>g[200005];
int vis[200005];
bool go(int x,int tar){
	if(x==tar)return true;
//	cerr<<x<<" "<<tar<<" "<<vis[1]<<endl;
	vis[x]=1;
	for(auto to:g[x]){
		if(vis[to]==1)return false;
		if(!vis[to]&&!go(to,tar))return false;
	}
	cerr<<x<<endl;
	vis[x]=2;
	return true;
}
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;map<int,int>cnt;
		for(int i=1;i<=n;i++)g[i].clear();
		for(int i=1;i<=n;i++)cin>>a[i],cnt[a[i]]++;
		for(int i=1;i<=n;i++)cin>>b[i],g[a[i]].push_back(b[i]);
		int ans=n;tot=0;
		for(auto p:cnt)ans=min(ans,n-p.second);
		int pos=1;
		for(int i=1;i<=n;i++)if(cnt[i]>cnt[pos])pos=i;
		ban=pos;
		for(int i=1;i<=n;i++)vis[i]=0;
		bool can=1;
		for(int i=1;i<=n;i++)if(i!=ban&&!vis[i]){
			if(!go(i,ban)){
				can=0;break;
			}
		}
		puts(can?"AC":"WA");
	}
	return 0;
}