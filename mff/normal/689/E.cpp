#include <bits/stdc++.h>

using namespace std;

typedef long long int64;
typedef vector<int> vi;
typedef pair<int64,int64> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;
const int maxn = 200010;

const int64 mod = 1000000007;

int64 fact[maxn];
int64 ifact[maxn];

int64 modexp(int64 a, int64 n, int64 m){
	if (n == 0) return 1 % m;
	if (n & 1) return a * modexp(a, n - 1, m) % m;
	return modexp(a * a % m, n / 2, m);
}

int64 c(int n, int k){
	return fact[n] * ifact[k] % mod * ifact[n - k] % mod;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, k; cin >> n >> k;

	fact[0] = ifact[0] = 1;

	for (int i = 1; i <= n; ++i){
		fact[i] = fact[i - 1] * i % mod;
		ifact[i] = modexp(fact[i], mod - 2, mod);
	}

	vector<pii> P;

	for (int i = 0; i < n; ++i){
		int u, v; cin >> u >> v;
		P.push_back({u, +1});
		P.push_back({v + 1, -1});
	}

	sort(P.begin(), P.end());

	int64 ans = 0;
	int64 p = -1000000000;

	for (int i = 0, t = 0, j; i < (int)P.size(); i = j){

		if (t >= k){
			int64 cur = (P[i].first - p) * c(t, k) % mod;
			ans = (ans + cur) % mod;
		}

		for (j = i; j < (int)P.size() && P[j].first == P[i].first; ++j){
			t += P[j].second;
		}

		p = P[i].first;
	}

	cout << ans << endl;

	return 0;
}