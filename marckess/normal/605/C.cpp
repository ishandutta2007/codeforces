#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

const ld EPS = 1e-12;

int n, q[100010], x[100010], y[100010];
ld a[100010], b[100010];
bitset<100010> us;

int manoDerecha (int a, int b) {
	ll pc = ll(x[a]) * y[b] - ll(x[b]) * y[a];

	if (!pc)
		return 0;
	return pc / abs(pc); 
}

int manoDerechaLD (int o, int x, int y) {
	o = q[o], x = q[x], y = q[y];
	ld pc = (a[x] - a[o]) * (b[y] - b[o]) 
	      - (a[y] - a[o]) * (b[x] - b[o]);
	if (fabs(pc) < EPS)
		return 0;
	return pc / fabs(pc) < 0 ? -1 : 1;
}

void convexHull () {
	vi st;
	for (int i = 0; i < n; i++) {
		while (st.size() > 1 && manoDerechaLD(st[st.size()-2], st.back(), i) != 1) {
			us[q[st.back()]] = 0;
			st.pop_back();
		}
		st.push_back(i);
		us[q[i]] = 1;
	}
}

ld obtRes () {
	ld i = 0, j = 1e6+5, m = (i+j)/2;
	int rep = 60;

	while (rep--) {
		for (int i = 0; i < n; i++) {
			a[i] = x[i] * (i == n-4 ? 1.0L : m);
			b[i] = y[i] * (i == n-4 ? 1.0L : m);
		}
		us.reset();
		convexHull();

		if (us[n-4]) {
			i = m;
		} else {
			j = m;
		}
		m = (i+j)/2;
	}

	return i;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> n;
    cin >> x[n] >> y[n];
    for (int i = 0; i < n; i++)
    	cin >> x[i] >> y[i];

    x[n+1] = *max_element (x, x+n), y[n+1] = 0;
    x[n+2] = 0, y[n+2] = *max_element (y, y+n);
    x[n+3] = 0, y[n+3] = 0;

    n += 4;
    iota (q, q+n, 0);
    sort (q, q+n, [&] (int a, int b) {
    	int d = manoDerecha(a, b);

    	if (!d)
    		return x[a] < x[b];
    	return d == 1;
    });

    cout << fixed << setprecision(8) << obtRes() << endl;

    return 0;
}