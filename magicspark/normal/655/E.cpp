#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int dp[2000005];
int n,k,last[28],sb[28];
string s;
void add(int &x,int y){
	(x+=y)%=mod;
}
void sub(int &x,int y){
	x=(x-y%mod+mod)%mod;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>k>>s;
	s=" "+s;
	int m=s.size()-1;
	dp[0]=1;
	for(int i=1;i<=m;i++){
		add(dp[i],dp[i-1]*2);
		if(last[s[i]-'a']){
			sub(dp[i],sb[s[i]-'a']);
		}
		last[s[i]-'a']=i;
		add(sb[s[i]-'a'],dp[i]-dp[i-1]);
	}
	for(int i=m+1;i<=n+m;i++){
		add(dp[i],dp[i-1]*2);
		int mn=20051216,pos=-1;
		for(int j=0;j<k;j++){
			if(last[j]<mn){
				mn=last[j];
				pos=j;
			}
		}
		last[pos]=i;
		if(mn)sub(dp[i],sb[pos]);
		add(sb[pos],dp[i]-dp[i-1]);
	}
	cout<<dp[n+m]<<endl;
	return 0;
}