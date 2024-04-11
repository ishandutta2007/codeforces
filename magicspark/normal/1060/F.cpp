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
int n,sz[55],ban;
vector<int>g[55];
double dp[52][52];
double tmp[52],tdp[52];
double C[52][52];
void dfs(int x,int par){
	sz[x]=1;dp[x][0]=1;
	for(auto to:g[x])if(to!=par){
		dfs(to,x);
		memset(tdp,0,sizeof tdp);
		memset(tmp,0,sizeof tmp);
		for(int j=0;j<sz[to];j++){
			for(int t=0;t<=sz[to];t++){
				if(j<t)tmp[t]+=dp[to][j]*0.5;
				else tmp[t]+=dp[to][t];
			}
		}
		for(int a=0;a<sz[x];a++){
			for(int b=0;b<=sz[to];b++){
				tdp[a+b]+=dp[x][a]*tmp[b]*C[a+b][a]*C[sz[x]-a+sz[to]-b-1][sz[x]-a-1];
			}
		}
		memcpy(dp[x],tdp,sizeof dp[x]);
		sz[x]+=sz[to];
	}
}
double pw2[55];
void solve(int x){
	memset(dp,0,sizeof dp);
	ban=x;dfs(x,0);
	auto ans=dp[x][n-1];
	for(int i=1;i<n;i++)ans/=i;
	printf("%.8lf\n",ans);
}
int main(){
	for(int i=0;i<52;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1]);
		}
	}
	cin>>n;
	for(int i=1;i<n;i++){
		int x,y;cin>>x>>y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
//	solve(4);return 0;
	for(int i=1;i<=n;i++)solve(i);
	return 0;
}