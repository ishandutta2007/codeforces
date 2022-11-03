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
#define int long long
//#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-9;
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
int t,n,a[200005],par[200005];
bool check_min(){
	int sum=(n-1)*a[1];
	for(int i=2;i<=n;i++)sum+=a[i];
	return sum<=0;
}
bool check_max(){
	int sum=(n-1)*a[n];
	for(int i=1;i<n;i++)sum+=a[i];
	return sum>=0;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		if(!check_min()||!check_max()){
			cout<<"INF"<<endl;
			continue;
		}
		int cx=0,cc=0,ans=-9e18;
		for(int i=2;i<=n;i++)cx+=(a[1]+a[i]),cc+=a[1]*a[i];
		for(int i=1;i<=n;i++){
			//a[i-1]+t<=0 a[i]+t>=0
			if(cx>=0){
				int rb=-a[i-1];
				ans=max(ans,rb*cx+cc);
			}else{
				int lb=-a[i];
				ans=max(ans,lb*cx+cc);
			}
			if(i>=2){
				cx-=a[1]+a[i];
				cc-=a[1]*a[i];
				cx+=a[n]+a[i];
				cc+=a[n]*a[i];
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}