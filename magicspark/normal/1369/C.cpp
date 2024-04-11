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
int T,n,k;
int a[200005],w[200005];
int main(){
	cin>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=k;i++)cin>>w[i];
		sort(w+1,w+k+1);
		sort(a+1,a+n+1);
		ll ans=0,pos=1,cur=n;
		for(int i=n;i>n-k;i--)ans+=a[i];
		for(int i=k;i>=1;i--){
			w[i]--;
			if(w[i]){
				ans+=a[pos];
				cerr<<a[pos]<<endl;
				pos+=w[i];
			}else{
				cerr<<a[cur]<<endl;
				ans+=a[cur--];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}