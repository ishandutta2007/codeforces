#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=200010,MOD=998244353;
int n,ans,x[N],y[N],s[N],f[N],g[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i]>>s[i];
		int p=lower_bound(x+1,x+1+i,y[i])-x;
		f[i]=(x[i]-y[i]+g[i-1]-g[p-1]+2*MOD)%MOD;
		g[i]=(g[i-1]+f[i])%MOD,ans=(ans+s[i]*f[i]%MOD)%MOD;
	}
	cout<<(ans+x[n]+1)%MOD<<"\n";
}