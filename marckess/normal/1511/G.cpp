#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

struct wavelet_tree {
	int lo, hi;
	wavelet_tree *l, *r;
	vi b;
	
	wavelet_tree (vi::iterator from, vi::iterator to, int x, int y) {
		lo = x, hi = y;
		if(lo == hi or from >= to) return;
		
		int mid = (lo + hi) / 2;
		
		auto f = [mid] (int x) {
			return x <= mid;
		};
		
		b.reserve(to - from + 1);
		b.pb(0);
		for (auto it = from; it != to; it++)
			b.pb(b.back() + f(*it));
		
		auto pivot = stable_partition(from, to, f);
		l = new wavelet_tree(from, pivot, lo, mid);
		r = new wavelet_tree(pivot, to, mid + 1, hi);
	}
	
	int query (int l, int r, int k) {
		if (l > r || k < lo) return 0;
		if (hi <= k) return r - l + 1;
		
		int lb = b[l-1], rb = b[r];
		return this->l->query(lb + 1, rb, k) + this->r->query(l - lb, r - rb, k);
	}
};

const int MX = 200005;
int n, m, q, c[MX], l[MX], r[MX], x[MX], y[MX], res[MX];
vi a;
wavelet_tree *wt;

int query (int l, int r, int x, int y, int hi) {
	if (x <= y)
		return wt->query(l, r, y) - wt->query(l, r, x - 1);
	return wt->query(l, r, hi) - wt->query(l, r, x - 1) + wt->query(l, r, y);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	forn (i, n)
		cin >> c[i];
	sort(c, c + n);
	
	cin >> q;
	forn (i, q) {
		cin >> l[i] >> r[i];
		x[i] = lower_bound(c, c + n, l[i]) - c; x[i]++;
		y[i] = upper_bound(c, c + n, r[i]) - c;
	}
	
	forn (i, 18) {
		int sz = 1 << i;
		
		a.clear();
		forn (i, n)
			a.pb(c[i] % (2 * sz));
		wt = new wavelet_tree(all(a), 0, 2 * sz - 1);
		
		forn (j, q) {
			if (x[j] > y[j]) continue;
			
			int off = l[j] % (2 * sz);
			int acu = query(
				x[j],
				y[j],
				(off + sz) % (2 * sz),
				(off + 2 * sz - 1) % (2 * sz),
				2 * sz - 1
			);
			
			if (acu & 1)
				res[j] |= sz;
		}
	}
	
	forn (i, q)
		cout << "BA"[bool(res[i])];
	cout << endl;
	
	return 0;
}