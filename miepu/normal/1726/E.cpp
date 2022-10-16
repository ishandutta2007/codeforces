#include<bits/stdc++.h>
#define int long long
const int N=1000005,mod=998244353;
using namespace std;

int dp[N],g[N];

int jc[N],ij[N],iv[N]; 
int C(int n,int m){
    if(n<m||n<0||m<0)return 0;
    return jc[n]*ij[m]%mod*ij[n-m]%mod;
}
void init(){
    iv[0]=jc[0]=ij[0]=iv[1]=1;
    for(int i=2;i<N;i++)
        iv[i]=mod-(mod/i)*iv[mod%i]%mod;
    for(int i=1;i<N;i++)
        jc[i]=jc[i-1]*i%mod,ij[i]=ij[i-1]*iv[i]%mod;
}

void solve(){
	int n;cin>>n;
	int res=0,mu=1;
	for(int i=0;i*4<=n;i++){
		res+=mu*dp[n-4*i]%mod*C(n-i*2,i*2)%mod*g[i]%mod; 
		mu=mu*2%mod;
	}
	cout<<res%mod<<endl;
}

main(){
	
	init();
	dp[0]=1;
	for(int i=1;i<N;i++){
		dp[i]+=dp[i-1];
		dp[i]+=dp[i-2]*(i-1);
		dp[i]%=mod;
	}
	g[0]=1;
	for(int i=1;i<N;i++){
		g[i]=g[i-1]*(i*2-1)%mod;
	}
	ios::sync_with_stdio(0);
	int _T=1;cin>>_T;
	while(_T--)solve();
}