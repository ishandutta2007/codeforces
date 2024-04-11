#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=100010,MOD=1000000007,INV=500000004;
int n,ans,pw[N],w[N];
string s;
signed main(){
	ios::sync_with_stdio(0);
	for(int i=0;i<N;i++)
		pw[i]=i?pw[i-1]*10%MOD:1;
	for(int i=1;i<N;i++)
		w[i]=(pw[i-1]*i+w[i-1])%MOD;
	cin>>s,n=s.size();
	for(int i=0;i<n;i++)
		ans=(ans+(w[n-i-1]+pw[n-i-1]*i%MOD*(i+1)%MOD*INV%MOD)*(s[i]-48))%MOD;
	cout<<ans<<"\n";
}