#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, k, t[MX], ind[MX][52];
ld mem[MX][52], st[MX], inv[MX];
ll acu[MX];

ld sum (int i, int j) {
	ld res = st[j];
	if (i) {
		res -= st[i - 1];
		res -= acu[i - 1] * (inv[j] - inv[i - 1]);
	}
	return res;
}

ld dp (int i, int k, int l, int r) {
	mem[i][k] = sum(i, l) + mem[l + 1][k - 1];
	ind[i][k] = l;

	for (int m = l + 1; m <= r; m++) {
		ld p = sum(i, m) + mem[m + 1][k - 1];
		if (p < mem[i][k]) {
			mem[i][k] = p;
			ind[i][k] = m;
		}
	}

	return mem[i][k];
}

void dp (int i, int j, int l, int r, int k) {
	if (i > j) return;
	if (i == j) mem[i][k] = dp(i, k, l, r);

	int m = (i + j) / 2;
	mem[m][k] = dp(m, k, l, r);

	dp(i, m - 1, l, ind[m][k], k);
	dp(m + 1, j, ind[m][k], r, k);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	cin >> n >> k;
	forn (i, n) {
		cin >> t[i];

		acu[i] = t[i];
		if (i) acu[i] += acu[i - 1];
	
		inv[i] = ld(1) / t[i];
		if (i) inv[i] += inv[i - 1];
	}

	for (int i = 1; i < n; i++) {
		st[i] = ld(1) * acu[i - 1] / t[i];
		st[i] += st[i - 1];
	}

	forn (i, n) mem[i][1] = sum(i, n - 1);

	for (int j = 2; j <= k; j++)
		dp(0, n - 1, 0, n - 1, j);

	cout << n + mem[0][k] << endl;

	return 0;
}