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
int a[100005];
int main(){
	cin>>T;
	while(T--){
		int n;cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		int high=30;
		while(1){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]&(1<<high))cnt++;
			}
			if(cnt%2==0)high--;
			if(cnt%2==1||high==-1)break;
		}
		if(high==-1){
			puts("DRAW");
			continue;
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]&(1<<high))cnt++;
		}
		cnt%=4;
		if(cnt==1){
			puts("WIN");
		}else{
			if((n-cnt)%2)puts("WIN");
			else puts("LOSE");
		}
	}
	return 0;
}