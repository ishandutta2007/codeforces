#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=23,MOD=1000000007;
int n,s,ans,a[N],inv[N];
int qpow(int x,int y){
	return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
int C(int n,int m){
	if(n<m)
		return 0;
	if(n%MOD==0)
		return 1;
	int res=1;
	for(int i=1;i<=m;i++)
		res=(i+n-m)%MOD*res%MOD*inv[i]%MOD;
	return res;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>s;
	for(int i=0;i<n;i++)
		cin>>a[i],inv[i]=qpow(i,MOD-2);
	for(int i=0;i<1<<n;i++){
		int k=n+s-1;
		for(int j=0;j<n;j++)
			if(i>>j&1)
				k-=a[j]+1;
		ans=(ans+(__builtin_popcount(i)&1?-1:1)*C(k,n-1)+MOD)%MOD;
	}
	cout<<ans<<"\n";
}