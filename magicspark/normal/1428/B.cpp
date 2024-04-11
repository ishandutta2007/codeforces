/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
//#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
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
int T;
string s;
int par[300005];
int find(int x){
	return x==par[x]?x:par[x]=find(par[x]);
}
int main(){
	ios::sync_with_stdio(0);
	cin>>T;
	while(T--){
		int n;cin>>n;cin>>s;
		for(int i=0;i<n;i++)par[i]=i;
		set<char>st;
		for(int i=0;i<n;i++){
			int nxt=(i+1)%n;
			if(s[i]=='-')par[find(i)]=find(nxt);
			else st.insert(s[i]);
		}
		map<int,int>cnt;
		if(st.size()<2){
			cout<<n<<endl;
			continue;
		}
		for(int i=0;i<n;i++)cnt[find(i)]++;
		int ans=0;
		for(auto p:cnt){
			if(p.second>1)ans+=p.second;
		}
		cout<<ans<<endl;
	}
	return 0;
}