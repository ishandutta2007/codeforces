#include<bits/stdc++.h>
#define L(i, j, k) for(int i = (j); i <= (k); ++i)
#define R(i, j, k) for(int i = (j); i >= (k); --i)
#define ll long long
#define vi vector <int>
#define sz(a) ((int) (a).size())
using namespace std;
template < int N > struct fenwt {
	using F = long long ;
	F a[N + 1];
	int n;
	void add (int x, F w) {
		for (; x <= n; x += x & -x) a[x] += w;
	}
	F query (int x) {
		F ret = 0;
		for (; x; x -= x & -x) ret += a[x];
		return ret;
	}
	F get (int l, int r) {
		if(l > r) return 0;
		return query (r) - query (l - 1);
	}
	void clear () {
		L(i, 0, n + 1) a[i] = 0;
	}
} ;

const int N = 1e6 + 7 ;
fenwt < N > val, rk; 
int n, m, p[N], ord[N];
ll t;
int getn (ll Z) {
	int l = 1, r = n, ns = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if(val.query (mid) <= Z) ns = mid, l = mid + 1;
		else r = mid - 1;
	}
	return rk.query (ns);
}
int rkk (int x) { // what is rank x ?
	if (x == 0) return 0;
	x -= 1;
	int l = 1, r = n, ns = 0;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if(rk.query (mid) <= x) ns = mid, l = mid + 1;
		else r = mid - 1;
	}
	return ns + 1;
}
void Main () {
	int ns = 0, nsd = 1;
	cin >> n >> m >> t;
	val.n = rk.n = n;
	L(i, 1, n) cin >> p[i], ord[i] = i;
	sort(ord + 1, ord + n + 1, [&] (int x, int y) {
		return p[x] < p[y];
	}) ;
	L(i, 1, n) {
		int u = ord[i];
		rk.add (u, 1);
		val.add (u, p[u]);
		if((i != n && p[ord[i + 1]] == p[ord[i]]) || p[u] > t) continue;
		int r = getn (t / 2);
		r = (r / m) * m;
		int pos = rkk (r);
		int ret = getn(t - val.query (pos));
		ret = min(ret, r + m);
		if(ret > ns) ns = ret, nsd = p[u];
	}
	cout << ns << ' ' << nsd << '\n';
	rk.clear (), val.clear ();
}
int main () {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T--) Main () ;
	return 0;
}
/*
1
11 1 29
6 4 3 7 5 3 4 7 3 5 3

*/