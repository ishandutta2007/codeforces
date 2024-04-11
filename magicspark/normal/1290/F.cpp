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
const int mod=998244353;
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
int n,m,x[55],y[55];
int dp[31][42][42][42][42];
int dfs(int lvl,int px,int nx,int py,int ny){
	if(max(px,nx)>40){
		int sub=max(px,nx)-40;
		px-=sub;nx-=sub;
		if(px<0||nx<0)return 0;
	}
	if(max(py,ny)>40){
		int sub=max(py,ny)-40;
		py-=sub;ny-=sub;
		if(py<0||ny<0)return 0;
	}
	if(lvl==-1)return px==nx&&py==ny;
	if(~dp[lvl][px][nx][py][ny])return dp[lvl][px][nx][py][ny];
	int ret=0;
	for(int i=0;i<(1<<n);i++){
		int a=px,b=nx,c=py,d=ny;
		for(int j=0;j<n;j++)if(i&(1<<j)){
			if(x[j]>0)a-=x[j];
			else b-=abs(x[j]);
			if(y[j]>0)c-=y[j];
			else d-=abs(y[j]);
		}
		if(m&(1<<lvl)){a++;b++;c++;d++;}
		if(a<0||b<0||c<0||d<0)continue;
		ret=(ret+dfs(lvl-1,a<<1,b<<1,c<<1,d<<1))%mod; 
	}
	return dp[lvl][px][nx][py][ny]=ret;
}
int main(){
	memset(dp,-1,sizeof dp);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>x[i]>>y[i];
	cout<<(dfs(30,0,0,0,0)-1+mod)%mod<<endl;
	return 0;
}