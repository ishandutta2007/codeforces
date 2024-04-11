#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forab(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, a[MX], q, l, r, x[2*MX], y[2*MX];
int st[4*MX][101], p[MX];
vi c[MX];

void init (int i, int j, int pos) {
	forab (k, 1, 100) st[pos][k] = k;

	if (i == j) {
		p[i] = pos;
		return;
	}

	int m = (i+j)/2;
	init(i, m, pos*2);
	init(m+1, j, pos*2+1);
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);

	scanf("%d", &n);
	forn(i,n) scanf("%d", a+i+1);

	scanf("%d", &q);
	forn(i, q) {
		scanf("%d%d%d%d", &l, &r, x+2*i, y+2*i);
		x[2*i+1] = y[2*i+1] = x[2*i];
		c[l].pb(2*i);
		c[r+1].pb(2*i+1);
	}

	init (1, q, 1);

	forab (i, 1, n) {
		for (int j : c[i]) {
			int pos = p[j/2+1];
			st[pos][x[j]] = y[j];
			pos /= 2;
			while (pos) {
				forab (i, 1, 100) st[pos][i] = st[pos*2+1][st[pos*2][i]];
				pos /= 2;
			}
		}

		printf("%d ", st[1][a[i]]);
	}
	cout << endl;

	return 0;
}