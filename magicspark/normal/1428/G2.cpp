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
int k,q,n;
int f[6],mem[6][1000005];
int func(int x){
	if((x+8)/9==k){
		if(x%3==0)return x/3;
		else return x/9*3;
	}else{
		return x/3;
	}
}
int dfs(int lvl,int n){
	if(~mem[lvl][n])return mem[lvl][n];
	if(lvl==6)return 0;
	int ret=0,tk=n%10;
	for(int i=0;i*10+tk<=k*9&&i<=200&&n/10>=i;i++){
		ret=max(ret,dfs(lvl+1,n/10-i)+f[lvl]*func((i*10+tk)));
	}
	int mx=min(n/10,(k*9-tk)/10);
	for(int i=mx;i>=max(0ll,mx-200);i--){
		ret=max(ret,dfs(lvl+1,n/10-i)+f[lvl]*func((i*10+tk)));
	}
	return mem[lvl][n]=ret;
}
signed main(){
	cin>>k;
	for(int i=0;i<6;i++)cin>>f[i];
	cin>>q;
	memset(mem,-1,sizeof mem);
	while(cin>>n) 
	cout<<dfs(0,n)<<endl;
	return 0;
}