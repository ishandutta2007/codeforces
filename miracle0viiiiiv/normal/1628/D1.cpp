#include <bits/stdc++.h>
using namespace std;
const int M=1e9+7;
int f[1000010],invf[1000010];
int comb(int n,int m){return n<m||m<0?0:f[n]*1ull*invf[n-m]%M*invf[m]%M;}
void solve(){
	int n,m,k,ans=0;cin>>n>>m>>k;
	if(n==m)ans=k*1ull*n%M;
	else for(int i=n;i>=1;i--){
		ans=(ans+comb(n-i-1,m-i)*1ull*k%M*i)%M;k=k*(M+1ull)/2%M;
	}
	cout<<ans<<'\n';
}
int main(){
	f[0]=1;for(int i=1;i<=1000000;i++)f[i]=f[i-1]*1ull*i%M;
	for(int i=1;i<=1000000;i++)invf[i]=i==1?1:M-invf[M%i]*1ull*(M/i)%M;
	invf[0]=1;for(int i=1;i<=1000000;i++)invf[i]=invf[i-1]*1ull*invf[i]%M;
	ios::sync_with_stdio(false); cin.tie(0);
	int t;cin>>t;
	while(t--)solve();
	return 0;
}