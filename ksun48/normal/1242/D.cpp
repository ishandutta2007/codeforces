#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll k;

ll round_down(ll a, ll res){
	return res + ((a - res) / k) * k;
}

// number, index
pair<ll, ll> sequence_prev(ll n){
	if(n < k * (k + 1) / 2) return {0, 0};
	ll en = (n + k * (k-1) / 2 + k-1) / k;
	pair<ll, ll> excl = sequence_prev(en);

	// above excl
	ll next_en = round_down(en, excl.second % k);
	if(next_en < excl.first){
		next_en--;
	}
	if (next_en == en && next_en - k > excl.first && next_en * k - k * (k-1) / 2 > n){
		next_en -= k;
	}
	if (next_en == en && next_en - k <= excl.first && (next_en * (k+1) - k * (k+1) / 2) - excl.first > n) {
		next_en -= (k+1);
	}
	ll val, idx;
	if(next_en >= excl.first && next_en - k <= excl.first){
		val = (next_en * (k+1) - k * (k+1) / 2) - excl.first;
	} else {
		val = next_en * k - k * (k-1) / 2;
	}

	if(next_en < excl.first){
		idx = (next_en - (excl.second - 1)) / k;
	} else {
		idx = (next_en - excl.second) / k;
	}
	return {val, idx};
}

void solve(){
	ll n;
	cin >> n >> k;
	pair<ll, ll> f = sequence_prev(n);
	if(f.first == n){
		cout << (k+1) * f.second << '\n';
	} else {
		ll idx = f.second;
		ll cnt = n - idx;
		ll full = (cnt - 1) / k;
		cout << cnt + full << '\n';
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T;
	cin >> T;
	while(T--){
		solve();
	}
}