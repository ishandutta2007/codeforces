#include <bits/stdc++.h>
#define F first
#define S second
#define X real()
#define Y imag()
using namespace std;
typedef long long ll;
typedef long double ld;
const ll mod=1e9+7;

ll pot(ll x, ll p){
	if (p==0) return 1;
	if (p%2==0){
		x=pot(x, p/2);
		return x*x;
	}
	return (x*pot(x, p-1));
}

ll f(ll n){
	vector<pair<ll, ll> > pd;
	for (ll i=2;i*i<=n;i++){
		if (n%i==0){
			pd.push_back({i, 0});
		}
		while (n%i==0){
			pd.back().S++;
			n/=i;
		}
	}
	if (n>1) pd.push_back({n, 1});
	ll phi=1;
	for (auto t:pd){
		phi*=pot(t.F, t.S-1ll)*(t.F-1ll);
	}
	return phi;
}

ll F(ll n, ll k){
	if (k==1){
		return f(n);
	}
	else{
		if (k%2==0){
			return F(n, k-1);
		}
		else{
			return f(F(n, k-1));
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n,k;
	cin>>n>>k;
	if (k>1000){
		cout<<1<<endl;
		return 0;
	}
	else{
		cout<<F(n, k)%mod<<endl;
	}
}