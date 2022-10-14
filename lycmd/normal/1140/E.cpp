#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=300010,MOD=998244353;
int n,k,ans=1,a[N],pw[N],s[N];
signed main(){
	ios::sync_with_stdio(0);
	cin>>n>>k,pw[0]=1;
	for(int i=1;i<=n;i++)
		cin>>a[i],pw[i]=pw[i-1]*(k-1)%MOD,s[i]=(pw[i]-s[i-1]+MOD)%MOD;
	for(int i=1;i<=2;i++)
		for(int j=i,pre=0,l=0;j<=n+2;j+=2)
			if(~a[j])
				ans=ans*(!pre||!a[j]?pw[l]+(pre||a[j]||!l?0:pw[l-1]):s[l]+(pre^a[j]?l&1?MOD-1:1:0))%MOD,l=0,pre=a[j];
			else l++;
	cout<<ans<<"\n";
}