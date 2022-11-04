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
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 2005;
int n, m, a[10005], b[10005], cn[MX], res[MX];
bitset<MX> bs[MX];

void solve () {
	cin >> n >> m;
	
	forn (i, n) bs[i].reset(), cn[i] = 0, res[i] = 0;
	
	forn (i, m) {
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
		cn[a[i]]++;
		cn[b[i]]++;
	}
	
	int f = 0;
	forn (i, n) f += cn[i] & 1;
	
	if (!f) {
		cout << 1 << endl;
		forn (i, n) cout << 1 << " ";
		cout << endl;
		return;
	}
	
	forn (i, m) bs[a[i]][b[i]] = bs[b[i]][a[i]] = 1;
	forn (i, n) if (cn[i] & 1) bs[i][i] = 1, bs[i][n] = 1;
	
	for (int i = 0, j = 0; i < n; i++) {
		int ind = -1;
		
		for (int k = j; k < n; k++)
			if (bs[k][i])
				ind = k;
		
		if (ind == -1) continue;
		swap(bs[j], bs[ind]);
		
		forn (k, n)
			if (k != j && bs[k][i])
				bs[k] ^= bs[j];
		
		j++;
	}
	
	forn (i, n) if (bs[i].count()) {
		forn (j, n)
			if (bs[i][j]) {
				res[j] = bs[i][n];
				break;
			}
	}
	
	cout << 2 << endl;
	forn (i, n) cout << res[i] + 1 << " ";
	cout << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}