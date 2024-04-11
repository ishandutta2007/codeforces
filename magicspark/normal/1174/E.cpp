#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
//Fmax(x)=log2(x)
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,dp[1000005][22][2];
int lg2[1000005],fact[1000005];
int ans=0;
void add(int &x,int y){
	(x+=y)%=mod;
}
inline int calc(int x,int y,int z){
	return n/(1<<x)/(y==0?1:3)-z;
}
int main(){
	cin>>n;if(n==1)return puts("1")&0;
	lg2[1]=0;fact[1]=1;
	for(int i=2;i<=1000000;i++)lg2[i]=lg2[i/2]+1,fact[i]=(ll)fact[i-1]*i%mod;
	dp[1][lg2[n]][0]=1;
	if(n>=(1<<lg2[n]-1)*3)dp[1][lg2[n]-1][1]=1;
	for(int i=1;i<n;i++){
		for(int j=lg2[n];j>=0;j--){
			for(int k=0;k<2;k++){
				add(dp[i+1][j][k],(ll)dp[i][j][k]*calc(j,k,i)%mod);
				if(j)add(dp[i+1][j-1][k],(ll)dp[i][j][k]*(calc(j-1,k,i)-calc(j,k,i))%mod);
				if(k)add(dp[i+1][j][k-1],(ll)dp[i][j][k]*(calc(j,k-1,i)-calc(j,k,i))%mod);
			}
		}
	}
	cout<<dp[n][0][0]<<endl;
	return 0;
}