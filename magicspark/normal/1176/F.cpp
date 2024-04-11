//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#define int long long
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=1e18;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int dp[200005][11];
int n;
inline void upd(int &x,int y){
	if(y>x)x=y;
}
void update_dp(int x){
	int k;cin>>k;
	vector<int>v[4]={};
	while(k--){
		int cost,dmg;
		cin>>cost>>dmg;
		v[cost].push_back(dmg);
	}
	for(int i=1;i<=3;i++)sort(v[i].begin(),v[i].end()),reverse(v[i].begin(),v[i].end());
	for(int i=0;i<10;i++){
		//1+1+1
		if((int)v[1].size()>=3){
			if(i<7)upd(dp[x+1][i+3],dp[x][i]+v[1][0]+v[1][1]+v[1][2]);
			else upd(dp[x+1][i-7],dp[x][i]+v[1][0]*2ll+v[1][1]+v[1][2]);
		}
		//2+1
		if((int)v[2].size()&&(int)v[1].size()){
			if(i<8)upd(dp[x+1][i+2],dp[x][i]+v[2][0]+v[1][0]);
			else upd(dp[x+1][i-8],dp[x][i]+v[2][0]+v[1][0]+max(v[2][0],v[1][0]));
		}
		//3
		if((int)v[3].size()){
			if(i<9)upd(dp[x+1][i+1],dp[x][i]+v[3][0]);
			else upd(dp[x+1][0],dp[x][i]+v[3][0]*2ll);
		}
		//2
		if((int)v[2].size()){
			if(i<9)upd(dp[x+1][i+1],dp[x][i]+v[2][0]);
			else upd(dp[x+1][0],dp[x][i]+v[2][0]*2ll);
		}
		//1
		if((int)v[1].size()){
			if(i<9)upd(dp[x+1][i+1],dp[x][i]+v[1][0]);
			else upd(dp[x+1][0],dp[x][i]+v[1][0]*2ll);
		}
		//1+1
		if((int)v[1].size()>=2){
			if(i<8)upd(dp[x+1][i+2],dp[x][i]+v[1][0]+v[1][1]);
			else upd(dp[x+1][i-8],dp[x][i]+v[1][0]*2ll+v[1][1]);
		}
		//nothing
		upd(dp[x+1][i],dp[x][i]);
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<=10;i++)for(int j=0;j<=n;j++)dp[j][i]=-inf;
	dp[0][0]=0;
	for(int i=1;i<=n;i++){
		update_dp(i-1);
	}
	cout<<*max_element(dp[n],dp[n+1])<<endl;
	return 0;
}