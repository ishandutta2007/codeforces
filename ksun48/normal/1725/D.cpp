#include <bits/stdc++.h>
using namespace std;

using ll = int64_t;
int main(){
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	ll N;
	cin >> N;
	ll total_cost = 0;
	ll nleft = N;
	ll last_D;
	ll last_need;
	for(ll D = 1; ; D++){
		ll gain = (D + 1) / 2;
		ll need = min(nleft, gain);
		total_cost += ll(need) * ll(D);
		nleft -= need;
		last_D = D;
		last_need = need;
		if(nleft == 0) break;
	}
	cout << total_cost << '\n';

	ll L = last_D;

	vector<ll> nused(L);
	for(ll i = 0; i < L; i++){
		nused[i] = (L - i) / 2;
	}
	for(ll j = 0; j < last_need; j++){
		nused[L - 1 - 2 * j] += 1;
	}
	vector<ll> nused_psum(L + 1);
	for(ll l = 0; l < L; l++){
		nused_psum[l+1] = nused_psum[l] + nused[l];
	}

	const ll MAXL = 16;
	vector<ll> nless(L, 0);
	for(ll l = 0; l < L; l++){
		ll z = max(ll(0), l - MAXL);
		nless[l] += nused_psum[z];
		for(ll j = z; j < l; j++){
			ll x = ll(1) << (l-j);
			nless[l] += min(nused[j], x / 2);
		}
	}
	assert(nless[L-1] == N-1);

	ll Q;
	cin >> Q;
	vector<ll> queries(Q);
	for(ll& p : queries){
		cin >> p;
		p--;
	}

	ll idx = 0;
	for(ll i = 0; i < Q; i++){
		while(idx + 1 < L && nless[idx + 1] <= queries[i]) idx++;
		ll z = max(ll(0), idx - MAXL);
		ll s = ll(1) << (idx - z);
		ll e = ll(1) << (idx + 1 - z);
		while(s + 1 < e){
			ll m = (s + e) / 2;
			// 2*z * m, how many less?
			ll m_eq = m - 1;
			ll num_less = nused_psum[z];
			for(ll j = z; j <= idx && j < L; j++){
				ll thresh = m_eq >> (j - z);
				num_less += min((thresh + 1) / 2, nused[j]);
			}
			if(num_less <= queries[i]){
				s = m;
			} else {
				e = m;
			}
		}
		ll a = z;
		ll b = s;
		while(b % 2 == 0){
			b >>= 1;
			a += 1;
		}
		cout << (a + b) << '\n';
	}
	cout << flush;
}