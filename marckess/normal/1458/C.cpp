#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 1005;
int n, m, a[MX][MX], res[MX][MX], off[3];
string s;

void solve () {
	cin >> n >> m;
	forn (i, n)
		forn (j, n)
			cin >> a[i][j];
	cin >> s;
	
	memset(off, 0, sizeof(off));
	vi ord = {0, 1, 2};
	for (char c : s) {
		if (c == 'R')
			off[ord[1]]++;
		if (c == 'L')
			off[ord[1]]--;
		if (c == 'D')
			off[ord[0]]++;
		if (c == 'U')
			off[ord[0]]--;
		if (c == 'I')
			swap(ord[1], ord[2]);
		if (c == 'C')
			swap(ord[0], ord[2]);
	}
	
	forn (i, n)
		forn (j, n) {
			int p[] = {i, j, a[i][j] - 1};
			int r = MOD(p[ord[2]] + off[ord[2]], n) + 1;
			res[MOD(p[ord[0]] + off[ord[0]], n)][MOD(p[ord[1]] + off[ord[1]], n)] = r;
	    }
	
	forn (i, n) {
		forn (j, n)
			cout << res[i][j] << " ";
		cout << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}