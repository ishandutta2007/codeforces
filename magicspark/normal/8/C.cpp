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
int X,Y,n;
int x[24],y[24];
int dp[1<<24],pre[1<<24],lg[1<<24]; 
int f[24],g[24][24];
void solve(int mask){
	if(mask==0){
		cout<<0<<endl;
		return;
	}
	cout<<0<<" ";
	int msk=mask^pre[mask];
	if(__builtin_popcount(msk)==2){
		int x=lg[msk];msk-=(1<<x);int y=lg[msk];
		cout<<x+1<<" "<<y+1<<" ";
	}else{
		int x=lg[msk];cout<<x+1<<" ";
	}
	solve(pre[mask]);
}
void update(int pos,int pref,int v){
	if(v<dp[pos]){
		dp[pos]=v;pre[pos]=pref;
	}
}
int dist(int xa,int xb,int ya,int yb){
	return (xa-xb)*(xa-xb)+(ya-yb)*(ya-yb);
}
int main(){
	memset(dp,inf,sizeof dp);
	cin>>X>>Y;cin>>n;
	lg[1]=0;
	for(int i=2;i<(1<<n);i++)lg[i]=lg[i/2]+1;
	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i];
		f[i]=2*dist(X,x[i],Y,y[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			g[i][j]=f[i]/2+f[j]/2+dist(x[i],x[j],y[i],y[j]);
		}
	}
	dp[0]=0;
	for(int i=0;i<(1<<n)-1;i++){
		int inv=~i;
		int lowbit=lg[inv&-inv];
		update(i|(inv&-inv),i,dp[i]+f[lowbit]);
		for(int j=lowbit+1;j<n;j++){
			if(i&(1<<j))continue;
			update(i|(1<<lowbit)|(1<<j),i,dp[i]+g[lowbit][j]);
		}
	}
	cout<<dp[(1<<n)-1]<<endl;
	solve((1<<n)-1);
	return 0;
}