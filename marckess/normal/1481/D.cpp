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

const int MX = 1005;
int n, m;
char c[MX][MX];

void solve () {
	cin >> n >> m;
	forn (i, n) cin >> c[i];
	
	if (m & 1) {
		cout << "YES" << endl;
		forn (i, m + 1)
			cout << (i & 1) + 1 << " ";
		cout << endl;
		return;
	}
	
	forn (i, n)
		forn (j, n)
			if (i != j && c[i][j] == c[j][i]) {
				cout << "YES" << endl;
				vi v = {i, j};
				
				forn (k, m + 1)
					cout << v[k & 1] + 1 << " ";
				cout << endl;
				
				return;
			}
	
	forn (i, n) {
		int x = -1, y = -1;
		
		forn (j, n) {
			if (c[i][j] == 'a') x = j;
			if (c[i][j] == 'b') y = j;
		}
		
		if (x != -1 && y != -1) {
			cout << "YES" << endl;
			
			forn (i, m / 2) {
				cout << x + 1 << " ";
				swap(x, y);
			}
			
			cout << i + 1 << " ";
			
			forn (i, m / 2) {
				cout << x + 1 << " ";
				swap(x, y);
			}
			cout << endl;
			return;
		}
	}
	
	cout << "NO" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}