#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

ll modPow(ll a, ll b) {
	if (b == 0) return 1;
	if (b & 1) return (a * modPow(a, b-1)) % MOD;
	else return modPow((a*a) % MOD, b / 2);
}

const int N = 2 * (int)1e5;
vector<int> conns[N];
ll fact[N+1];

ll solve(int i, int p) {
	ll res = 1;
	int cou = 1;
	for (auto t : conns[i]) {
		if (t == p) continue;
		++cou;
		res = (res * solve(t, i)) % MOD;
	}
	res = (res * fact[cou]) % MOD;
	// cout << "solve " << i << ' ' << p << ": " << res << '\n';
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// When does a permutation not work?
	// If there are edges a-b and c-d, and the order is a ... c ... b ... d. It works in all other cases.
	// The parent of a subtree has to be one of the two nodes adjacent to the subtree. The subtree must be continuous
	// DP how many ways there are to build some subtree? For a node with K children, we can do it in (K+1)! ways

	int n;
	cin >> n;

	fact[0] = 1;
	for (int i = 1; i <= n; ++i) fact[i] = (fact[i-1]*i) % MOD;

	for (int i = 0; i < n-1; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		conns[a].push_back(b);
		conns[b].push_back(a);
	}

	ll res = solve(0, 0);
	res = (res * modPow(conns[0].size() + 1, MOD-2)) % MOD;
	res = (res * n) % MOD;
	cout << res << '\n';

	// Symmetry: root must appear before any of its children -> Divide by (conns[0].size() + 1)
}