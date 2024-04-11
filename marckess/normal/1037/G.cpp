#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, q, l, r, sig[MX][26], ant[MX][26];
char dpl[MX][26], dpr[MX][26], acu[MX];
string s;

char mex (int x) {
	for (int i = 0;; i++)
		if (!(x & (1 << i)))
			return i;
}

int query (int l, int r) {
	if (l > r) return 0;

	int res = 0;
	for (int i = 0; i < 26; i++) {
		int lt = sig[l][i];
		int rt = ant[r][i];

		if (lt != -1 && rt != -1 && lt <= r && rt >= l) {
			if (dpl[l][i] == -1) dpl[l][i] = query(l, lt-1);
			if (dpr[r][i] == -1) dpr[r][i] = query(rt+1, r);

			res |= 1 << (acu[lt] ^ acu[rt] ^ dpl[l][i] ^ dpr[r][i]);
		}
	}

	return mex(res);
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	memset(sig, -1, sizeof(sig));
	memset(ant, -1, sizeof(ant));
	memset(dpl, -1, sizeof(dpl));
	memset(dpr, -1, sizeof(dpr));

	cin >> s;
	n = s.size();

	for (int i = 0; i < n; i++) {
		for (int j = 0; i && j < 26; j++)
			ant[i][j] = ant[i-1][j];
		ant[i][s[i] - 'a'] = i;
	}

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < 26; j++)
			sig[i][j] = sig[i+1][j];
		sig[i][s[i] - 'a'] = i;
	}

	for (int i = 1; i < n; i++) {
		int a = ant[i-1][s[i] - 'a'];
		if (a != -1) acu[i] = query(a+1, i-1) ^ acu[a];
	}

	cin >> q;
	while (q--) {
		cin >> l >> r;
		if (query(l-1, r-1)) cout << "Alice" << endl;
		else cout << "Bob" << endl;
	}

	return 0;
}