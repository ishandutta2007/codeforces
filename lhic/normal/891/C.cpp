#ifndef LOCAL
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

typedef long long ll;
typedef long long llong;
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


const int MAXN = 510000;
const int MX = 510000;
int p[MAXN];
int sz[MAXN];

int n, m;
vector<pair<int, int> > gg[MX];
vector<pair<int, int> > go[MX];
tuple<int, int, int> ed[MAXN];
vector<pair<int, int> > st;

int fl[MAXN];

int get(int a) {
	if (p[a] == a)
		return a;
	return get(p[a]);
}

void un(int a, int b) {
	a = get(a);
	b = get(b);
	if (a == b)
		return;
	if (sz[a] > sz[b])
		swap(a, b);
	st.push_back(make_pair(a, b));
	sz[b] += sz[a];
	p[a] = b;
}

void undo() {
	int a = st.back().first;
	int b = st.back().second;
	st.pop_back();
	sz[b] -= sz[a];
	p[a] = a;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		--a, --b;
		gg[c].push_back(make_pair(a, b));
		ed[i] = make_tuple(c, a, b);
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int k;
		scanf("%d", &k);
		for (int j = 0; j < k; ++j) {
			int x;
			scanf("%d", &x);
			--x;
			go[get<0>(ed[x])].push_back(make_pair(i, x));
		}
	}
	for (int i = 0; i < n; ++i)
		p[i] = i, sz[i] = 1;
	for (int i = 0; i < MX; ++i) {
		sort(go[i].begin(), go[i].end());
		int lst = 0;
		for (int j = 0; j < go[i].size(); ++j) {
			if (j + 1 == go[i].size() || go[i][j].first != go[i][j + 1].first) {
				int cc = 0;
				int fln = 0;
				for (int k = lst; k <= j; ++k) {
					int a = get(get<1>(ed[go[i][k].second]));
					int b = get(get<2>(ed[go[i][k].second]));
					if (a == b) {
						fln = 1;
						break;
					}
					++cc;
					un(a, b);
				}
				lst = j + 1;
				if (fln)
					fl[go[i][j].first] = 1;
				while (cc--)
					undo();
			}
		}
		for (auto e: gg[i]) {
			un(e.first, e.second);
		}
	}
	for (int i = 0; i < q; ++i)
		if (!fl[i])
			printf("YES\n");
		else
			printf("NO\n");
	return 0;
}