/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
string s[55];
int dp[55][55][55][55];
int dfs(int x1,int y1,int x2,int y2){
	if(~dp[x1][y1][x2][y2])return dp[x1][y1][x2][y2];
	int ret=max(x2-x1+1,y2-y1+1);
	for(int cut_x=x1;cut_x<x2;cut_x++){
		ret=min(ret,dfs(x1,y1,cut_x,y2)+dfs(cut_x+1,y1,x2,y2));
	}
	for(int cut_y=y1;cut_y<y2;cut_y++){
		ret=min(ret,dfs(x1,y1,x2,cut_y)+dfs(x1,cut_y+1,x2,y2));
	}
	return dp[x1][y1][x2][y2]=ret;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];s[i]=" "+s[i];
	}
	memset(dp,-1,sizeof dp);
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)dp[i][j][i][j]=s[i][j]=='#';
	cout<<dfs(1,1,n,n)<<endl;
	return 0;
}