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

const int MX = 42;

int n, f[MX], ini, fin;
ll dp[MX][MX];
string s;

void obtKMP () {
	int i = 0, j = -1;
	f[0] = -1;

	while (i < s.size()) {
		while (j >= 0 && s[i] != s[j]) j = f[j];
		i++, j++;
		f[i] = j;
	}
}

int go (int j, char c) {
	while (j >= 0 && c != s[j]) j = f[j];
	return j+1;
}

bool check (int i, int j) {
	for (int l = 0; l < s.size(); l++) {
		j = go(j, s[l]);
		if (j == s.size()) {
			if (i < fin) return 0;
			j = f[j];
		}
		i = (i + 1) % n;
	}
	return 1;
}

void init () {
	forn(i,MX) forn(j,MX)
		dp[i][j] = -1;
}

ll obtRes (int i, int j) {
	if (j == s.size()) j = f[j];
	if (i == ini) return check(i, j);

	ll &res = dp[i][j];
	if (res != -1) return res;
	res = 0;

	int a = go(j, '0'), b = go(j, '1');
	if (a != s.size() || i >= fin) res += obtRes((i+1)%n, a);
	if (b != s.size() || i >= fin) res += obtRes((i+1)%n, b);

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> s;
	obtKMP();

	ll res = 0;

	for (int i = 0; i < n; i++) {
		ini = i, fin = (i + (int)s.size()-1) % n;
		init();
		res += obtRes((fin+1)%n, f[s.size()]);
	}

	cout << res << endl;

	return 0;
}