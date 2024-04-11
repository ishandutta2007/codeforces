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
int n;
int a[200005];
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cout<<1<<" "<<n<<endl;
	for(int i=1;i<=n;i++){
		//divisible by (n-1)
		int rem=n==1?0:a[i]%(n-1);
		int add=n*(n-1-rem);
		cout<<add<<" ";
		a[i]+=add;
	}
	cout<<endl;
	cout<<1<<" "<<max(n-1,1ll)<<endl;
	for(int i=1;i<=max(n-1,1ll);i++){
		cout<<-a[i]<<" ";a[i]=0;
	}
	cout<<endl;
	cout<<n<<" "<<n<<endl;
	cout<<-a[n]<<endl;
	return 0;
}