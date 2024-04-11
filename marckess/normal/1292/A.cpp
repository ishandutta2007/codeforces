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
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 100005;
int n, q, a[2][MX], cn;

bool valid (int i, int j) {
	return 0 <= i && i < 2 && 0 <= j && j < n && a[i][j];
}

int main() {
	ios_base::sync_with_stdio(); cin.tie(0);
		
	cin >> n >> q;
	while (q--) {
		int r, c;
		cin >> r >> c;
		--r, --c;

		if (a[r][c]) {
			for (int i = -1; i <= 1; i++) {
				cn -= valid(r-1, c+i);
				cn -= valid(r+1, c+i);
			} 
		} else {
			for (int i = -1; i <= 1; i++) {
				cn += valid(r-1, c+i);
				cn += valid(r+1, c+i);
			}
		}

		a[r][c] ^= 1;
		if (!cn) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}