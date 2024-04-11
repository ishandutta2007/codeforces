#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=2010,MOD=1000000007;
int n,m,a[N],c[N];
int qpow(int x,int y){
	return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>m,c[0]=1;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=1;i<n;i++)
		c[i]=c[i-1]*(m+i-1)%MOD*qpow(i,MOD-2)%MOD;
	for(int i=0;i<n;i++){
		int res=0;
		for(int j=0;j<=i;j++)
			res=(res+a[j]*c[i-j]%MOD)%MOD;
		cout<<res<<" ";
	}
}