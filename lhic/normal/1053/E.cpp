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

const int MAXN = 510000;

vector<int> gg[MAXN];

int a[MAXN * 2];

int n;
int nx[MAXN * 2];
vector<int> fr;
int prs[MAXN * 2];
int nxs[MAXN * 2];
vector<tuple<int, int, int>> ev;
vector<int> vv;

void no() {
	cout << "no\n";
	exit(0);
}
int cp[MAXN * 2];


int get(int x) {
	if (cp[x] == -1)
		return a[x];
	int ans = get(cp[x]);
	cp[x] = -1;
	return a[x] = ans;
}

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> n;
	for (int i = 1; i <= 2 * n - 1; ++i) {
		cin >> a[i];
		if (a[i] == 0)
			--a[i];
		if (a[i] != -1)
			gg[a[i]].push_back(i);
	}
	gg[0].push_back(0);
	gg[0].push_back(2 * n);
	++n;
	for (int i = 0; i < 2 * n - 1; ++i)
		nx[i] = i + 1;
	for (int i = 0; i < 2 * n - 1; ++i)
		prs[i] = nxs[i] = i;
	for (int i = 0; i < n; ++i) {
		if (gg[i].empty()) {
			fr.push_back(i);
			continue;
		}
		for (int j = 0; j + 1 < gg[i].size(); ++j)
			nxs[gg[i][j]] = gg[i][j + 1];
		for (int j = 1; j < gg[i].size(); ++j)
			prs[gg[i][j]] = gg[i][j - 1];
		for (int j = 1; j < gg[i].size(); ++j)
			ev.emplace_back(gg[i][j] - gg[i][0], gg[i][0], gg[i][j]);
	}
	sort(ev.begin(), ev.end());
	fill(cp, cp + 2 * n - 1, -1);
	for (auto it: ev) {
		int d, l, r;
		tie(d, l, r) = it;
		if (d % 2 == 1)
			no();
		vv.clear();
		int x = nx[l];
		while (x != r) {
			if (prs[x] < l || nxs[x] > r)
				no();
			vv.push_back(x);
			x = nx[x];
		}
		nx[l] = r + 1;
		vector<int> st;
		if (a[vv[0]] == -1)
			reverse(ALL(vv));
		for (int x: vv) {
			if (a[x] == -1) {
				if (st.size() <= 1 || a[st.back()] == -1)
					st.push_back(x);
				else {
					st.pop_back();
					cp[x] = st.back();
				}
			}
			else {
				if (st.size() >= 2 && a[st.back()] != -1 && a[st[st.size() - 2]] == -1) {
					st.pop_back();
					a[st.back()] = a[x];
					st.pop_back();
					st.push_back(x);
				}
				else
					st.push_back(x);
			}
		}
		for (int i = 1; i + 1 < st.size(); ++i)
			if (a[st[i]] != -1)
				no();
		if (a[st[0]] != -1 && a[st.back()] != -1 && a[st[0]] != a[st.back()]) {
			for (int i = 1; i < st.size(); i += 2)
				a[st[i]] = a[l];
			for (int i = 0; i < st.size(); i += 2) {
				if (a[st[i]] == -1) {
					if (fr.empty())
						no();
					a[st[i]] = fr.back();
					fr.pop_back();
				}
			}
		}
		else {
			for (int i = 0; i * 2 < st.size(); ++i) {
				if (a[st[i]] != -1) {
					a[st[st.size() - 1 - i]] = a[st[i]];
				}
				else if (a[st[st.size() - 1 - i]] != -1) {
					a[st[i]] = a[st[st.size() - 1 - i]];
				}
				else {
					if (fr.empty())
						no();
					a[st[i]] = a[st[st.size() - 1 - i]] = fr.back();
					fr.pop_back();
				}
			}
		}
	}
	for (int i = 0; i < 2 * n - 1; ++i) {
		get(i);
	}
	--n;
	for (int i = 1; i <= 2 * n - 1; ++i) {
		if (a[i] == 0)
			no();
	}
	cout << "yes\n";
	for (int i = 1; i <= 2 * n - 1; ++i)
		cout << a[i] << " ";
	cout << "\n";
	return 0;
}