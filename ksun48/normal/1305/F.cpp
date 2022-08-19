#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main(){
	auto st = clock();
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n;
	cin >> n;
	vector<ll> a(n);
	for(ll& x : a) cin >> x;
	shuffle(a.begin(), a.end(), rng);
	ll best = n;
	set<ll> tried;
	for(int i = 0; i < n; i++){
		if(clock() > st + 0.1 * CLOCKS_PER_SEC) break;
		for(ll f = a[i] - 2; f <= a[i] + 2; f++){
			vector<ll> pr;
			ll c = f;
			for(ll p = 2; p * p <= c; p++){
				if(c % p == 0){
					while(c % p == 0) c /= p;
					pr.push_back(p);
				}
			}
			if(c > 1) pr.push_back(c);
			for(ll p : pr){
				if(tried.count(p)) continue;
				tried.insert(p);
				ll cost = 0;
				for(ll r : a){
					if(r < p){
						cost += p - r;
					} else {
						r %= p;
						cost += min(r, p-r);
					}
					if(cost > best) break;
				}
				best = min(best, cost);
			}
		}
	}
	cout << best << '\n';
}