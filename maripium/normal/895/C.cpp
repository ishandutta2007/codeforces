#include<bits/stdc++.h>

using namespace std;
#define ll long long

const ll mod=1e9+7;
int n,x;
int dem[75];
int dp[72][1<<19];
ll pmask[75];
ll ipow[100005];
ll snt[19]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67};
void inp(){
	for(int i=2;i<=70;++i){
		int j=0,x=i;
		pmask[i]=0;
		while(j<19){
			while(x%snt[j]==0){
				x/=snt[j];
				pmask[i]^=(1<<j);
			}
			j++;
		}
	}	
}
int main(){
	inp();
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>x;
		dem[x]++;
	}
	ipow[0]=1;
	for(int i=1;i<100005;++i)
		ipow[i]=(ipow[i-1]<<1)%mod;
	dp[0][0]=1;
	for(int i=1;i<=70;++i){
		for(int j=0;j<(1<<19);++j){
			if(dem[i]==0)
				dp[i][j]=dp[i-1][j];
			else{
				int mask=j^pmask[i];
				dp[i][mask]+=(dp[i-1][j]*ipow[dem[i]-1])%mod;
				dp[i][mask]%=mod;
				dp[i][j]+=(dp[i-1][j]*ipow[dem[i]-1])%mod;
				dp[i][j]%=mod;
			}	
		}
	}
	cout<<(dp[70][0] - 1 + mod) % mod;
}