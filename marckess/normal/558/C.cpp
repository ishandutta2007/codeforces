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

const int MX = 100000;
int n, x[MX+5], a[MX+5], st[4*MX+20], l2[MX+5];
vi cand;

void build (int i) {
	if (i > MX) return;
	build(i*2);
	build(i*2+1);
	st[i] = a[i] + st[i*2] + st[i*2+1];
}

bool obtCand (int u) {
	if (u > MX) return 0;
	if (st[u] < n) return 0;

	cand.push_back(u);

	if (!obtCand(u*2) && !obtCand(u*2+1)) {
		while (u*2 <= MX) {
			u *= 2;
			cand.push_back(u);
		}
	}

	return 1;
}

int obtRes (int m) {
	int res = 0;

	for (int i = 0; i < n; i++) {
		int u = x[i];

		while (m % u) {
			u /= 2;
			res++;
		}
		while (u < m) {
			u *= 2;
			res++;
		}
		if (u != m) {
			while (1)
				cand.push_back(u);
		}
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
		a[x[i]]++;
	}

	build(1);
	obtCand(1);

	int mn = 1e9;
	for (int x : cand) {
		//cout << x << endl;
		mn = min(mn, obtRes(x));
	}

	cout << mn << endl;

	return 0;
}