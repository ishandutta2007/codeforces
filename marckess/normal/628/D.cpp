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

const int MX = 2005, mod = 1'000'000'007;
int m, d, a[MX], dp[MX][MX][2], n[MX], res = 0;
string s, t;

void init (string &s) {
	for (int i = 0; i < MX; i++)
		for (int j = 0; j < MX; j++)
			for (int k = 0; k < 2; k++)
				dp[i][j][k] = -1;

	for (int i = 1; i <= s.size(); i++)
		n[i] = s[i-1]-'0';
}

int obtRes (int i, int j, int k) {
	if (i > s.size()) return j == 0;

	int &res = dp[i][j][k];
	if (res != -1) return res;
	res = 0;

	for (int l = 0; l < (k ? 10 : n[i]); l++) {
		if ((l != d) ^ (i % 2 == 0)) {
			res += obtRes(i+1, (j + a[i] * l) % m, 1);
			res %= mod;
		}
	}

	if (!k && ((n[i] != d) ^ (i % 2 == 0))) {
		res += obtRes(i+1, (j + a[i] * n[i]) % m, 0);
		res %= mod;
	}

	return res;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> m >> d >> s >> t;

	for (int i = (int)s.size(), j = 1; i; i--, j = j * 10 % m) a[i] = j;

	init(t);
	res = obtRes(1, 0, 0);

	init(s);
	res -= obtRes(1, 0, 0);

	int x = 0;
	for (int i = 1; i <= s.size(); i++) {
		if ((n[i] != d) ^ (i % 2 == 0)) {
			x = (x + a[i] * n[i]) % m;
		} else {
			x = -1;
			break;
		}
	}

	if (!x) res++;

	cout << MOD(res, mod) << endl;

	return 0;
}