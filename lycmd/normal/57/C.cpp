#include<bits/stdc++.h>
#define int long long
using namespace std;
int const MOD=1000000007;
int n;
int fac(int x){
	return x?fac(x-1)*x%MOD:1;
}
int qpow(int x,int y){
    return y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1;
}
int C(int n,int m){
    return fac(n)*qpow(fac(m),MOD-2)%MOD*qpow(fac(n-m),MOD-2)%MOD;
}
signed main(){
	cin>>n,cout<<((C(2*n,n)-n)%MOD+MOD)%MOD;
}