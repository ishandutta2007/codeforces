#include <bits/stdc++.h>

// #define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand (int i, int j) {
	return uniform_int_distribution<int>(i, j)(rng);
}

const int MX = (1 << 18) + 5;
int h, n, cn[MX], x, y;

int query (int u, int v, int w) {
	cout << "? " << u << " " << v << " " << w << endl;
	int r;
	cin >> r;
	if (r == -1) exit(0);
	return r;
}

int main () {
	// ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> h;
	n = (1 << h) - 1;
	
	forn (i, 420) {
		int a = rand(1, n), b, c;
		while (a == (b = rand(1, n)));
		while (a == (c = rand(1, n)) || b == c);
		
		cn[query(a, b, c)]++;
	}
	
	x = 1, y = 2;
	if (cn[x] < cn[y]) swap(x, y);
	
	for (int i = 3; i <= n; i++) {
		if (cn[i] > cn[x]) {
			y = x;
			x = i;
		} else if (cn[i] > cn[y]) {
			y = i;
		}
	}
	
	for (int i = 1; i <= n; i++)
		if (x != i && y != i && query(x, y, i) == i) {
			cout << "! " << i << endl;
			return 0;
		}
	
	return 0;
}