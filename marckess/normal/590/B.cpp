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

#define sq(a) ((a)*(a))
typedef complex<ld> cd;

const ld eps = 1e-18;
int x, y, x1, y1, v, t, vx, vy, wx, wy;

bool leq (ld a, ld b) {
	return a < b || fabs(a - b) < eps;
}

bool esPos (ld m) {
	cd from(x, y);
	cd to(x1, y1);

	cd a = from + cd(vx, vy) * min(m, ld(t));

	if (leq(abs(to-a), min(m, ld(t)) * v)) return 1;

	ld d = m - t;
	if (leq(d, 0)) return 0;

	cd b = to + cd(-wx, -wy) * d;
	if (leq(abs(b-a), m * v)) return 1; 

	return 0;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> x >> y >> x1 >> y1 >> v >> t;
	cin >> vx >> vy >> wx >> wy;

	ld i = 0, j = 1e18;
	int rep = 100;

	while (rep--) {
		ld m = (i+j)/2;
		if (esPos(m)) j = m;
		else i = m;
	}

	cout << fixed << setprecision(10) << j << endl;

	return 0;
}