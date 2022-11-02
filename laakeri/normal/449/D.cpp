#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll pot(ll x, ll p, ll mod){
	if (p==0) return 1;
	if (p%2==0){
		x=pot(x, p/2, mod);
		return (x*x)%mod;
	}
	return (x*pot(x, p-1, mod))%mod;
}

ll inv(ll x, ll mod){
	return pot(x, mod-2, mod);
}

const ll mod=1e9+7;

ll dp[1<<20][21];
ll c[1<<20];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		int a;
		cin>>a;
		a=((1<<20)-1)&(~a);
		c[a]++;
	}
	ll v=0;
	for (int i=0;i<(1<<20);i++){
		dp[i][0]+=c[i];
		ll f=0;
		for (int j=0;j<20;j++){
			f+=dp[i][j];
			if ((i&(1<<j))==0){
				dp[i^(1<<j)][j+1]+=f;
			}
		}
		ll t=0;
		for (int j=0;j<21;j++){
			t+=dp[i][j];
		}
		if (__builtin_popcount(i)%2==0){
			v+=pot(2, t, mod);
		}
		else{
			v-=pot(2, t, mod);
		}
		v+=mod;
		v%=mod;
	}
	cout<<v<<endl;
}