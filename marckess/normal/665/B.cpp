#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 105;
int n, m, k, p[MX], a[MX][MX], res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;
	forn (i, k) cin >> p[i];
	forn (i, n) forn (j, m) {
		cin >> a[i][j];

		int x = 0;
		while (1) {
			res++;
			if (p[x] == a[i][j]) {
				while (x) {
					swap(p[x], p[x - 1]);
					x--;
				}
				break;
			}
			x++;
		}
	}

	cout << res << endl;

	return 0;
}