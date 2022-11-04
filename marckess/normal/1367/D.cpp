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

const int MX = 55;
int n, m, cn[256], b[MX], x;
string s, t;

void solve () {
	cin >> s >> m;
	n = s.size();

	forn (i, m) cin >> b[i];

	memset(cn, 0, sizeof(cn));
	for (char c : s) cn[c]++;

	t = string(m, 0);
	x = 0;

	char ptr = 'z';
	while (x < m) {
		vi pos;
		forn (i, m) if (b[i] == 0) pos.pb(i);

		while (ptr >= 'a' && cn[ptr] < pos.size()) ptr--;

		for (int k : pos) t[k] = ptr;
		ptr--;
		x += pos.size();

		forn (i, m) if (b[i])
			for (int k : pos)
				b[i] -= abs(k - i);

		for (int k : pos)
			b[k] = -1;
	}

	cout << t << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}