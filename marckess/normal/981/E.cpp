#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 10005, mod = 1e9+7;
int n, q, l, r, x;
int acu[MX];
bitset<MX> res;
vii a;

void add (int x) {
	for (int i = n-x; i >= 0; i--) {
		acu[i+x] += acu[i];
		if (acu[i+x] >= mod) acu[i+x] -= mod;
		if (acu[i+x]) res[i+x] = 1;
	}
}

void remove (int x) {
	for (int i = 0; i <= n-x; i++) {
		acu[i+x] -= acu[i];
		if (acu[i+x] < 0) acu[i+x] += mod;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> q;
	while (q--) {
		cin >> l >> r >> x;
		a.emplace_back(l, x);
		a.emplace_back(r+1, -x);
	}

	sort(all(a));

	acu[0] = 1;
	for (auto x : a)
		if (x.se < 0) remove(-x.se);
		else add(x.se);

	res[0] = 0;
	cout << res.count() << endl;
	for (int i = 1; i <= n; i++)
		if (res[i])
			cout << i << " ";
	cout << endl;

	return 0;
}