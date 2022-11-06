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

int n, m, k;
string s[22], t[22], res[22*22];
int q, y;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m;
	forn(i, n) cin >> s[i];
	forn(i, m) cin >> t[i];

	k = n * m / __gcd(n, m);
	for (int i = 0; i < k; i++)
		res[i] = s[i % n] + t[i % m];

	cin >> q;
	while (q--) {
		cin >> y;
		cout << res[(y - 1) % k] << endl;
	}

	return 0;
}