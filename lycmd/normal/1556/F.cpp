#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=23,M=23333,MOD=1000000007;
int n,ans,a[N],p[N][N],f[M];
int qpow(int x,int y){
	return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
int calc(int x,int y){
	int res=1;
	for(int i=0;i<n;i++)
		if(x>>i&1)
			for(int j=0;j<n;j++)
				if(y>>j&1)
					res=res*p[i][j]%MOD;
	return res;
}
signed main(){
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			p[i][j]=a[i]*qpow(a[i]+a[j],MOD-2)%MOD;
	for(int i=1;i<1<<n;i++)
		f[i]=1;
	for(int i=1;i<1<<n;i++)
		for(int j=(i-1)&i;j;j=(j-1)&i)
			f[i]=(f[i]-f[j]*calc(j,i^j)%MOD+MOD)%MOD;
	for(int i=1;i<1<<n;i++)
		ans=(ans+__builtin_popcountll(i)*f[i]%MOD*calc(i,(1<<n)-1-i)%MOD)%MOD;
	cout<<ans<<"\n";
}