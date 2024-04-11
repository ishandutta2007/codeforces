#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define find(v,x) (lower_bound(ALL(v), x) - v.begin())

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

int n, c, x, y;

ll esPos (int m) {
	ll res = 0;
	int l = x - m, r = x + m;

	for (int i = 0; i <= m; i++, l++, r--) {
		if (y+i <= n) res += min(r, n) - max(l, 1) + 1;
		if (i && y-i >= 1) res += min(r, n) - max(l, 1) + 1;
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> x >> y >> c;

	int i = 0, j = 1e5, rep = 20;
	while (rep--) {
		int m = (i+j)/2;
		if (esPos(m) >= c) j = m;
		else i = m; 
	}

	cout << j << endl;

	return 0;
}