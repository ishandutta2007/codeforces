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
int t,n;
string s;
int dp[100005][2][2];
int main(){
	cin>>t;
	while(t--){
		cin>>s;n=s.size();s=" "+s;
		if(n==1){
			cout<<0<<endl;
			continue;
		}
		for(int i=0;i<2;i++){
			for(int j=0;j<2;j++){
				if(i==0&&j==0&&s[1]==s[2])dp[2][i][j]=inf;
				else dp[2][i][j]=i+j;
			}
		}
		if(n==2){
			if(s[1]==s[2])cout<<1<<endl;
			else cout<<0<<endl;
			continue;
		}
		int ans=inf;
		for(int i=3;i<=n;i++){
			for(int l1=0;l1<2;l1++)for(int l2=0;l2<2;l2++)dp[i][l1][l2]=inf;
			for(int l1=0;l1<2;l1++){
				for(int l2=0;l2<2;l2++){
					for(int cur=0;cur<2;cur++){
						if(l1==0&&cur==0&&s[i-2]==s[i])continue;
						if(l2==0&&cur==0&&s[i-1]==s[i])continue;
						dp[i][l2][cur]=min(dp[i][l2][cur],dp[i-1][l1][l2]+cur);
						if(i==n)ans=min(ans,dp[i][l2][cur]);
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}