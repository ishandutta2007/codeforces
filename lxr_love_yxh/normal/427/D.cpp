/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#define int long long
#pragma comment("-Wl,--stack=1024000000")
using namespace std;
using namespace __gnu_pbds;
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
string s,t;
gp_hash_table<int,int>gs,gt;
const int mul=233;
int n,m;
int hsh1[5005],hsh2[5005],pw[5005];
int get_hash(int *f,int l,int r){
	int ret=f[r]-f[l-1]*pw[r-l+1]%mod;
	if(ret<0)ret+=mod;return ret;
}
bool good(int x,int y,int len){
	for(int i=0;i<=len;i++){
		if(s[x+i]!=t[y+i])return false;
	}
	return true;
}
bool check(int len){
	gs.clear();gt.clear();
	for(int i=0;i+len<s.size();i++)gs[get_hash(hsh1,i+1,i+len+1)]+=5006+i;
	for(int i=0;i+len<t.size();i++)gt[get_hash(hsh2,i+1,i+len+1)]+=5006+i;
	for(auto p:gs){
		if(p.second<=5005+5005&&gt.find(p.first)!=gt.end()&&gt[p.first]<=5005+5005&&good(p.second-5006,gt[p.first]-5006,len)){
			return 1;
		}
	}
	return 0;
}
signed main(){
	cin>>s>>t;n=s.size();m=t.size();
	pw[0]=1;
	for(int i=1;i<=5000;i++)pw[i]=1ll*pw[i-1]*mul%mod;
	for(int i=0;i<s.size();i++){
		hsh1[i+1]=(1ll*mul*hsh1[i]+s[i])%mod;
	}
	for(int i=0;i<t.size();i++){
		hsh2[i+1]=(1ll*mul*hsh2[i]+t[i])%mod;
	}
	for(int len=0;len<=min(n-1,m-1)&&1.0*clock()/CLOCKS_PER_SEC<0.98;len++){
		if(check(len)){
			cout<<len+1<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}