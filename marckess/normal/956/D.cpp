#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

#include <bits/extc++.h>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;

const int MX = 100005;

int n, w, x[MX], v[MX], qs[MX], qt[MX], f[MX];
ii s[MX], t[MX];
ll res = 0;
map<ii, int> a, b;
ordered_set st;

ll gcd (ll a, ll b) { return b ? gcd(b, a%b) : a; }

bool ls (ii &a, ii &b) { return a.fi * b.se < b.fi * a.se; }

ii cross (int i, int w) {
	int a = -x[i], b = v[i] + w, d = gcd(a, b);
	a /= d, b /= d;
	if (b < 0) a *= -1, b *= -1;
	return {a, b};
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> w;
	FOR(i,n) cin >> x[i] >> v[i];

	FOR(i,n) {
		s[i] = cross(i, w);
		t[i] = cross(i, -w);

		res += a[s[i]]++;
		if (w) res += b[t[i]]++;
	}

	iota(qs, qs+n, 0);
	iota(qt, qt+n, 0);

	sort(qs, qs+n, [&] (int i, int j) {
		if (s[i] == s[j]) return ls(t[i], t[j]);
		return ls(s[i], s[j]);
	});

	sort(qt, qt+n, [&] (int i, int j) {
		if (t[i] == t[j]) return ls(s[i], s[j]);
		return ls(t[i], t[j]);
	});

	FOR(i,n) f[qs[i]] = i+1;

	if (w) {
		for (int i = n-1; i >= 0; i--) {
			res += st.order_of_key(f[qt[i]]);
			st.insert(f[qt[i]]);
		}
	}

	cout << res << endl;

	return 0;
}