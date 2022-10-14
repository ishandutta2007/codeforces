#include<bits/stdc++.h>
#define int long long
using namespace std;
int const MOD=998244353,MOD1=MOD-1,INV2=499122177;
int n,m,l,r;
int qpow(int x,int y){
	return x%MOD?y?qpow(x*x%MOD,y>>1)*(y&1?x:1)%MOD:1:0;
}
signed main(){
	cin>>n>>m>>l>>r;
	if(n&1&&m&1){
		cout<<qpow(r-l+1,n*m)<<"\n";
	}else{
		int e=r/2-(l-1)/2,o=r-l+1-e;
		cout<<(qpow(o+e,n*m%MOD1)+qpow((o-e+MOD)%MOD,n*m%MOD1)+MOD)*INV2%MOD<<"\n"; 
	}
}//