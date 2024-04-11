#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO

#ifdef FASTIO
#define scanf abacaba
#define printf abacaba
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

using namespace std;


/*
ll pw(ll a, ll b) {
	ll ans = 1; while (b) {
		while (!(b & 1)) b >>= 1, a = (a * a) % MOD;
		ans = (ans * a) % MOD, --b;
	} return ans;
}
*/

const int MAXN = 1e6 + 100;

string tp[MAXN];
int lc[MAXN];
int rc[MAXN];
int val[MAXN];
int n;

int get(int v, int a, int b) {
	if (tp[v] == "AND")
		return (a && b);
	else if (tp[v] == "OR")
		return (a || b);
	else if (tp[v] == "XOR") {
		return (a ^ b);
	}
	return 0;
}

pair<int, vector<int> > dfs1(int v) {
	if (tp[v] == "IN") {
		return {val[v], {v}};
	}
	else if (tp[v] != "NOT") {
		auto al = dfs1(lc[v]);
		auto ar = dfs1(rc[v]);
		if (al.second.size() < ar.second.size())
			swap(al, ar);
		if (get(v, al.first, ar.first) == get(v, al.first ^ 1, ar.first))
			al.second.clear();
		if (get(v, al.first, ar.first) == get(v, al.first, ar.first ^ 1))
			ar.second.clear();
		for (int i: ar.second)
			al.second.push_back(i);
		al.first = get(v, al.first, ar.first);
		return al;
	}
	else {
		auto al = dfs1(lc[v]);
		al.first ^= 1;
		return al;
	}
}

int a[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> tp[i];
		if (tp[i] == "IN") {
			cin >> val[i];
		}
		else if (tp[i] != "NOT") {
			cin >> lc[i] >> rc[i];
			--lc[i], --rc[i];
		}
		else {
			cin >> lc[i];
			--lc[i];
		}
	}
	auto tmp = dfs1(0);
	auto ans = tmp.second;
	sort(ans.begin(), ans.end());
	for (int i: ans)
		a[i] = 1;
	for (int i = 0; i < n; ++i)
		if (tp[i] == "IN") {
			cout << (a[i] ^ tmp.first);
		}
	cout << "\n";
	return 0;
}