#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 200005;

int n, q, x[MX], num[MX], inv[MX], a, l;

int go (int i) {
	int m = l;
	int j = upper_bound(x, x+n, x[i]+m) - x - 1;
	m -= x[j] - x[i];
	int k = lower_bound(x, x+n, x[j]-m) - x;
	m -= x[j] - x[k];

	if (i != k) {
		l = m;
		return k;
	}

	if (i == j && j == k) return k;

	l %= 2 * (x[j] - x[i]);
	return go(i);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q;
	for (int i = 0; i < n; cin >> x[i++]);
	
	iota(num, num+n, 0);
	sort(num, num+n, [&] (int i, int j) {
		return x[i] < x[j];
	});
	sort(x, x+n);

	for (int i = 0; i < n; i++)
		inv[num[i]] = i;

	while (q--) {
		cin >> a >> l;
		a = inv[a-1];
		while (1) {
			int d = go(a);
			if (d == a) break;
			a = d;
		}
		cout << num[a]+1 << endl;
	}

	return 0;
}