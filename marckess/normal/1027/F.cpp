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

const int MX = 3000005;
int n, z, a[MX], b[MX], p[MX], rk[MX], x[MX], y[MX], inv[MX], q[MX], acu;
vi c;

void init () {
	for (int i = 0; i < MX; i++) {
		p[i] = i;
		rk[i] = 0;
		if (i < n) x[i] = 1, y[i] = 0;
		else x[i] = 0, y[i] = 1;
	}
	acu = n;
}

int find (int a) { 
	return a == p[a] ? a : p[a] = find(p[a]);
}

inline void joint (int a, int b) {
	a = find(a), b = find(b);
	if (a == b) return;

	if (rk[a] < rk[b]) swap(a, b);
	if (rk[a] == rk[b]) rk[a]++;
	p[b] = a;

	if (x[a] > y[a]) acu--;
	if (x[b] > y[b]) acu--;

	x[a] += x[b], y[a] += y[b];
	if (x[a] > y[a]) acu++;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> z;
		a[i*2] = i, b[i*2] = z;
		cin >> z;
		a[i*2+1] = i, b[i*2+1] = z;
	}
	init();

	n *= 2;
	iota(q, q+n, 0);
	sort(q, q+n, [&] (int i, int j){
		return b[i] < b[j];
	});

	int act = -1, ind = n/2;
	for (int i = 0; i < n;) {
		act = b[q[i]];

		while (i < n && act == b[q[i]]) {
			joint(a[q[i]], ind);
			i++;
		}

		ind++;
		if (!acu) {
			cout << act << endl;
			return 0;
		}
	}

	cout << -1 << endl;

	return 0;
}