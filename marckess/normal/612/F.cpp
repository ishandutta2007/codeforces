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
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 2005;
int n, s, mem1[MX][2], a[MX], mem2[MX][MX][2], in[MX];
vi c, pos[MX];

int go (int i, int j, int f = 0) {
	int x = (j - i + n) % n;
	if (f) if (x < n - x) cout << "+" << x << endl;
		   else cout << "-" << n - x << endl;
	return min(x, n - x);
}

int dp2 (int i, int j, int f);

int dp1 (int i, int f) {
	if (a[i] + 1 == c.size() && f) return 0;

	int &res = mem1[i][f];
	if (res != -1) return res;
	res = 1e9;

	if (f) {
		for (int j = 0; j < n; j++) 
			if (a[j] == a[i] + 1)
				res = min(res, dp1(j, 0) + go(i, j));
	} else {
		res = dp2(i, i, 0);
	}

	return res;
}

int dp2 (int i, int j, int f) {
	int x = in[i];
	int y = in[j];
	int m = pos[a[i]].size();

	if ((y - x + m) % m + 1 == m) return f ? dp1(j, 1) : dp1(i, 1);

	int &res = mem2[i][j][f];
	if (res != -1) return res;
	res = 1e9;

	int ni = pos[a[i]][(x - 1 + m) % m];
	int nj = pos[a[i]][(y + 1) % m];
	int from = f ? j : i;

	res = min(res, dp2(ni, j, 0) + go(from, ni));
	res = min(res, dp2(i, nj, 1) + go(from, nj));

	return res;
}

void rec2 (int i, int j, int f);

void rec1 (int i, int f) {
	if (a[i] + 1 == c.size() && f) return;

	if (f) {
		for (int j = 0; j < n; j++) 
			if (a[j] == a[i] + 1) {
				if (dp1(j, 0) + go(i, j) == dp1(i, f)) {
					go(i, j, 1);
					return rec1(j, 0);
				}
			}
	} else {
		return rec2(i, i, 0);
	}
}

void rec2 (int i, int j, int f) {
	int x = in[i], y = in[j];
	int m = pos[a[i]].size();

	if ((y - x + m) % m + 1 == m) return f ? rec1(j, 1) : rec1(i, 1);

	int ni = pos[a[i]][(x - 1 + m) % m];
	int nj = pos[a[i]][(y + 1) % m];
	int from = f ? j : i;

	if (dp2(ni, j, 0) + go(from, ni) == dp2(i, j, f)) {
		go(from, ni, 1);
		return rec2(ni, j, 0);
	}

	if (dp2(i, nj, 1) + go(from, nj) == dp2(i, j, f)) {
		go(from, nj, 1);
		return rec2(i, nj, 1);
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(mem1, -1, sizeof(mem1));
	memset(mem2, -1, sizeof(mem2));

	cin >> n >> s;
	s--;

	forn (i, n) {
		cin >> a[i];
		c.pb(a[i]);
	}

	sort(all(c));
	c.erase(unique(all(c)), c.end());

	forn (i, n) {
		a[i] = lower_bound(all(c), a[i]) - c.begin();
		in[i] = pos[a[i]].size();
		pos[a[i]].pb(i);
	}

	int ind, mn = 1e9;

	for (int i = 0; i < n; i++)
		if (!a[i]) {
			int p = dp1(i, 0) + go(s, i);

			if (p < mn) {
				mn = p;
				ind = i;
			}
		}

	cout << mn << endl;
	go(s, ind, 1);
	rec1(ind, 0);

	return 0;
}