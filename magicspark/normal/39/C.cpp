#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
map<int,int>mp;
vector<int>g[4005];
int v[4005][4005];
vector<pair<int,int> >vec;
int l[2005],r[2005];
int dp[4005][4005];
int get_dp(int l,int r){
	if(l>=r)return dp[l][r]=0;
	int ret=dp[l][r];
	if(ret!=-1)return ret;
	ret=get_dp(l,r-1);
	for(int i=0;i<g[r].size();i++){
		if(g[r][i]<=l)break;
		ret=max(ret,get_dp(l,g[r][i])+get_dp(g[r][i],r));
	}
	ret+=(v[l][r]>0);
//	cerr<<l<<" "<<r<<" "<<ret<<endl;
	return dp[l][r]=ret;
}
vector<int>answer;
void get_ans(int l,int r){
	if(v[l][r])answer.push_back(v[l][r]);
	for(int k=l+1;k<r;k++)
		if(get_dp(l,k)+get_dp(k,r)+(v[l][r]>0)==get_dp(l,r)){
			get_ans(l,k);get_ans(k,r);
			return;
		}
}
int main(){
	memset(dp,-1,sizeof dp);
	cin>>n;
	for(int i=1;i<=n;i++){
		int c_,r_;
		cin>>c_>>r_;
		l[i]=(c_-r_),r[i]=(c_+r_);
		mp[l[i]];mp[r[i]];
	}
	int cnt=0;
	for(auto &p:mp)p.second=++cnt;
	for(int i=1;i<=n;i++)l[i]=mp[l[i]],r[i]=mp[r[i]],g[r[i]].push_back(l[i]),v[l[i]][r[i]]=i;
	for(int i=1;i<=cnt;i++)sort(g[i].begin(),g[i].end()),reverse(g[i].begin(),g[i].end());
	int ans=get_dp(1,cnt);
	cout<<ans<<endl;
	get_ans(1,cnt);
	for(auto x:answer)cout<<x<<" ";
	return 0;
}