#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define FASTIO
#define ALL(v) (v).begin(), (v).end()
#define rep(i, l, r) for (int i = (l); i < (r); ++i)

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
const int MAXN = 610;

int n;

int en[MAXN];
vector<int> eds[MAXN];
int cl[MAXN];

void add_edge(int a, int b) {
	eds[a].push_back(b);
	eds[b].push_back(a);
}

void dfs1(int v, int p, int c) {
	cl[v] = c;
	for (int u: eds[v]) {
		if (u == p)
			continue;
		dfs1(u, v, c ^ 1);
	}
}

vector<int> st;
//vector<pair<int, int>> ed = {{4, 1}, {1, 3}, {3, 2}, {2, 4}};
//vector<pair<int, int>> ed = {{1, 2}, {1, 4}, {2, 4}, {3, 4}};

int dfs2(int v, int p, int d) {
	st.push_back(v);
	if (v == d)
		return 1;
	for (int u: eds[v]) {
		if (u == p)
			continue;
		if (dfs2(u, v, d))
			return 1;
	}
	st.pop_back();
	return 0;
}
//int was[MAXN];

int ask(vector<int> vv) {
	if (vv.size() <= 1)
		return 0;
	cout << "? " << vv.size() << "\n";
	for (int i: vv)
		cout << i << " ";
	cout << "\n";
	cout.flush();
	int x = 0;
	cin >> x;
	/*memset(was, 0, sizeof(was));
	for (int i: vv)
		was[i] = 1;
	for (auto p: ed)
		if (was[p.first] && was[p.second])
			++x;*/
	return x;
}

int ask(vector<int> vv, int x) {
	int a = ask(vv);
	vv.push_back(x);
	int b = ask(vv);
	return b - a;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	queue<int> qu;
	qu.push(1);
	en[1] = 1;
	while (!qu.empty()) {
		int x = qu.front();
		qu.pop();
		while (true) {
			vector<int> vv;
			for (int i = 1; i <= n; ++i)
				if (!en[i])
					vv.push_back(i);
			int ad = ask(vv, x);
			if (ad == 0)
				break;
			int l = 0;
			int r = vv.size();
			while (r - l > 1) {
				int mid = (l + r) >> 1;
				vector<int> vv2 = vv;
				vv2.resize(mid);
				if (ask(vv2, x))
					r = mid;
				else
					l = mid;
			}
			add_edge(x, vv[l]);
			qu.push(vv[l]);
			en[vv[l]] = 1;
		}
	}
	dfs1(1, 0, 0);
	vector<int> vv[2];
	for (int i = 1; i <= n; ++i)
		vv[cl[i]].push_back(i);
	int x = ask(vv[0]);
	int y = ask(vv[1]);
	if (!x && !y) {
		cout << "Y " << vv[0].size() << "\n";
		for (int i: vv[0])
			cout << i << " ";
		cout << "\n";
		cout.flush();
		return 0;
	}
	if (!x)
		swap(vv[0], vv[1]);
	for (int i = 2; i <= vv[0].size(); ++i) {
		vector<int> vv2 = vv[0];
		vv2.resize(i);
		if (ask(vv2)) {
			int x = vv2.back();
			for (int y: vv2) {
				vector<int> tmp = {x, y};
				if (ask(tmp)) {
					dfs2(x, 0, y);
					cout << "N " << st.size() << "\n";
					for (int i: st) {
						cout << i << " ";
					}
					cout << "\n";
					cout.flush();
					return 0;
				}
			}
		}
	}
	return 0;
}