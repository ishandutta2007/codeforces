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
typedef vector<ll> vl;
typedef vector<ii> vii;
 
int n, m, a[1005];
string s[1005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	forn(i, n) cin >> s[i];
	forn(i, m) cin >> a[i];

	ll res = 0;
	forn (i, m) {
		int mx = 0;
		forn (j, 5) {
			int x = 0;
			forn (k, n)
				if (s[k][i] == 'A' + j)
					x++;
			mx = max(mx, x);
		}
		res += mx * a[i];
	}

	cout << res << endl;
 
	return 0;
}