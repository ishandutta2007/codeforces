#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
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

const int MX = 55;
int n, m;
char c[MX][MX];

void solve () {
	cin >> n >> m;
	forn (i, n)
		cin >> c[i];
	
	char a = 'R', b = 'W';
	forn (kk, 2) {
		int f = 1;
		forn (i, n)
			forn (j, m) {
				if ((i + j) % 2)
					f &= c[i][j] == '.' || c[i][j] == a;
				else
					f &= c[i][j] == '.' || c[i][j] == b;
			}
		
		if (f) {
			cout << "YES" << endl;
			forn (i, n) {
				forn (j, m) {
					if ((i + j) % 2) cout << a;
					else cout << b;
				}
				cout << endl;
			}
			return;
		}
		
		swap(a, b);
	}
	
	cout << "NO" << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}