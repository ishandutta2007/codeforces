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
typedef pair<int, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1000005;
string s;
int n, k, res[MX];

vi obtZF (const string &s) {
	int n = s.size();
	vi zf(n);

	for (int i = 1, l = 0, r = 0; i < n; i++) {
		if (i <= r)
			zf[i] = min (r - i + 1, zf[i - l]);

		while (i + zf[i] < n && s[zf[i]] == s[i + zf[i]])
			zf[i]++;
		
		if (i + zf[i] - 1 > r)
			l = i, r = i + zf[i] - 1;
	}

	return zf;
}

vi obtKMP (const string &s) {
	int i = 0, j = -1;
	vi b(n + 1);
	b[0] = -1;

	while (i < n) {
		while (j >= 0 && s[i] != s[j])
			j = b[j];
		i++, j++;
		b[i]= j;
	}

	return b;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> k >> s;

	vi z = obtZF(s);
	vi f = obtKMP(s);
	f.erase(f.begin());

	forn (i, n) {
		int len = i + 1, c = len - f[i];
		if (!c || len % c) continue;

		int rep = len / c;
		if (rep % k) continue;

		res[i]++;
		if (i + 1 < n)
			res[min(n, i + 1 + min(c * (rep / k), z[i + 1]))]--;
	}

	forn (i, n) {
		if (i) res[i] += res[i - 1];
		cout << bool(res[i]);
	}

	cout << endl;

	return 0;
}