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
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int query(string s){
	cout<<s<<endl;
	fflush(stdout);
	int x;cin>>x;
	if(x==0)exit(0);
	return x;
}
int main(){
	string s="";
	for(int i=0;i<300;i++)s+='a';
	int sza=300-query(s);
	for(int i=0;i<300;i++)s[i]='b';
	int szb=300-query(s);
	cerr<<sza<<" "<<szb<<endl;
	if(sza==0){
		s="";
		for(int i=0;i<szb;i++){
			s+='b';
		}
		query(s);return 0;
	}else if(szb==0){
		s="";
		for(int i=0;i<sza;i++){
			s+='a';
		}
		query(s);return 0;
	}
	string ans="";
	for(int i=0;i<sza+szb;i++)ans.push_back('a');
	int sz=sza+szb;
	for(int i=0;i<sz-1;i++){
		ans[i]='b';
		if(query(ans)>=szb){
			ans[i]='a';
		}else{
			szb--;
		}
	}
	if(szb)ans.back()='b';
	query(ans);
	return 0;
}