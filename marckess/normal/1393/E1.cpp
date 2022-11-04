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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005, LG = 20, mod = 1000000007;
int sa[MX], lcp[MX], f[MX];

int t_sa[MX], c[MX];
void countingSort (string &s, int ra[], int k) {
	int sum, n = s.size(), mx = max(300, n);
	memset(t_sa, 0, sizeof(t_sa));
	memset(c, 0, sizeof(c));

	forn (i, n) c[i + k < n ? ra[i + k] : 0]++;
	
	sum = 0;
	forn (i, mx) {
		int t = c[i];
		c[i] = sum;
		sum += t;
	}

	forn (i, n) t_sa[c[sa[i] + k < n ? ra[sa[i] + k] : 0]++] = sa[i];
	forn (i, n) sa[i] = t_sa[i];
}

int t_ra[MX], ra[MX];
void obtSA (string &s) {
	int r, n = s.size();

	forn (i, n) ra[i] = s[i];
	forn (i, n) sa[i] = i;

	for (int k = 1; k < n; k <<= 1) {
		countingSort(s, ra, k);
		countingSort(s, ra, 0);

		t_ra[s[0]] = r = 0;

		for (int i = 1; i < n; i++)
			if (ra[sa[i]] == ra[sa[i - 1]] && ra[sa[i] + k] == ra[sa[i - 1] + k])
				t_ra[sa[i]] = r;
			else
				t_ra[sa[i]] = ++r;

		forn (i, n) ra[i] = t_ra[i];
		if (ra[sa[n - 1]] == n - 1) break;
	}
}

int phi[MX], plcp[MX];
void obtLCP (string &s) {
	int n = s.size();

	phi[sa[0]] = -1;
	for (int i = 1; i < n; i++) phi[sa[i]] = sa[i - 1];

	for (int i = 0, l = 0; i < n; i++) {
		if (phi[i] == -1) {
			plcp[i] = 0;
			continue;
		}

		while (s[i+l] == s[phi[i] + l]) l++;

		plcp[i] = l;
		l = max(l - 1, 0);
	}

	forn (i, n) lcp[i] = plcp[sa[i]];
}

int M[MX][LG], logTable[MX];

void pre(int n, int A[]) {
	for (int i = 2; i <= n; i++)
		logTable[i] = logTable[i >> 1] + 1;
	
	forn (i, n) M[i][0] = A[i];

	for(int j = 1; (1 << j) <= n; j++)
		forn (i, n - (1 << j) + 1)
			M[i][j] = min(M[i][j - 1], M[i + (1 << (j - 1))][j - 1]);
}

inline int query (int i, int j) {
	if (i > j) return 1e9;
	int k = logTable[j - i + 1];
	return min(M[i][k], M[j - (1 << k) + 1][k]);
}

int n, m, ini[100005], cn[100005];
string in[100005], s;
vii v;

inline int leq (int i, int a, int j, int b, int len) {
	int x = f[ini[i] + a];
	int y = f[ini[j] + b];

	if (x < y && query(x + 1, y) < len) return 1;
	if (x > y && query(y + 1, x) < len) return -1;
	return 0;
}

inline bool comp (int afi, int ase, int bfi, int bse) {
	int sa = in[afi].size(), sb = in[bfi].size();
	int f = leq(afi, 0, bfi, 0, min(ase, bse));

	if (f == 1) return 1;
	if (f == -1) return 0;

	if (ase < bse) f = leq(afi, ase + 1, bfi, ase, min(bse, sa - 1) - ase);
	if (ase > bse) f = leq(afi, bse, bfi, bse + 1, min(ase, sb - 1) - bse);

	if (f == 1) return 1;
	if (f == -1) return 0;

	int to = max(ase, bse);
	f = leq(afi, to + 1, bfi, to + 1, min(sa, sb) - (to + 1));

	if (f == 1) return 1;
	if (f == -1) return 0;

	if (ase < sa) sa--;
	if (bse < sb) sb--;

	return sa <= sb;
}

int dp[2][MX];
vi ord[100005];

void sum (int &a, int b) {
	a += b;
	if (a >= mod) a -= mod;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) {
		cin >> in[i];

		ini[i] = s.size();
		s += in[i];

		forn (j, in[i].size() + 1) v.emplace_back(i, j);
	}


	s += '#';
	m = s.size();

	obtSA(s);
	obtLCP(s);
	pre(m, lcp);
	forn (i, m) f[sa[i]] = i;

	forn (i, n) {
		ord[i].resize(in[i].size() + 1);

		int l = 0, r = (int)in[i].size(), j = 0;

		while (j < in[i].size()) {
			int to = j;

			while (to < in[i].size() && in[i][j] == in[i][to]) to++;

			while (j < to) {
				if (to == in[i].size() || in[i][j] > in[i][to]) ord[i][l++] = j++;
				else ord[i][r--] = j++;
			}
		}

		ord[i][l] = in[i].size();
	}

	int x = 0, y = 1;
	fill(dp[x], dp[x] + ord[0].size(), 1);

	forn (i, n - 1) {
		int j = 0;

		forn (k, ord[i + 1].size()) {
			if (k) dp[y][k] = dp[y][k - 1];
			else dp[y][k] = 0;

			while (j < ord[i].size() && comp(i, ord[i][j], i + 1, ord[i + 1][k]))
				sum(dp[y][k], dp[x][j++]);
		}

		swap(x, y);
	}

	int res = 0;
	forn (i, ord[n - 1].size())
		sum(res, dp[x][i]);
	cout << res << endl;
	
	return 0;
}