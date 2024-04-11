
#pragma GCC optimize "-O3"
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
//typedef ull hsh;

const ll MOD = 1e9 + 7;
struct hsh {
	ull a;
	ll b;
	hsh(ll x = 0) {
		a = x;
		b = x;
	}
	hsh(ull x, ll y) {
		a = x;
		b = y % MOD;
	}
	hsh operator+(hsh x) {
		return hsh(a + x.a, b + x.b);
	}
	hsh operator*(hsh x) {
		return hsh(a * x.a, b * x.b);
	}
	hsh operator-(hsh x) {
		return hsh(a - x.a, b - x.b + MOD);
	}
};
bool operator==(hsh a, hsh b) {
	return a.a == b.a && a.b == b.b;
}

bool operator!=(hsh a, hsh b) {
	return a.a != b.a || a.b != b.b;
}

const int MX = 120000;
const int LOG = 20;
const hsh P = 23917;
const int SQ = 300;

char s[MX], t[MX];
int spt[LOG][MX];
int pr[MX];
int bb[MX];
int bc;
int n, m;
hsh hss[MX];
hsh hst[MX];
hsh pw[MX];
int c[MX];
vector<int> vv;
int ans[MX];
vector<tuple<int, int, int, int, int> > go[MX];

hsh gethss(int l, int r) {
	return hss[r] - hss[l] * pw[r - l];
}

hsh gethst(int l, int r) {
	return hst[r] - hst[l] * pw[r - l];
}

int gss(int x, int y) {
	int l = 0;
	int r = min(n - x, n - y) + 1;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (gethss(x, x + mid) == gethss(y, y + mid))
			l = mid;
		else
			r = mid;
	}
	return s[x + l] < s[y + l];
}
int gst(int x, int y) {
	int l = 0;
	int r = min(n - x, m - y) + 1;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (gethss(x, x + mid) == gethst(y, y + mid))
			l = mid;
		else
			r = mid;
	}
	return s[x + l] < t[y + l];
}

int gts(int x, int y) {
	return 1 - gst(y, x);
}

int gtt(int x, int y) {
	int l = 0;
	int r = min(m - x, m - y) + 1;
	while (r - l > 1) {
		int mid = (l + r) >> 1;
		if (gethst(x, x + mid) == gethst(y, y + mid))
			l = mid;
		else
			r = mid;
	}
	return t[x + l] < t[y + l];
}

bool cmp(int x, int y) {
	int fl = 0;
	if (x > y)
		swap(x, y), fl = 1;
	if (x + m <= y) {
		if (hst[m] != gethss(x, x + m)) {
			return gts(0, x) ^ fl;
		}
		else if (gethss(x, x + (y - x - m)) != gethss(x + m, x + m + (y - x - m))) {
			return gss(x, x + m) ^ fl;
		}
		else if (gethss(y - m, y) != hst[m]) {
			return gst(y - m, 0) ^ fl;
		}
		else {
			return (x < y) ^ fl;
		}
	}
	else {
		if (gethst(0, y - x) != gethss(x, y)) {
			return gts(0, x) ^ fl;
		}
		else if (gethst(y - x, m) != gethst(0, m - (y - x))) {
			return gtt(y - x, 0) ^ fl;
		}
		else if (gethss(x, y) != gethst(m - (y - x), m)) {
			return gst(x, m - (y - x)) ^ fl;
		}
		else {
			return (x < y) ^ fl;
		}
	}
}

int mmn(int a, int b) {
	if (a == -1)
		return b;
	if (b == -1)
		return a;
	if (c[a] < c[b])
		return a;
	return b;
}

void build() {
	for (int i = 0; i < bc; ++i)
		spt[0][i] = bb[i];
	for (int i = 1; i < LOG; ++i)
		for (int j = 0; j + (1 << i) <= bc; ++j) {
			spt[i][j] = mmn(spt[i - 1][j], spt[i - 1][j + (1 << (i - 1))]);
		}
}

int get(int l, int r) {
	if (r <= l)
		return -1;
	int k = pr[r - l];
	return mmn(spt[k][l], spt[k][r - (1 << k)]);
}

int q;

int main() {
	pw[0] = 1;
	for (int i = 1; i < MX; ++i)
		pw[i] = (pw[i - 1] * P);
	for (int i = 0; i < LOG; ++i) {
		for (int j = (1 << i); j < (1 << (i + 1)) && j < MX; ++j)
			pr[j] = i;
	}
	scanf("%s %s%d", s, t, &q);
	n = strlen(s);
	m = strlen(t);
	hss[0] = 0;
	for (int i = 0; i < n; ++i)
		hss[i + 1] = hss[i] * P + s[i];
	hst[0] = 0;
	for (int i = 0; i < m; ++i)
		hst[i + 1] = hst[i] * P + t[i];
	for (int i = 0; i <= n; ++i)
		vv.push_back(i);
	sort(vv.begin(), vv.end(), cmp);
	for (int i = 0; i < vv.size(); ++i)
		c[vv[i]] = i;
	for (int i = 0; i < vv.size(); ++i)
		bb[i] = i;
	bc = vv.size();
	build();
	for (int i = 0; i < q; ++i)
		ans[i] = -1;
	for (int i = 0; i < q; ++i) {
		int l, r, k, x, y;
		scanf("%d%d%d%d%d", &l, &r, &k, &x, &y);
		++r;
		if (k >= SQ) {
			int bst = -1;
			int lb = l / k;
			int rb = r / k + 1;
			for (int j = lb; j < rb; ++j)
				bst = mmn(bst, get(max(l, j * k + x), min(r, j * k + y + 1)));
			ans[i] = bst;
		}
		else {
			go[k].push_back(make_tuple(i, l, r, x, y));
		}
	}
	for (int i = 1; i < SQ; ++i) {
		if (go[i].empty())
			continue;
		for (int j = 0; j < i; ++j) {
			bc = 0;
			for (int k = j; k <= n; k += i) {
				bb[bc++] = k;
			}
			build();
			for (auto it: go[i]) {
				int a, l, r, x, y;
				tie(a, l, r, x, y) = it;
				if (j >= x && j <= y)
					ans[a] = mmn(ans[a], get((l - j + i - 1) / i, (r - j + i - 1) / i));
			}
		}
	}
	for (int i = 0; i < q; ++i)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}