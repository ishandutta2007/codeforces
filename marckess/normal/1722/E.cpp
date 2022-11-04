#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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

const int MX = 1005;
int n, q;
ll acu[MX][MX];

void main_() {
	cin >> n >> q;
	memset(acu, 0, sizeof(acu));
	
	forn (i, n) {
		int x, y;
		cin >> x >> y;
		acu[x][y] += x * y;
	}
	
	forn (i, MX)
	forr (j, 1, MX - 1)
		acu[i][j] += acu[i][j - 1];
	
	while (q--) {
		int hs, ws, hb, wb;
		cin >> hs >> ws >> hb >> wb;
		
		ll res = 0;
		for (int i = hs + 1; i < hb; i++)
			res += acu[i][wb - 1] - acu[i][ws];
		cout << res << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}