#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define Fi first
#define Se second
#define pb(x) push_back(x)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define rep(i,n) for(int i=0;i<n;i++)
#define repp(i,n) for(int i=1;i<=n;i++)


ll N,K;
int main() {
	scanf("%lld%lld",&N,&K);
	vector<ll> v; 
	repp(i,N){
		ll x; scanf("%lld",&x); v.pb(x);
	}
	v.pb(0);
	ll ans = 0;
	ll left = 0;
	for(int i=0;i<sz(v);i++){
		ll d = 0;
		if( left ){
			ans ++; d = K-left;
		}
		v[i] = max(0LL, v[i]-d);
		ans += v[i]/K; left = v[i]%K;
	}

	cout << ans << endl;

}