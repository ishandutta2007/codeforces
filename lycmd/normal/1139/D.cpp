#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010,MOD=1000000007;
int n,ans,f[N];
int qpow(int x,int y){
	return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
signed main(){
	cin>>n;
	for(int i=n;i>=2;i--){
		f[i]=(n*qpow(n-n/i,MOD-2)%MOD-1+MOD)%MOD;
		for(int j=i+i;j<=n;j+=i)
			f[i]=(f[i]-f[j]+MOD)%MOD;
		ans=(ans+f[i])%MOD;
	}
	cout<<(ans+1)%MOD;
}//