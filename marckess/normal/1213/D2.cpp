#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb emplace_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

const int MX = 200005, LG = 19;
int n, k, cn[MX][LG], a, res = 1e9;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;

	forn(i, n) {
		cin >> a;
		int t = 0;
		while (a) {
			cn[a][t]++;
			a /= 2, t++;
		}
	}

	forn(i, MX) {
		int s = 0, c = 0;
		for (int j = 0; j < LG; j++) {
			s += cn[i][j] * j;
			c += cn[i][j];
			if (c >= k) {
				s -= (c - k) * j;
				break;
			}
		}
		if (c >= k) res = min(res, s); 
	}
	cout << res << endl;

	return 0;
}