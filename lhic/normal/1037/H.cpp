#ifndef BZ
#pragma GCC optimize "-O3"
#endif
#include <bits/stdc++.h>

#define ALL(v) (v).begin(), (v).end()

using ll = long long;
using ld = long double;
using ull = uint64_t;

using namespace std;
const int MAXN = 210000;
const int LOG = 19;

string t;
int s[MAXN];
int pr[1 << (LOG + 1)];
int cnt[MAXN];
int c[MAXN];
int p[MAXN];
int c2[MAXN];
int p2[MAXN];
int lcp[MAXN];
pair<int, int> sp[LOG][MAXN];

int nm(int x, int n) {
	if (x < 0)
		return x + n;
	else if (x >= n)
		return x - n;
	return x;
}

void buildsa(int n) {
	int sz = max(30, n + 1);
	fill(cnt, cnt + sz, 0);
	for (int i = 0; i < n; ++i) {
		c[i] = s[i];
		++cnt[c[i] + 1];
	}
	for (int i = 0; i < sz; ++i)
		cnt[i + 1] += cnt[i];
	for (int i = 0; i < n; ++i)
		p[cnt[c[i]]++] = i;
	for (int k = 0; (1 << k) < n; ++k) {
		for (int i = 0; i < n; ++i)
			p[i] = nm(p[i] - (1 << k), n);
		fill(cnt, cnt + sz, 0);
		for (int i = 0; i < n; ++i)
			++cnt[c[i] + 1];
		for (int i = 0; i < sz; ++i)
			cnt[i + 1] += cnt[i];
		for (int i = 0; i < n; ++i)
			p2[cnt[c[p[i]]]++] = p[i];
		memcpy(p, p2, sizeof(p[0]) * n);
		int now = 0;
		c2[p[0]] = now;
		for (int i = 1; i < n; ++i) {
			if (c[p[i]] == c[p[i - 1]] && c[nm(p[i] + (1 << k), n)] == c[nm(p[i - 1] + (1 << k), n)])
				c2[p[i]] = now;
			else
				c2[p[i]] = ++now;
		}
		memcpy(c, c2, sizeof(c[0]) * n);
		++now;
		if (now == n)
			break;
	}
	int lst = 0;
	for (int i = 0; i < n; ++i) {
		lst = max(0, lst - 1);
		int x = c[i];
		if (x == n - 1) {
			lst = 0;
			lcp[x] = 0;
			continue;
		}
		int y = p[x + 1];
		while (i + lst < n && y + lst < n && s[i + lst] == s[y + lst])
			++lst;
		lcp[x] = lst;
	}
	--n;
	for (int i = 0; i < n; ++i)
		lcp[i] = lcp[i + 1], p[i] = p[i + 1], --c[i];
	for (int i = 0; i < n; ++i)
		sp[0][i] = {lcp[i], i};
	for (int i = 1; i < LOG; ++i)
		for (int j = 0; j + (1 << i) <= n; ++j) {
			sp[i][j] = min(sp[i - 1][j], sp[i - 1][j + (1 << (i - 1))]);
		}
}


pair<int, int> get(int l, int r) {
	int k = pr[r - l];
	return min(sp[k][l], sp[k][r - (1 << k)]);
}

int b[MAXN];

void run(int l, int r) {
	if (l + 1 == r) {
		return;
	}
	int len = get(l, r - 1).first;
	int cur = l;
	vector<pair<int, int>> vv;
	while (cur + 1 < r) {
		auto tmp = get(cur, r - 1);
		if (tmp.first == len) {
			vv.emplace_back(cur, s[p[cur] + len]);
			cur = tmp.second + 1;
		}
		else {
			break;
		}
	}
	vv.emplace_back(cur, s[p[cur] + len]);
	vv.emplace_back(r, 0);
}

struct str {
	vector<int> rmq;
	void build(int v, int tl, int tr, const vector<pair<int, int>> &vv) {
		if (tl + 1 == tr) {
			rmq[v] = vv[tl].second;
			return;
		}
		int m = (tl + tr) >> 1;
		build(v * 2 + 1, tl, m, vv);
		build(v * 2 + 2, m, tr, vv);
		rmq[v] = min(rmq[v * 2 + 1], rmq[v * 2 + 2]);
	}
	void build(const vector<pair<int, int>> &vv) {
		rmq.resize(vv.size() * 4);
		build(0, 0, vv.size(), vv);
	}
	int gm(int v, int tl, int tr, int l, int r) {
		if (r <= tl || tr <= l)
			return t.size();
		if (l <= tl && tr <= r) {
			return rmq[v];
		}
		int m = (tl + tr) >> 1;
		return min(gm(v * 2 + 1, tl, m, l, r), gm(v * 2 + 2, m, tr, l, r));
	}
};


vector<pair<int, int>> vv[MAXN * 4];

str rmq[MAXN * 4];

int getmin(int v, int tl, int tr, int l, int r, int l1, int r1) {
	if (r <= tl || tr <= l)
		return t.size();
	if (l <= tl && tr <= r) {
		l = lower_bound(vv[v].begin(), vv[v].end(), make_pair(l1, 0)) - vv[v].begin();
		r = lower_bound(vv[v].begin(), vv[v].end(), make_pair(r1, 0)) - vv[v].begin();
		if (l != r) {
			return rmq[v].gm(0, 0, vv[v].size(), l, r);
		}
		else {
			return t.size();
		}
	}
	int m = (tl + tr) >> 1;
	return min(getmin(v * 2 + 1, tl, m, l, r, l1, r1), getmin(v * 2 + 2, m, tr, l, r, l1, r1));
}

void build(int v, int tl, int tr) {
	if (tl + 1 == tr) {
		vv[v].emplace_back(p[tl], tl);
		rmq[v].build(vv[v]);
		return;
	}
	int m = (tl + tr) >> 1;
	build(v * 2 + 1, tl, m);
	build(v * 2 + 2, m, tr);
	merge(ALL(vv[v * 2 + 1]), ALL(vv[v * 2 + 2]), back_inserter(vv[v]));
	rmq[v].build(vv[v]);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cout.setf(ios::fixed), cout.precision(20);
	for (int k = 0; k < LOG; ++k) {
		for (int i = (1 << k); i < (1 << (k + 1)); ++i)
			pr[i] = k;
	}
	cin >> t;
	for (int i = 0; i < t.size(); ++i)
		s[i] = t[i] - 'a' + 1;
	s[t.size()] = 0;
	buildsa(t.size() + 1);
	build(0, 0, t.size());
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int l, r;
		string x;
		cin >> l >> r >> x;
		--l;
		for (int j = 0; j < x.size(); ++j)
			b[j] = x[j] - 'a' + 1;
		b[x.size()] = 0;
		int rb = t.size();
		int lb = 0;
		int ans = t.size();
		for (int j = 0; j <= x.size() && lb < rb; ++j) {
			int llb = lb - 1;
			int rrb = rb;
			while (rrb - llb > 1) {
				int mid = (llb + rrb) >> 1;
				if (s[p[mid] + j] < b[j])
					llb = mid;
				else
					rrb = mid;
			}
			int nlb = rrb;
			llb = lb - 1;
			rrb = rb;
			while (rrb - llb > 1) {
				int mid = (llb + rrb) >> 1;
				if (s[p[mid] + j] > b[j])
					rrb = mid;
				else
					llb = mid;
			}
			int nrb = rrb;
			ans = min(ans, getmin(0, 0, t.size(), nrb, rb, l, r - j));
			lb = nlb;
			rb = nrb;
		}
		if (ans == t.size()) {
			cout << -1 << "\n";
		}
		else {
			int st = p[ans];
			int j = st;
			for (;s[j] == b[j - st]; ++j);
			for (int x = st; x <= j; ++x)
				cout << (char)('a' + s[x] - 1);
			cout  << "\n";
		}
	}
	return 0;
}