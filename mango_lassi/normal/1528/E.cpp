#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 998244353;

ll mAdd(ll a, ll b) {
	return (a + b >= MOD ? a + b - MOD : a + b);
}
ll mSub(ll a, ll b) {
	return (a < b ? a + MOD - b : a - b);
}
ll modPow(ll a, ll b) {
	if (b & 1) return modPow(a, b ^ 1) * a % MOD;
	if (b == 0) return 1;
	return modPow(a*a % MOD, b >> 1);
}

const int N = 1e6;
ll dp0[N+1]; // Number of rooted directed trees of depth exactly n and outdegree at most 2
ll sum0[N+1];
ll sum1[N+1];
ll two_inv;
ll six_inv;

ll pick2(ll n) {
	return (n * mAdd(n, 1) % MOD) * two_inv % MOD;
}
ll pick3(ll n) {
	return ((n * mAdd(n, 1) % MOD) * mAdd(n, 2) % MOD) * six_inv % MOD;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	two_inv = modPow(2, MOD - 2);
	six_inv = two_inv * modPow(3, MOD - 2) % MOD;

	dp0[0] = 1;
	sum0[0] = 1;
	sum1[0] = 1;
	for (int i = 1; i <= n; ++i) {
		dp0[i] = (dp0[i-1] + pick2(dp0[i-1]) + (i >= 2 ? sum0[i-2] * dp0[i-1] : 0)) % MOD;
		sum0[i] = mAdd(sum0[i-1], dp0[i]);
		sum1[i] = (sum1[i-1] + sum0[i-1] * dp0[i] + pick2(dp0[i])) % MOD;
	}

	// Special vertex = vertex with 0, 2 or 3 out-edges, such that every vertex can reach it, or it can reach every vertex
	// Unique, always exists!

	// Count number of ways for special vertex to have no in-edges
	ll res = pick3(dp0[n-1]);
	if (n >= 2) {
		res = (res + pick2(dp0[n-1]) * sum0[n-2]) % MOD;
		res = (res + dp0[n-1] * sum1[n-2]) % MOD;
	}
	res = (res + mSub(dp0[n], dp0[n-1])) % MOD; // 2 children

	// Count number of ways for special vertex to have no out-edges
	res = (res + pick3(dp0[n-1])) % MOD;
	if (n >= 2) {
		res = (res + pick2(dp0[n-1]) * sum0[n-2]) % MOD;
		res = (res + dp0[n-1] * sum1[n-2]) % MOD;
	}
	res = (res + dp0[n]) % MOD; // 1, 2 parents

	// 2 outedges, 1 in-edge
	for (int k = 1; k < n; ++k) {
		res = (res + dp0[k-1] * mSub(dp0[n-k], dp0[n-k-1])) % MOD;
	}

	if (res < 0) res += MOD;
	cout << res << '\n';
}