#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, q, p[MX], st[4 * MX][4][4];
string s;

void update (int i, char c) {
	int pos = i + (1 << int(log2(n) + 1));
	c -= 'a';
	
	memset(st[pos], 0, sizeof(st[pos]));
	forn (j, 3)
		if (j != c)
			st[pos][j][j] = 1;
	st[pos][c][c + 1] = 1;
	
	while (pos /= 2) {
		memset(st[pos], 0, sizeof(st[pos]));
		
		forn (j, 3)
		forn (m, j + 1)
		forn (i, m + 1)
			st[pos][i][j] = max(
				st[pos][i][j], 
				st[pos * 2][i][m] + st[pos * 2 + 1][m][j]
			);
	}
}

void main_() {
	cin >> n >> q >> s;
	
	forn (i, n)
		update(i + 1, s[i]);
	
	while (q--) {
		int i;
		char c;
		cin >> i >> c;
		
		update(i, c);
		
		int mx = 0;
		forn (j, 3)
		forn (i, j + 1)
			mx = max(mx, st[1][i][j]);
		
		cout << n - mx << endl;
	} 
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}