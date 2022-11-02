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
#define int long long
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
int dp[705][705][3][3];
string s;
int L[705],R[705];
int dfs(int l,int r,int banl,int banr){
	if(~dp[l][r][banl][banr])return dp[l][r][banl][banr];
	if(l>r)return dp[l][r][banl][banr]=(banl==banr?0:1);
	int mid=R[l];
	if(mid==r){
		int ret=0;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(banl&&i==banl)continue;
				if(banr&&j==banr)continue;
				if(i&&j)continue;
				if(i==0&&j==0)continue;
				(ret+=dfs(l+1,r-1,i,j))%=mod;
			}
		}
		return dp[l][r][banl][banr]=ret;
	}else{
		int ret=0;
		for(int i=0;i<3;i++){
			for(int j=0;j<3;j++){
				if(banl&&i==banl)continue;
				if(i&&j)continue;
				if(i==0&&j==0)continue;
				(ret+=dfs(l+1,mid-1,i,j)*dfs(mid+1,r,j,banr)%mod)%=mod;
			}
		}
		return dp[l][r][banl][banr]=ret;
	}
}
signed main(){
	memset(dp,-1,sizeof dp);
	cin>>s;
	stack<int>stk;
	s=" "+s;
	for(int i=1;i<s.size();i++){
		if(s[i]=='(')stk.push(i);
		else{
			L[i]=stk.top();
			R[stk.top()]=i;
			stk.pop();
		}
	}
	cout<<dfs(1,(int)s.size()-1,0,0)<<endl;
	return 0;
}