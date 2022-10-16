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
const int mod=998244353;
typedef long long ll;
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int dp[505][505];
int n,c[505],m;
int dfs(int l,int r){
	if(~dp[l][r])return dp[l][r];
	if(l>=r){
		return dp[l][r]=1;
	}
	int ret=0,mn=inf,pos;
	for(int i=l;i<=r;i++){
		if(c[i]<mn){
			mn=c[i];
			pos=i;
		}
	}
	int left=0,right=0;
//	cerr<<l<<" "<<r<<" "<<pos<<endl;
	for(int i=l;i<=pos;i++){
		//where the left range of the max value is
//		cerr<<"left:"<<l<<" "<<r<<" to:"<<l<<" "<<i-1<<endl;
//		cerr<<"left:"<<l<<" "<<r<<" to:"<<i<<" "<<pos-1<<endl;
//		system("pause");
		left=left+(ll)dfs(l,i-1)*dfs(i,pos-1)%mod;
		if(left>=mod)left-=mod;
	}
	for(int i=pos;i<=r;i++){
		//where the right range of the max value is
//		cerr<<"right:"<<l<<" "<<r<<" to:"<<pos+1<<" "<<i<<endl;
//		cerr<<"right:"<<l<<" "<<r<<" to:"<<i+1<<" "<<r<<endl;
//		system("pause");
		right=right+(ll)dfs(pos+1,i)*dfs(i+1,r)%mod;
		if(right>=mod)right-=mod;
	}
//	cerr<<l<<" "<<r<<" "<<left<<" "<<right<<endl;
	return dp[l][r]=(ll)left*right%mod;
}
signed main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	memset(dp,-1,sizeof dp);
	cout<<dfs(1,n)<<endl;
	return 0;
}