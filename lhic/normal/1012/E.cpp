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

const int MAXN = 210000;

int was[MAXN];
int wss[MAXN];
vector<int> st;
vector<vector<int> > vv;
vector<vector<int>> vv2;
int lb[MAXN];
int rb[MAXN];

set<int> ss;
int pl[MAXN], cl[MAXN];
int pos[MAXN];
int n;

void dfs1(int v) {
	was[v] = 1;
	st.push_back(v);
	if (was[pos[v]])
		return;
	dfs1(pos[v]);
}


void dfs2(int v, int start) {
	int len = vv[v].size() / 2;
	for (int i = 0; i < len; ++i)
		ss.erase(vv[v][i]);
	wss[v] = 1;
	for (int i = start; i < start + len; ++i) {
		int x = vv[v][i];
		st.push_back(x);
		auto it = ss.lower_bound(lb[x]);
		if (it != ss.end() && *it < rb[x]) {
			int u = *it;
			dfs2(cl[u], pl[u]);
		}
	}
}

int a[MAXN];
int b[MAXN];

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	int s;
	cin >> n >> s;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b, b + n);
	set<pair<int, int>> ss2;
	for (int i = 0; i < n; ++i) {
		if (a[i] == b[i])
			pos[i] = i;
		else {
			ss2.insert({b[i], i});
		}
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[i]) {
			auto it = ss2.lower_bound({a[i], 0});
			pos[i] = it->second;
			ss2.erase(it);
		}
	}
	for (int i = 0; i < n; ++i) {
		lb[i] = lower_bound(b, b + n, a[i]) - b;
		rb[i] = lower_bound(b, b + n, a[i] + 1) - b;
	}
	for (int i = 0; i < n; ++i) {
		if (was[i])
			continue;
		if (pos[i] == i)
			continue;
		st.clear();
		dfs1(i);
		for (int j = 0; j < st.size(); ++j)
			cl[st[j]] = vv.size(), pl[st[j]] = j;
		vv.push_back(st);
	}
	for (int i = 0; i < vv.size(); ++i) {
		int x = vv[i].size();
		for (int j = 0; j < x; ++j)
			vv[i].push_back(vv[i][j]);
	}
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[i])
			ss.insert(i);
	}
	for (int i = 0; i < vv.size(); ++i) {
		if (wss[i])
			continue;
		st.clear();
		dfs2(i, 0);
		vv2.push_back(st);
	}
	int sum = 0;
	for (int i = 0; i < vv2.size(); ++i)
		sum += vv2[i].size();
	if (sum > s) {
		cout << -1 << "\n";
		return 0;
	}
	int av = min((int)vv2.size(), s - sum);
	if (av <= 1) {
		cout << vv2.size() << "\n";
		for (int i = 0; i < vv2.size(); ++i) {
			cout << vv2[i].size() << "\n";
			for (int j: vv2[i])
				cout << j + 1 << " ";
			cout << "\n";
		}
	}
	else {
		cout << vv2.size() - (av - 1) + 1 << "\n";
		int sum = 0;
		for (int i = 0; i < av; ++i) {
			sum += vv2[i].size();
		}
		cout << sum << "\n";
		for (int i = 0; i < av; ++i) {
			for (int j: vv2[i])
				cout << j + 1 << " ";
		}
		cout << "\n";
		for (int i = av; i < vv2.size(); ++i) {
			cout << vv2[i].size() << "\n";
			for (int j: vv2[i])
				cout << j + 1 << " ";
			cout << "\n";
		}
		cout << av << "\n";
		for (int i = av - 1; i >= 0; --i)
			cout << vv2[i][0] + 1 << " ";
		cout << "\n";
	}
	return 0;
}