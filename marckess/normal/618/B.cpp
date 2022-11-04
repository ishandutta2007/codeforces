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

int n, a[55][55], res[55];
bitset<55> ex;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> a[i][j];

	ex.set();
	for (int k = 1; k <= n; k++) {
		for (int i = 0; i < n; i++) {
			if (!ex[i]) continue;
			int mx = 0;

			for (int j = 0; j < n; j++) {
				if (i == j || !ex[j]) continue;
				mx = max(mx, a[i][j]);
			}

			if (mx <= k) {
				res[i] = k;
				ex[i] = 0;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}