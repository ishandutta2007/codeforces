#include<bits/stdc++.h>
#define int long long
const int N=1000050,mod=998244353;
using namespace std;

int jc[N],ij[N],iv[N]; 
int C(int n,int m){
    if(n<m)return 0;
    return jc[n]*ij[m]%mod*ij[n-m]%mod;
}
void init(){
    iv[0]=jc[0]=ij[0]=iv[1]=1;
    for(int i=2;i<N;i++)
        iv[i]=mod-(mod/i)*iv[mod%i]%mod;
    for(int i=1;i<N;i++)
        jc[i]=jc[i-1]*i%mod,ij[i]=ij[i-1]*iv[i]%mod;
}

int n;
int dp[N];

void solve(){
	cin>>n;
	init();
	int s=0;
	for(int i=n;i>=2;i--){
		dp[i]=jc[n-i]*jc[i-2]%mod*(i-1)%mod*C(n/2,i-1);
		dp[i]-=s*iv[i]%mod;
		dp[i]%=mod;
		s=(s+dp[i])%mod; 
	}
	dp[1]=jc[n-1];
	dp[1]-=s;
	dp[1]%=mod;
	for(int i=1;i<=n;i++)
		cout<<(dp[i]%mod+mod)%mod<<' ';
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;//cin>>_T;
	while(_T--)solve();
	
}