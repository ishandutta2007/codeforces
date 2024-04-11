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
typedef double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 200005;
const ld eps = 1e-9;

bool cero (ld x) { return fabs(x) < eps; }

struct Point {
	ld x, y;
};

int n, q, sy, a, b, l[MX], r[MX], x, y;
ld acu[MX];

ld proy (ld p) { return x - (p - x) / -y * (y - sy); }

bool leq (ld a, ld b) { return cero(a-b) || a < b; }

int izq () {
	int i = 1, j = n+1, rep = 20;

	while (rep--) {
		int m = (i+j)/2;
		if (leq(a, proy(l[m]))) j = m;
		else i = m;
	}

	return j;
}

int der () {
	int i = 1, j = n+1, rep = 20;

	while (rep--) {
		int m = (i+j)/2;
		if (leq(proy(r[m]), b)) i = m;
		else j = m;
	}

	if (j <= n && leq(proy(r[j]), b)) return j;
	if (leq(proy(r[i]), b)) return i;
	return 0;
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);
	//cout << fixed << setprecision(10);

	//cin >> sy >> a >> b >> n;
	scanf("%d%d%d%d", &sy, &a, &b, &n);
	for (int i = 1; i <= n; i++) {
		cin >> l[i] >> r[i];
		acu[i] = acu[i-1] + r[i] - l[i];
	}

	//cin >> q;
	scanf("%d", &q);
	while (q--) {
		//cin >> x >> y;
		scanf("%d%d", &x, &y);

		int i = izq(), j = der();
		
		ld res = 0;
		if (i <= j) res = (acu[j] - acu[i-1]) * (y - sy) / y;

		i--;
		if (i > 0) res += max(0.0, proy(r[i]) - a);
		
		j++;
		if (j <= n) res += max(0.0, b - proy(l[j]));

		//cout << min(res, (ld)b-a) << endl;
		printf("%.10lf\n", min(res, ld(b-a)));
	}

	return 0;
}