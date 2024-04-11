#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=1000010,MOD=1000000007;
int n,ans,a[N],c[N],f[N],pw[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n,pw[0]=1;
	for(int i=1;i<=n;i++)
		cin>>a[i],c[a[i]]++,pw[i]=pw[i-1]*2%MOD;
	for(int i=N-1;i>1;i--){
		int s=0;
		for(int j=i;j<N;j+=i)
			s+=c[j];
		if(!s)
			continue;
		f[i]=s*pw[s-1]%MOD;
		for(int j=i+i;j<N;j+=i)
			f[i]=(f[i]-f[j]+MOD)%MOD;
		ans=(ans+f[i]*i%MOD)%MOD;
	}
	cout<<ans<<"\n"; 
}