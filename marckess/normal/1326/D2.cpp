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
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 1000005;
int pal[2 * MX], t[2 * MX];
vi izq[2 * MX], der[2 * MX];

void manacher (string &s) {
	int n = s.size(), m = 2 * n - 1;

	for (int i = 0; i < m; i++)
		pal[i] = 0, t[i] = -1;

	for (int i = 0; i < n; i++)
		t[2*i] = s[i];

	int x = 0;
	for (int i = 1; i < m; i++) {
		int &r = pal[i];

		if (i <= x + pal[x])
			r = min(pal[2*x-i], x + pal[x] - i);
		while (i - r - 1 >= 0 && i + r + 1 < m && t[i-r-1] == t[i+r+1])
			r++;
		if (i + r >= x + pal[x])
			x = i;
	}

	for (int i = 0; i < m; i++)
		if (i - pal[i] == 0 || i + pal[i] == m - 1)
			pal[i]++;

	for (int i = 0; i < m; i++) {
		pal[i] /= 2;
		pal[i] = pal[i] + pal[i] + 1 - i % 2;
	}
}

int n;
string S;

void solve () {
	cin >> S;
	manacher(S);
	n = S.size();

	for (int i = 0; i < 2 * n - 1; i++) {
		izq[i].clear();
		der[i].clear();
	}

	for (int i = 0; i < 2 * n - 1; i++) {
		//cout << pal[i] << " ";
		if (!pal[i]) continue;

		if (i < (2 * n - 1) / 2) {
			izq[i - pal[i] + 1].pb(i);
		} else {
			der[i + pal[i] - 1].pb(i);
		}
	}
	//cout << endl;

	int p = -1, s = 2 * n, res = 1, ind = 0, f = 0, off = 1;

	for (int i = 0, j = 2 * n - 2; i <= j; i += 2, j -= 2) {
		for (int k : izq[i]) p = max(p, k);
		for (int k : der[j]) s = min(s, k);
		
		int x = 0;
		if (p >= i) {
			if (p % 2) x = max(x, (p - i + 1));
			else x = max(x, (p - i) + 1);
		}

		if (i + x > res) {
			res = i + x;
			ind = i;
			f = 0;
			off = x;
		}

		x = 0;
		if (s <= j) {
			if (s % 2) x = max(x, j - s + 1);
			else x = max(x, (j - s) + 1);
		}

		if (i + x > res) {
			res = i + x;
			ind = i;
			f = 1;
			off = x;
		}

		if (S[i / 2] != S[j / 2]) break;
	}

	string r;
	forn (i, ind / 2) r.pb(S[i]);

	if (!f) {
		forn (i, off) r.pb(S[ind / 2 + i]);
	}

	reverse(all(S));
	string aux;
	forn (i, ind / 2) aux.pb(S[i]);

	if (f) {
		forn(i, off) aux.pb(S[ind / 2 + i]);
	}

	reverse(all(aux));
	r.insert(r.end(), all(aux));

	cout << r << endl;
	//cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}