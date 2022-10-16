#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
int modpow(int x,int y,int md){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n;
string s;
int dp[505][505];

int main(){
	cin>>n>>s;
	for(int i=0;i<n;i++)for(int j=i;j<n;j++)dp[i][j]=inf;
	for(int len=0;len<n;len++)
		for(int i=0;i+len<n;i++){
			int j=i+len;
			if(i==j)dp[i][j]=1;
			else{
				for(int k=i;k<=j;k++)if(s[j]==s[k])dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j-1]);
				for(int k=i;k<=j;k++)dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]);
			}
		}
	cout<<dp[0][n-1]<<endl;
	return 0;
}