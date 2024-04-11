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
int n,a[88];
vector<int>pos;
int dp[82][82][82*82];
int func(int x){
	return x*(x-1)/2;
}
void upd(int &x,int y){
	x=min(x,y);
}
int main(){
	cin>>n;
	pos.push_back(0);
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1)pos.push_back(i);
	}
	memset(dp,inf,sizeof dp);
	dp[0][0][0]=0;
	int cnt=pos.size()-1;
	for(int i=1;i<=cnt;i++){
		for(int lst=0;lst<=n;lst++){
			for(int sub=0;sub<=n*n;sub++)if(dp[i-1][lst][sub]<inf){
				for(int nxt=0;nxt+lst+1<=n;nxt++){
					upd(dp[i][lst+nxt+1][sub+func(nxt)],dp[i-1][lst][sub]+abs(lst+nxt+1-pos[i]));
				}
			}
		}
	}
	vector<ll>ans(n*n+1,-1e18);
	int fuck=n-cnt;
	for(int lst=0;lst<=n;lst++){
		for(int sub=0;sub<=n*n;sub++)if(dp[cnt][lst][sub]<inf){
			int sb=sub+func(n-lst),p=dp[cnt][lst][sub];
			ans[p]=max(ans[p],(ll)func(fuck)-sb);
		}
	}
//	cerr<<ans.size()<<" "<<n*(n-1)/2<<endl;
	for(int i=1;i<ans.size();i++)ans[i]=max(ans[i],ans[i-1]);
	for(int i=0;i<=n*(n-1)/2;i++)cout<<ans[i]<<" ";
	return 0;
}