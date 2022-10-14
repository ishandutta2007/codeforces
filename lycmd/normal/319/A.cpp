#include<bits/stdc++.h>
#define int long long
using namespace std;
int const N=233,MOD=1000000007;
int n,ans,pw[N];
string s;
signed main(){
	for(int i=0;i<N;i++)
		pw[i]=i?pw[i-1]*2%MOD:1;
	cin>>s,n=s.size();
	for(int i=0;i<n;i++)
		if(s[i]&1)
			ans=(ans+pw[n+n-i-2])%MOD;
	cout<<ans<<"\n";
}