// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005, inf = 2e9;
int n;
vvi a, b;

bool f (vvi &v, vi &ord, int m, int d, int lvl = 0, int x1 = -inf, int y1 = -inf, int x2 = inf, int y2 = inf) {
	if (lvl == 3) return 1;
	int cn = 0;
	
	for (int i = (d == 1 ? 0 : n - 1); 0 <= i && i < n; i += d)
		if (v[i][2] == ord[lvl]) {
			if (v[i][0] < x1 || x2 < v[i][0]) continue;
			if (v[i][1] < y1 || y2 < v[i][1]) continue;
			cn++;
			
			if (cn >= m) {
				int nx1 = &v == &a && d == 1 ? v[i][0] + 1 : x1;
				int ny1 = &v == &b && d == 1 ? v[i][1] + 1 : y1;
				int nx2 = &v == &a && d == -1 ? v[i][0] - 1: x2;
				int ny2 = &v == &b && d == -1 ? v[i][1] - 1: y2;
				
				if (f(&v == &b ? a : b, ord, m, 1, lvl + 1, nx1, ny1, nx2, ny2)) return 1;
				if (lvl) break;
				if (f(v, ord, m, 1, lvl + 1, nx1, ny1, nx2, ny2)) return 1;
				
				break;
			}
		}
	
	return 0;
}

void main_() {
	cin >> n;
	
	forn (i, n) {
		int x, y, c;
		cin >> x >> y >> c;
		a.pb({x, y, c});
		b.pb({x, y, c});
	}
	
	sort(all(a), [&] (const vi &x, const vi &y) {
		return x[0] < y[0];
	});
	
	sort(all(b), [&] (const vi &x, const vi &y) {
		return x[1] < y[1];
	});
	
	int i = 0, j = n / 3, rep = 18;
	while (rep--) {
		int m = (i + j + 1) / 2, esPos = 0;
		
		vi ord = {1, 2, 3};
		do {
			esPos |= f(a, ord, m, 1);
			esPos |= f(a, ord, m, -1);
			esPos |= f(b, ord, m, 1);
			esPos |= f(b, ord, m, -1);
		} while (next_permutation(all(ord)));
		
		if (esPos) i = m;
		else j = m;
	}
	
	cout << 3 * i << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}