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
int t,n,a[300005];
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		map<int,int>cnt;
		for(int i=1;i<=n;i++)cnt[a[i]]++;
		int pos=0;
		for(int i=1;i<=n+1;i++)if(cnt[i]!=1){
			if(cnt[i]>1)pos=i;
			else pos=i-1;
			break;
		}
		if(pos==n)putchar('1');
		else putchar('0');
		int l=1,r=n;
		for(int i=1;i<=pos;i++){
			if(a[l]==i){
				l++;continue;
			}
			if(a[r]==i){
				r--;continue;
			}
			pos=i;break;
		}
		for(int i=n-1;i>=1;i--)if(i<=pos)putchar('1');else putchar('0');
		putchar('\n');
	}
	return 0;
}