#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)

typedef long long li;
typedef pair<int, int> pt;

const int N = 1000 * 1000 + 13;

int n;
pair<pt, int> a[N];
vector<int> vals;
vector<pt> ev[N];
pair<li, int> t[4 * N];
li add[4 * N];

void build(int v, int l, int r) {
	if (l == r) {
		t[v] = mp(-vals[l], l);
		add[v] = 0;
		return;
	}
	int m = (l + r) >> 1;
	build(v * 2 + 1, l, m);
	build(v * 2 + 2, m + 1, r);
	t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
}

void push(int v, int l, int r) {
	if (add[v] == 0) return;
	t[v].x += add[v];
	if (l != r) {
		add[v * 2 + 1] += add[v];
		add[v * 2 + 2] += add[v];
	}
	add[v] = 0;
}

void upd(int v, int l, int r, int L, int R, int val) {
	push(v, l, r);
	if (L > R) return;
	if (l == L && r == R) {
		add[v] += val;
		push(v, l, r);
		return;
	}
	int m = (l + r) >> 1;
	upd(v * 2 + 1, l, m, L, min(m, R), val);
	upd(v * 2 + 2, m + 1, r, max(m + 1, L), R, val);
	t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
}

pair<li, int> get(int v, int l, int r, int L, int R) {
	push(v, l, r);
	if (L > R) return mp(-li(1e18), 0);
	if (l == L && r == R) return t[v];
	int m = (l + r) >> 1;
	auto r1 = get(v * 2 + 1, l, m, L, min(m, R));
	auto r2 = get(v * 2 + 2, m + 1, r, max(m + 1, L), R);
	return max(r1, r2);
}

int main() {
	scanf("%d", &n);
	forn(i, n) scanf("%d%d%d", &a[i].x.x, &a[i].x.y, &a[i].y);
	
	forn(i, n) {
		vals.pb(a[i].x.x);
		vals.pb(a[i].x.y);
	}
	
	vals.pb(0);
	sort(all(vals));
	vals.pb(vals.back() + 1);
	
	vals.resize(unique(all(vals)) - vals.begin());
	
	forn(i, n) {
		int x = lower_bound(all(vals), a[i].x.x) - vals.begin();
		int y = lower_bound(all(vals), a[i].x.y) - vals.begin();
		ev[min(x, y)].pb(mp(max(x, y), a[i].y));
	}
	
	n = sz(vals);
	
	build(0, 0, n - 1);
	
	li ans = -1;
	int ansl = -1, ansr = -1;
	
	for (int i = sz(vals) - 1; i >= 0; i--) {
		for (auto it : ev[i]) upd(0, 0, n - 1, it.x, n - 1, it.y);
		auto cur = get(0, 0, n - 1, i, n - 1);
		if (cur.x + vals[i] > ans) {
			ans = cur.x + vals[i];
			ansl = vals[i]; ansr = vals[cur.y]; 
		}
	}
	
	printf("%lld\n%d %d %d %d\n", ans, ansl, ansl, ansr, ansr);
	
}