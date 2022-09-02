#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const ll Q = 5;
const int LIM = 1e4;

ll dp[LIM][Q+1];

ll solve(ll a, ll q) {
	if (q == 1) return a + min(a, (ll)LIM) - 1;
	if (a >= LIM) {
		ll sl = solve(a, q-1) - a + 1;
		ll resl = LIM + sl * (LIM + 1);
		return a + resl - 1;
	}

	if (dp[a][q] != -1) return dp[a][q];
	
	ll res = solve(a, q-1);
	for (int i = 0; i < a; ++i) {
		++res;
		res = solve(res+1, q-1);
	}
	dp[a][q] = res;
	return res;
}

vector<ll> build(ll a, ll q) {
	if (q == 1) {
		int n = min(a, (ll)LIM);
		vector<ll> res(n);
		for (int i = 0; i < n; ++i) res[i] = a + i;
		return res;
	}
	if (a >= LIM) {
		// _ _ _ 4 _ _ _ 8 _ _ _ 12 _ _ _
		int n = LIM;
		vector<ll> res(n);
		ll sl = solve(a, q-1) - a + 2;
		for (int i = 0; i < n; ++i) res[i] = a - 1 + sl * (i+1);
		return res;
	}
	
	int n = a;
	vector<ll> res(n);

	ll cur = solve(a, q-1);
	for (ll i = 0; i < a; ++i) {
		++cur;
		res[i] = cur;
		cur = solve(cur+1, q-1);
	}

	return res;
}

ll ask(const vector<ll>& vec) {
	cout << vec.size();
	for (auto it : vec) cout << ' ' << it;
	cout << endl;

	ll res;
	cin >> res;
	return res;
}

int main() {
	for (ll i = 0; i < LIM; ++i) {
		for (ll j = 0; j <= Q; ++j) {
			dp[i][j] = -1;
		}
	}

	ll a = 1;
	int q = Q;
	while(true) {
		vector<ll> res = build(a, q);
		--q;
		ll sub = ask(res);
		if (sub < 0) break;
		if (sub == 0) continue;
		a = res[sub-1] + 1;
	}
}