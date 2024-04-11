#include<bits/stdc++.h>
#define int long long
const int N=255,mod=998244353;
using namespace std;

int dp[N][N];
int n,k;

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

int gsc(int x,int y){
    int ans=1;
    for(int i=1;i<=y;i<<=1,x=x*x%mod)
        if(y&i)
            ans=ans*x%mod;
    return ans;
}int inv(int k){return gsc(k,mod-2);}

void solve(){
	init();
	cin>>n>>k;
	dp[0][0]=1;
	n--;
	for(int i=1;i<=k;i++){
		for(int j=0;j<=n;j++){
			for(int l=0;j+l<=n;l++)
				if(dp[i-1][j]){
					int xs=C(n-j,l);
					xs*=gsc(k-i+1,l*j+l*(l-1)/2);
					xs%=mod;
					dp[i][j+l]=(dp[i][j+l]+dp[i-1][j]*xs)%mod;
				}
		}
	}
	cout<<dp[k][n]<<endl;
}

main(){
	ios::sync_with_stdio(false);
	int _T=1;//cin>>_T;
	while(_T--)solve();
	
}