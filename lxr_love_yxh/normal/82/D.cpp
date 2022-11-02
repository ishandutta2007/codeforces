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
int n,a[1005],dp[1005][1005],p[1005][1005];
int solve(int i,int j){
	int mn,cur,pre;
	if(j>n)return a[i];
	if(j==n)return max(a[i],a[j]);
	if(dp[i][j])return dp[i][j];
	mn=solve(i,j+2)+max(a[j],a[j+1]);
	pre=1;
	cur=solve(j,j+2)+max(a[i],a[j+1]);
	if(cur<mn){
		mn=cur;pre=2;
	}
	cur=solve(j+1,j+2)+max(a[i],a[j]);
	if(cur<mn){
		mn=cur;pre=3;
	}
	dp[i][j]=mn;
	p[i][j]=pre;
	return mn;
} 
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	memset(dp,0,sizeof dp);
	int ans=solve(1,2);
	cout<<ans<<endl;
	int i=1,j=2;
	while(j<n){
		if(p[i][j]==1)cout<<j<<" "<<j+1<<endl;
		if(p[i][j]==2){
			cout<<i<<" "<<j+1<<endl;
			i=j;
		}
		if(p[i][j]==3){
			cout<<i<<" "<<j<<endl;
			i=j+1;
		}
		j+=2;
	}
	if(j==n)cout<<i<<" "<<j<<endl;
	else cout<<i<<endl;
	return 0;
}