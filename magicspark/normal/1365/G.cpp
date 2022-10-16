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
int n,id[1<<13],got[15],tot;
vector<int>hv[15];
signed main(){
	cin>>n;
	for(int i=0;i<(1<<13);i++){
		if(__builtin_popcount(i)==6){
			id[++tot]=i;
			for(int j=0;j<13;j++){
				if(i&(1<<j))hv[j].push_back(tot);
			}
			if(tot==n)break;
		}
	}
	for(int i=0;i<13;i++){
		if(!hv[i].size())continue;
		cout<<"? "<<hv[i].size()<<" ";
		for(auto v:hv[i]){
			cout<<v<<" ";
		}
		fflush(stdout);
		int x;cin>>x;
		got[i]=x;
	}
	cout<<"! ";
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=0;j<13;j++)if(id[i]&(1<<j));else{
			ans|=got[j];
		}
		cout<<ans<<" ";
	}
//	fflush(stdout); 
	return 0;
}