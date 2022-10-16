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
bool win(int s,int e){
	if(e&1){return !(s&1);}
	if(s*2>e){return (e-s)%2;}
	if(s*2>e/2)return 1;
	return win(s,e/4); 
}
bool lose(int s,int e){
	if(s*2>e)return 1;
	return win(s,e/2);
}
int n;
int s[100005],t[100005],w[100005],l[100005];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i]>>t[i];
	l[0]=1;
	cerr<<"-----"<<endl;
	for(int i=0;i<n;i++){
		cerr<<w[i]<<" "<<l[i]<<endl;
		if(l[i]){
			if(win(s[i+1],t[i+1]))w[i+1]=1;
			if(lose(s[i+1],t[i+1]))l[i+1]=1;
		}
		if(w[i]){
			if(!win(s[i+1],t[i+1]))w[i+1]=1;
			if(!lose(s[i+1],t[i+1]))l[i+1]=1;
		}
	}
	cout<<w[n]<<" "<<l[n]<<endl;
	return 0;
}