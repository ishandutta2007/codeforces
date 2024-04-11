#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const ll L = 2520;
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a * b / gcd(a, b); }

vector <ll> S;
ll id[L + 10];
ll dp[20][60][L],num[20];
ll dfs(ll nw, ll s, ll rst, bool flg) {
	if (nw == 0) return rst % S[s] == 0;
	if (!flg && dp[nw][s][rst] != -1) return dp[nw][s][rst];
	ll res = 0, lim = flg ? num[nw] : 9;
	for (ll c = 0; c <= lim; ++c)
		res += dfs(nw - 1, c ? id[lcm(S[s], c)] : s, (rst * 10 + c) % L, flg && c == lim);
	if (!flg) dp[nw][s][rst] = res;
	return res;
}

ll calc(ll val) {
	if (val < 1) return 0;
	ll len = 0;
	while (val)
		num[++len] = val % 10, val /= 10;
	return dfs(len, id[1], 0, 1) - 1;
}

void work() {
	ll l, r;
	scanf("%lld%lld", &l, &r);
	printf("%lld\n", calc(r) - calc(l - 1));
}

int main() {
	for (ll i = 1; i <= L; ++i)
		if (L % i == 0) S.push_back(i), id[i] = S.size() - 1;
	memset(dp, -1, sizeof dp);
	ll t;
	scanf("%lld", &t);
	while (t--) work();
	return 0;
}