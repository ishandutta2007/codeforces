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
int n,m,q,ans=0;
multiset<int>s[200005];
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int x,y;scanf("%d%d",&x,&y);
		if(x>y)swap(x,y);
		s[x].insert(y);
	}
	for(int i=1;i<=n;i++)ans+=(s[i].size()==0);
	scanf("%d",&q);
	while(q--){
		int tp;scanf("%d",&tp);
		if(tp==1){
			int x,y;scanf("%d%d",&x,&y);
			if(x>y)swap(x,y);
			s[x].insert(y);
			if(s[x].size()==1)ans--;
		}
		if(tp==2){
			int x,y;scanf("%d%d",&x,&y);
			if(x>y)swap(x,y);
			s[x].erase(s[x].find(y));
			if(s[x].size()==0)ans++;
		}
		if(tp==3){
			printf("%d\n",ans);
		}
	}
	return 0;
}