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
int T,n;
string a,b;
set<int>s[33];
bool hv[20][20];
int par[22];
int find(int x){
	return x==par[x]?x:par[x]=find(par[x]);
}
bool same(int x,int y){
	return find(x)==find(y);
}
void merge(int x,int y){
	par[find(x)]=find(y);
}
int main(){
	cin>>T;
	while(T--){
		cin>>n;
		cin>>a>>b;
		bool can=1;
		for(int i=0;i<20;i++)s[i].clear();
		for(int i=0;i<n;i++){
			if(a[i]!=b[i]){
				if(a[i]>b[i]){
					can=0;
				}else s[a[i]-'a'].insert(b[i]-'a');
			}
		}
		int ans=0;
		if(can){
			memset(hv,0,sizeof hv);
			for(int i=0;i<20;i++)par[i]=i;
			for(int i=19;i>=0;i--){
				for(auto v:s[i]){
					if(!same(i,v))ans++;
					merge(i,v);
				}
			}
			cout<<ans<<endl;
		}else cout<<-1<<endl; 
	}
	return 0;
}