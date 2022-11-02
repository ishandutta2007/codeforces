#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
typedef long long ll;

ll mod=1e9+7;

ll dp[2020];
ll ke[303030];

ll pot(ll x, ll p){
	if (p==0) return 1;
	if (p==1) return x%mod;
	if (p==2) return (x*x)%mod;
	if (p%2==0) return pot(pot(x, p/2), 2);
	return (x*pot(x, p-1))%mod;
}

ll inv(ll x){
	return pot(x, mod-2);
}

ll ncr(ll n, ll k){
	return (ke[n]*inv((ke[k]*ke[n-k])%mod))%mod;
}

ll vs(ll x1, ll y1, ll x2, ll y2){
	if (x2<x1||y2<y1) return 0;
	if (x1==x2||y1==y2) return 1;
	return ncr((x2-x1)+(y2-y1), (x2-x1));
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ke[0]=1;
	for (ll i=1;i<303030;i++){
		ke[i]=ke[i-1]*i;
		ke[i]%=mod;
	}
	ll h,w,n;
	cin>>h>>w>>n;
	vector<pair<ll, ll> > cs(n);
	for (int i=0;i<n;i++){
		cin>>cs[i].F>>cs[i].S;
	}
	sort(cs.begin(), cs.end());
	for (int i=0;i<n;i++){
		dp[i]=vs(1, 1, cs[i].F, cs[i].S);
		for (int j=0;j<i;j++){
			dp[i]-=(dp[j]*vs(cs[j].F, cs[j].S, cs[i].F, cs[i].S))%mod;
			dp[i]+=mod;
			dp[i]%=mod;
		}
		//cout<<cs[i].F<<" "<<cs[i].S<<" "<<dp[i]<<endl;
	}
	ll v=vs(1, 1, h, w);
	for (int i=0;i<n;i++){
		v-=(dp[i]*vs(cs[i].F, cs[i].S, h, w))%mod;
		v+=mod;
		v%=mod;
	}
	cout<<v<<endl;
}