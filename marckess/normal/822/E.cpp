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

const int MX = 200010, LMX = 20;
int n, m, x, st[LMX][MX], ps[MX], pt[MX], dp[MX][32];
string s, t, w;

int ra[MX], t_ra[MX], sa[MX], t_sa[MX], lcp[MX], pos[MX], c[MX];

void countingSort (string &s, int k) {
	int sum, n = s.size(), mx = max(300, n);
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

void obtSA (string &s) {
	int r, n = s.size();

	for (int i = 0; i < n; i++) ra[i] = s[i];
	for (int i = 0; i < n; i++) sa[i] = i;

	for (int k = 1; k < n; k <<= 1) {
		countingSort(s, k);
		countingSort(s, 0);

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

void obtLCP (string &s) {
	int phi[MX], plcp[MX], n = s.size();

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

int query (int i, int j) {
	if (i > j) swap(i, j);
	i++;
	int k = log2(j-i+1);
	return min(st[k][i], st[k][j-(1<<k)+1]);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> s >> m >> t >> x;

	w = s + "#" + t + "$";
	obtSA(w);
	obtLCP(w);

	for (int i = 0; i < w.size(); i++) {
		pos[sa[i]] = i;
		st[0][i] = lcp[i];
	}

	for (int j = 1; j < LMX; j++)
		for (int i = 0; i < w.size(); i++)
			st[j][i] = min(st[j-1][i], st[j-1][min((int)w.size()-1, i+(1<<(j-1)))]);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < x; j++) {
			if (dp[i][j] == m) {
				cout << "YES" << endl;
				return 0;
			}
			int d = query(pos[i], pos[n+dp[i][j]+1]);
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			if (d) dp[i+d][j+1] = max(dp[i+d][j+1], dp[i][j]+d);
		}

	for (int j = 1; j <= x; j++)
		if (dp[n][j] == m) {
			cout << "YES" << endl;
			return 0;
		}
	for (int i = 0; i < n; i++)
		if (dp[i][x] == m) {
			cout << "YES" << endl;
			return 0;
		}

	cout << "NO" << endl;

	return 0;
}