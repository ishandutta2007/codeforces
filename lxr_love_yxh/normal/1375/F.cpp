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
int a[4],b[4];
signed main(){
	cin>>a[1]>>a[2]>>a[3];
	for(int i=1;i<=3;i++)b[i]=a[i];
	sort(b+1,b+3+1);
	printf("First\n");
	while(1){
	printf("%I64d\n",(b[3]-b[1])+(b[3]-b[2]));
	fflush(stdout);
	int x;cin>>x;
	if(x==0)return 0;
	a[x]+=(b[3]-b[1])+(b[3]-b[2]);
	for(int i=1;i<=3;i++)b[i]=a[i];
	sort(b+1,b+3+1);
	if(b[3]-b[2]==b[2]-b[1]&&a[x]==b[3]){
		printf("%I64d\n",b[3]-b[2]);
		fflush(stdout);
		return 0;
	}
	}
	return 0;
}