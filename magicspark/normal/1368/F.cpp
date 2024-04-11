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
int n;
int pre(int x){
	if(x==1)return n;
	return x-1;
}
int nxt(int x){
	if(x==n)return 1;
	return x+1;
}
int block,ans=-1;
set<int>all;
int main(){
	cin>>n;
	if(n<=3){
		puts("0");
		return 0;
	}
	for(int i=2;i<=n;i++){
		if(n-i-(n-1)/i>ans){
			ans=n-i-(n-1)/i;
			block=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(i%block!=1)all.insert(i);
	}
	while(all.size()){
		vector<int>vec;
		for(auto v:all){
			vec.push_back(v);
			if(vec.size()==block)break;
		}
		for(auto v:vec)all.erase(v);
		cout<<vec.size()<<" ";
		for(auto v:vec)cout<<v<<" ";
		int x;cin>>x;
		if(!all.size())break;
		int tot=block;
		for(int i=x;tot--;i=nxt(i)){
			if(i%block!=1)all.insert(i);
		}
	}
	return printf("0\n")&0;
}