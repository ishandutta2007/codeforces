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

const int MAXN = 1200000;
int lcp[MAXN];
int c[MAXN];
int p[MAXN];

namespace SA {

char s[MAXN];
int cnt[MAXN];
int c2[MAXN];
int n;
int p2[MAXN];

int nm(int x, int n) {
	if (x < 0)
		return x + n;
	if (x >= n)
		return x - n;
	return x;
}

void buildsa() {
	s[n] = 0;
	++n;
	memset(cnt, 0, sizeof(cnt));
	for (int i = 0; i < n; ++i)
		c[i] = s[i], ++cnt[c[i] + 1];
	for (int i = 1; i < MAXN; ++i)
		cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; ++i)
		p[cnt[c[i]]++] = i;
	for (int k = 0; (1 << k) < n; ++k) {
		for (int i = 0; i < n; ++i)
			p[i] = nm(p[i] - (1 << k), n);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; ++i)
			++cnt[c[i] + 1];
		for (int i = 1; i < MAXN; ++i)
			cnt[i] += cnt[i - 1];
		for (int i = 0; i < n; ++i)
			p2[cnt[c[p[i]]]++] = p[i];
		memcpy(p, p2, sizeof(p[0]) * n);
		c2[p[0]] = 0;
		int now = 0;
		for (int i = 1; i < n; ++i) {
			if (c[p[i]] == c[p[i - 1]] &&
					c[nm(p[i] + (1 << k), n)] == c[nm(p[i - 1] + (1 << k), n)])
				c2[p[i]] = now;
			else
				c2[p[i]] = ++now;
		}
		memcpy(c, c2, sizeof(c[0]) * n);
		if (now == n - 1)
			break;
	}
	int lst = 0;
	for (int i = 0; i < n; ++i) {
		int x = c[i];
		lst = max(0, lst - 1);
		if (x == n - 1)
			lst = 0;
		else {
			int y = p[x + 1];
			while (i + lst < n && y + lst < n && s[i + lst] == s[y + lst])
				++lst;
			lcp[x] = lst;
		}
	}
	--n;
	for (int i = 0; i < n; ++i)
		lcp[i] = lcp[i + 1];
	for (int i = 0; i < n; ++i)
		--c[i];
	for (int i = 0; i < n; ++i)
		p[i] = p[i + 1];
}

}

const int LOG = 21;

string s, t;
int sp[LOG][MAXN];
int pr[MAXN];

void buildst() {
	for (int i = 0; i < LOG; ++i)
		for (int j = (1 << i); j < MAXN && j < (1 << (i + 1)); ++j)
			pr[j] = i;
	for (int i = 0; i < t.size(); ++i)
		sp[0][i] = lcp[i];
	for (int i = 1; i < LOG; ++i)
		for (int j = 0; j + (1 << i) <= t.size(); ++j)
			sp[i][j] = min(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
}

int get(int x, int y) {
	if (x > y)
		swap(x, y);
	int k = pr[y - x];
	return min(sp[k][x], sp[k][y - (1 << k)]);
}


int ans = 0;

int main() {
#ifdef FASTIO
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#endif
	cin >> s >> t;
	SA::n = t.size();
	for (int i = 0; i < t.size(); ++i)
		SA::s[i] = t[i];
	SA::buildsa();
	buildst();
	int cc[2] = {0, 0};
	for (int i = 0; i < s.size(); ++i)
		++cc[s[i] - '0'];
	if (cc[1] > cc[0]) {
		for (int i = 0; i < s.size(); ++i)
			if (s[i] == '1')
				s[i] = '0';
			else
				s[i] = '1';
		swap(cc[1], cc[0]);
	}
	for (int l = 1; l * cc[0] <= t.size(); ++l) {
		int l1 = (t.size() - l * cc[0]) / cc[1];
		if (l1 == 0 || l * cc[0] + l1 * cc[1] != t.size())
			continue;
		int p0 = -1;
		int p1 = -1;
		int cur = 0;
		int fl = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '0') {
				if (p0 == -1) {
					p0 = cur;
				}
				else {
					if (get(c[p0], c[cur]) < l) {
						fl = 1;
						break;
					}
				}
				cur += l;
			}
			else {
				if (p1 == -1) {
					p1 = cur;
				}
				else {
					if (get(c[p1], c[cur]) < l1) {
						fl = 1;
						break;
					}
				}
				cur += l1;
			}
		}
		if (fl || (l == l1 && get(c[p0], c[p1]) >= l))
			continue;
		++ans;
	}
	cout << ans << "\n";
	return 0;
}