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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int MX = 1005;
const ll inf = ll(1e18) + 5;

int sa[MX], lcp[MX], inv[MX];

int t_sa[MX], c[MX];
void countingSort (string &s, int ra[], int k) {
	int sum, n = s.size(), mx = max(300, n);
	memset(t_sa, 0, sizeof(t_sa));
	memset(c, 0, sizeof(c));

	for (int i = 0; i < n; i++)
		c[i+k<n?ra[i+k]:0]++;

	for (int i = sum = 0; i < mx; i++) {
		int t = c[i];
		c[i] = sum;
		sum += t;
	}

	for (int i = 0; i < n; i++)
		t_sa[c[sa[i]+k<n?ra[sa[i]+k]:0]++] = sa[i];

	for (int i = 0; i < n; i++) sa[i] = t_sa[i];
}

int t_ra[MX], ra[MX];
void obtSA (string &s) {
	int r, n = s.size();

	for (int i = 0; i < n; i++) ra[i] = s[i];
	for (int i = 0; i < n; i++) sa[i] = i;

	for (int k = 1; k < n; k <<= 1) {
		countingSort(s, ra, k);
		countingSort(s, ra, 0);

		t_ra[s[0]] = r = 0;

		for (int i = 1; i < n; i++)
			if (ra[sa[i]] == ra[sa[i-1]] && ra[sa[i]+k] == ra[sa[i-1]+k])
				t_ra[sa[i]] = r;
			else
				t_ra[sa[i]] = ++r;

		for (int i = 0; i < n; i++) ra[i] = t_ra[i];
		if (ra[sa[n-1]] == n-1) break;
	}
}

int phi[MX], plcp[MX];
void obtLCP (string &s) {
	int n = s.size();

	phi[sa[0]] = -1;
	for (int i = 1; i < n; i++) phi[sa[i]] = sa[i-1];

	for (int i = 0, l = 0; i < n; i++) {
		if (phi[i] == -1) {
			plcp[i] = 0;
			continue;
		}

		while (s[i+l] == s[phi[i]+l]) l++;

		plcp[i] = l;
		l = max(l-1, 0);
	}

	for (int i = 0; i < n; i++) lcp[i] = plcp[sa[i]];
}

int n, m, adj[MX][MX];
ll mem[MX][MX], acu[MX][MX], k;
string s;

ii find (int k) {
	int i = n, acu = 0;
	while (i > 0 && acu + (n - sa[i] - lcp[i]) < k) {
		acu += (n - sa[i] - lcp[i]);
		i--;
	}

	if (!i) return {-1, -1};
	return {sa[i], n - (k - acu)};
}

bool esPos (int mit) {
	ii act = find(mit);

	if (act.fi == -1) return 1;

	memset(mem, 0, sizeof(mem));
	mem[n][m] = 1;

	for (int i = n - 1; i >= 0; i--) {
		forn (j, m + 1) {
			acu[i + 1][j] = mem[i + 1][j] + acu[i + 2][j];
			if (acu[i + 1][j] > inf) acu[i + 1][j] = inf;
		}

		if (inv[act.fi] > inv[i]) continue;

		int to = i + min(act.se - act.fi, adj[inv[act.fi]][inv[i]]);
		forn (j, m) mem[i][j] = acu[to + 1][j + 1];
	}

	return mem[0][0] >= k;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k >> s;

	s += "$";
	obtSA(s);
	obtLCP(s);	

	forn (i, n + 1) inv[sa[i]] = i;

	forn (i, n + 1) {
		adj[i][i] = 1e9;
		for (int j = i + 1; j <= n; j++)
			adj[i][j] = min(adj[i][j - 1], lcp[j]);
	}

	int i = 1, j = n * (n + 1) / 2, rep = 20;
	while (rep--) {
		int m = (i + j) / 2;
		if (esPos(m)) j = m;
		else i = m;
	}

	ii r = find(j);
	if (r.fi != -1) {
		while (r.fi <= r.se) {
			cout << s[r.fi];
			r.fi++;
		}
		cout << endl;
	}

	return 0;
}