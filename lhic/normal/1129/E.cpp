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

const int MAXN = 510;

int n;

int sz[MAXN];
vector<pair<int, int> > vv;
vector<pair<int, int>> ed;
int was[MAXN];
int cr[MAXN];

int ask(vector<int> a, vector<int> b, int c) {
	if (a.empty() || b.empty())
		return 0;
	cout << a.size() << "\n";
	for (int i: a)
		cout << i + 1 << " ";
	cout << "\n";
	cout << b.size() << "\n";
	for (int i: b)
		cout << i + 1 << " ";
	cout << "\n";
	cout << c + 1 << "\n";
	cout.flush();
	int x;
	cin >> x;
	return x;
}

void add_edge(int a, int b) {
	a = vv[a].second;
	b = vv[b].second;
	ed.emplace_back(a, b);
}

void dfs1(int v) {
	was[v] = 1;
	cr[v] = 1;
	if (v == 0) {
		for (int j = 1; j < n; ++j)
			if (!was[j])
				add_edge(v, j), dfs1(j), cr[v] += cr[j];
	}
	else {
		while (cr[v] != vv[v].first) {
			int lb = v;
			int rb = n - 1;
			while (rb - lb > 1) {
				int mid = (lb + rb) >> 1;
				vector<int> a = {vv[0].second};
				vector<int> b;
				for (int j = v + 1; j <= mid; ++j)
					if (!was[j])
						b.push_back(vv[j].second);
				if (ask(a, b, vv[v].second))
					rb = mid;
				else
					lb = mid;
			}
			add_edge(v, rb);
			dfs1(rb);
			cr[v] += cr[rb];
		}
	}
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	sz[0] = n;
	vv.emplace_back(sz[0], 0);
	for (int i = 1; i < n; ++i) {
		vector<int> a = {0};
		vector<int> b;
		for (int j = 1; j < n; ++j)
			if (j != i)
				b.push_back(j);
		sz[i] = ask(a, b, i) + 1;
		vv.emplace_back(sz[i], i);
	}
	sort(ALL(vv));
	reverse(ALL(vv));
	dfs1(0);
	cout << "ANSWER\n";
	for (auto p: ed)
		cout << p.first + 1 << " " << p.second + 1 << "\n";
	cout.flush();
	return 0;
}