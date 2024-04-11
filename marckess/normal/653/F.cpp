#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 500005;
int n, st[4*MX], lz[4*MX], dp[MX];
ll res;
string s;

void push (int i, int j, int pos) {
	if (i < j) {
		lz[pos*2] += lz[pos];
		lz[pos*2+1] += lz[pos];
	}
	st[pos] += lz[pos];
	lz[pos] = 0;
}

void update (int i, int j, int pos, int a, int b, int k) {
	if (lz[pos]) push(i, j, pos);
	if (j < a || b < i) return;
	if (a <= i && j <= b) {
		lz[pos] = k;
		push(i, j, pos);
		return;
	}
	int m = (i + j) / 2;
	update(i, m, pos*2, a, b, k);
	update(m+1, j, pos*2+1, a, b, k);
	st[pos] = min(st[pos*2], st[pos*2+1]);
}

int query (int i, int j, int pos, int a, int b) {
	if (lz[pos]) push(i, j, pos);
	if (j < a || b < i) return 1e9;
	if (a <= i && j <= b) return st[pos];
	int m = (i + j) / 2;
	return min(
		query(i, m, pos*2, a, b),
		query(m+1, j, pos*2+1, a, b)
	);
}

int sa[MX], lcp[MX];

void countingSort (string &s, int ra[], int k) {
	int t_sa[MX] = {0}, c[MX] = {0};
	int sum, n = s.size(), mx = max(300, n);

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
	int t_ra[MX] = {0}, ra[MX] = {0};
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

int cn[MX];
map<int, int> mp;
vi pos[MX], sg[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> s;
	s = 'a' + s;

	for (int i = n; i; i--) {
		update(1, n, 1, i, n, s[i] == '(' ? 1 : -1);

		int l = i, r = n;
		while (l < r) {
			int m = (l + r) / 2;
			int mn = query(1, n, 1, i, m);
			
			if (mn <= 0) r = m;
			else l = m + 1;
		}

		int mn = query(1, n, 1, i, r);
		if (mn == 0) {
			if (dp[r+1]) dp[i] = dp[r+1];
			else dp[i] = r;
		}
	}

	s.push_back(min('(', ')') - 1);
	obtSA(s);
	obtLCP(s);

	mp[0] = 1;
	cn[n + 1] = 0;
	for (int i = n; i; i--)
		cn[i] = cn[i + 1] + (s[i] == '(' ? 1 : -1);

	for (int i = 1; i <= n; i++) {
		if (!dp[sa[i]]) continue;

		int l = sa[i] + lcp[i];
		int r = dp[sa[i]];

		if (l <= r) {
			pos[l+1].pb(cn[sa[i]]);
			sg[l+1].pb(1);

			pos[r+2].pb(cn[sa[i]]);
			sg[r+2].pb(-1);

			//cout << l << " " << r << " " << cn[sa[i]] << endl;
		}
	}

	mp.clear();
	for (int i = n + 1; i; i--) {
		mp[cn[i]]++;
		for (int j = 0; j < pos[i].size(); j++)
			res += mp[pos[i][j]] * sg[i][j];
	}

	cout << res << endl;

	return 0;
}