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
int f[35][35],cnt[35];
int t,d,m;
void solve(){
	memset(f,0,sizeof f);
	//i step,high bit j
	const int n=33;
	for(int j=1;j<31;j++){
		f[1][j]=min(d+1,1ll<<j)-(1ll<<(j-1));
		f[1][j]=max(0ll,f[1][j]);
		f[1][j]%=m;
		cnt[j]=f[1][j];
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<31;j++){
			for(int nxt=j+1;nxt<31;nxt++){
				f[i+1][nxt]+=f[i][j]*cnt[nxt]%m;
				f[i+1][nxt]%=m;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++){
		for(int j=0;j<31;j++){
			ans+=f[i][j];ans%=m;
		}
	}
	cout<<ans<<endl;
}
signed main(){
	cin>>t;
	while(t--){
		cin>>d>>m;
		solve();
	}
	return 0;
}