#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010,MOD=1000000009;
int n,a,b,k,ans;
string s;
int qpow(int x,int y){
	return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
int calc(int a1,int d,int n){
	int an=a1*qpow(d,n-1)%MOD;
	return d>1?(an*d%MOD-a1+MOD)%MOD*qpow(d-1,MOD-2)%MOD:a1*n%MOD;
}
signed main(){
	cin>>n>>a>>b>>k>>s;
	int d=qpow(a,k*(MOD-2))*qpow(b,k)%MOD;
	for(int i=0;i<k;i++){
		int a1=((s[i]=='+'?1:-1)*qpow(a,n-i)*qpow(b,i)%MOD+MOD)%MOD;
		ans=(ans+calc(a1,d,(n+1)/k))%MOD;
	}
	cout<<ans<<"\n";
}