// Powered by CP Editor (https://cpeditor.org)

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

const int MX = 1005;
int n, a[MX][MX];

void main_() {
	cin >> n;
	forn (i, n)
		forn (j, n)
			cin >> a[i][j];
	
	int res = 0;
	for (int i = 0; i < 2 * n; i += 4) {
		forn (j, n) {
			if (i - j < 0) break;
			if (i - j < n) {
				res ^= a[i - j][j];
				j++;
			}
		}
	}
	
	forn (i, n)
		reverse(a[i], a[i] + n);
	
	for (int i = 0; i < 2 * n; i += 4) {
		forn (j, n) {
			if (i - j < 0) break;
			if (i - j < n) {
				res ^= a[i - j][j];
				j++;
			}
		}
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}