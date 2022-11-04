#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MX = 100005;
int n, m, k, l[MX], r[MX], pos[MX], del[3 * MX], mem[3 * MX][1 << 8];
int op[3 * MX], x[3 * MX];
vi c, ini[3 * MX], fin[3 * MX];

int mex (int n) {
	int i = 0;
	while (n & (1 << i))
		i++;
	return i;
}

int dp (int i, int mk) {
	if (i == m) return 0;
	int &res = mem[i][mk];
	if (res != -1) return res;

	if (op[i] == -1) {
		res = x[i] * (__builtin_popcount(mk) & 1) + dp(i + 1, mk & ~del[i]);
	} else {
		res = max(
			dp(i + 1, mk | (1 << x[i])),
			dp(i + 1, mk)
		);
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
		c.pb(l[i]);
		c.pb(r[i] + 1);
	}

	c.pb(0);
	sort(all(c));
	c.erase(unique(all(c)), c.end());

	for (int i = 0; i < n; i++) {
		l[i] = lower_bound(all(c), l[i]) - c.begin();
		r[i] = lower_bound(all(c), r[i] + 1) - c.begin();

		ini[l[i]].pb(i);
		fin[r[i]].pb(i);
	}

	int us = 0;
	m = 0;

	for (int i = 1; i < c.size(); i++) {
		op[m] = -1;
		x[m] = c[i] - c[i - 1];

		for (int j : fin[i]) {
			del[m] |= (1 << pos[j]);
			us &= ~(1 << pos[j]);
		}

		m++;

		for (int j : ini[i]) {
			op[m] = 1;
			x[m] = pos[j] = mex(us);
			us |= (1 << pos[j]);
			m++;
		}
	}

	memset(mem, -1, sizeof(mem));
	cout << dp(0, 0) << endl;

	return 0;
}