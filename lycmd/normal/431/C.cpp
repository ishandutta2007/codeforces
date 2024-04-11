#include<bits/stdc++.h>
#define int long long
using namespace std;
int const MOD=1e9+7,N=233;
int n,d,k,f[N],g[N];
signed main(){
    cin>>n>>k>>d,f[0]=g[0]=1;;
	for(int i=1;i<=n;i++){
		for(int j=max(0ll,i-k);j<i;j++)
		    f[i]=(f[i]+f[j])%MOD;
		for(int j=max(0ll,i-d+1);j<i;j++)
		    g[i]=(g[i]+g[j])%MOD;
	}
	cout<<(f[n]-g[n]+MOD)%MOD<<"\n";
}