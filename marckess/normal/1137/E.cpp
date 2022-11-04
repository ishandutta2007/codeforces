#include <bits/stdc++.h>

//#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

struct line {
	ll m, y;
	ll eval (ll x) { return m * x + y; }
};

int q, op, sz;
ll s, b, k, l, n;
line st[300005];

bool f (ll m3, ll y3) {
	ll m1 = st[sz-2].m, y1 = st[sz-2].y;
	ll m2 = st[sz-1].m, y2 = st[sz-1].y;
	return (y2 - y1) / (m1 - m2) < (y3 - y2) / (m2 - m3);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q;
	st[sz++] = {0, 0};

	while (q--) {
		cin >> op >> k;
		if (op == 1) {
			s = b = 0; 
			sz = 1;
			n += k;
		} else if (op == 2) {
			while (sz > 1 && f(n, -b - n * s)) sz--;
			st[sz++] = {n, -b - n * s};
			n += k;
		} else {
			cin >> l;
			b += k, s += l;
		}
		while (sz > 1 && st[sz-1].eval(s) >= st[sz-2].eval(s))
			sz--;
		cout << st[sz-1].m + 1 << " " << st[sz-1].eval(s) + b << endl;
	}

	return 0;
}