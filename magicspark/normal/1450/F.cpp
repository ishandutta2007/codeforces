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
int t,n,p[100005],cnt[100005];
vector<vector<int> >all;
vector<int>gen(int l,int r){
	vector<int>ret;
	for(int i=l;i<=r;i++){
		ret.push_back(p[i]);
	}
	return ret;
}
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>p[i];
		for(int i=1;i<=n;i++)cnt[i]=0;
		for(int i=1;i<=n;i++)cnt[p[i]]++;
		int mx=*max_element(cnt+1,cnt+n+1);
		if(mx*2-1>n){
			puts("-1");
			continue;
		}
		all.clear();
		p[0]=p[n+1]=0;
		int prv=1;
		for(int i=1;i<=n;i++){
			if(p[i]==p[i+1]||i+1==n+1){
				all.push_back(gen(prv,i));
				prv=i+1;
			}
		}
		int ans=all.size()-1;
		map<int,int>mp;
		for(auto v:all){
			mp[v[0]]++;
			mp[v.back()]++;
		}
		mx=0;
		for(auto p:mp)mx=max(mx,p.second);
		cerr<<ans<<" "<<mx<<" "<<all.size()<<endl;
		ans=max(ans,mx-2);
		cout<<ans<<endl;
	}
	return 0;
}