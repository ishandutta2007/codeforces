#include<bits/stdc++.h>
#define int long long
#define f(x) ((x)%MOD)
using namespace std;
int const MOD=1000000007,INV2=500000004;
int n,k,ans;
signed main(){
	cin>>k>>n,ans=f(k)*f(n)%MOD;
	for(int l=1,r;l<=n;l=r+1)
		r=k/l?min(k/(k/l),n):n,
		ans=(ans-f(k/l)*f(r-l+1)%MOD*f(l+r)%MOD*INV2%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}