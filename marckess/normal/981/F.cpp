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

const int MX = 200005;
int n, l, a[MX], b[MX];

#define dist(a,b) min(abs((a)-(b)), l - abs((a)-(b)))

bool esPos (int m) {
	int x, y, cn = 0;
	bool f = 1, g = 1;

	x = upper_bound(b, b+n, (a[0] + m) % l) - b - 1;
	if (x < 0) x += n;

	int k = x;
	while (cn < n) {
		if (dist(a[0], b[k]) > m) break;
		cn++;
		y = k;
		k--;
		if (k < 0) k += n;
	}

	for (int i = 0; i < n; i++) {
		while (cn && dist(a[i], b[(i+x+n)%n]) > m) x--, cn--;
		while (cn && dist(a[i], b[(i+y)%n]) > m) y++, cn--;
	}

	return cn;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> l;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];

	sort(a, a+n);
	sort(b, b+n);

	int i = 0, j = l+1, rep = 32;
	while (rep--) {
		int m = (i + j) / 2;
		if (esPos(m)) j = m;
		else i = m;
	}

	cout << j << endl;

	return 0;
}