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
int T,n,w[100005],deg[100005];
vector<int>g[100005];
signed main(){
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>w[i];
		for(int i=1;i<=n;i++)g[i].clear(),deg[i]=0;
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
			deg[x]++;
			deg[y]++;
		}
		vector<pair<int,int> >obj;
		for(int i=1;i<=n;i++){
			obj.push_back(make_pair(w[i],deg[i]-1));
		}
		sort(obj.begin(),obj.end());
		int ans=0;
		for(int i=1;i<=n;i++)ans+=w[i];
		cout<<ans<<" ";
		for(int i=2;i<n;i++){
			while(!obj.back().second)obj.pop_back();
			ans+=obj.back().first;obj.back().second--;
			cout<<ans<<" ";
		}
		cout<<endl;
	}
	return 0;
}