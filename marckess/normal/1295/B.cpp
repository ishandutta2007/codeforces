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

string s;
int cn[256], x, n, t, res;

void solve () {
	cin >> n >> x >> s;

	cn['0'] = 0;
	cn['1'] = 0;

	for (char c : s)
		cn[c]++;

	res = 0;
	t = cn['0'] - cn['1'];
	for (int i = 0, p = 0; i < n; i++) {
		if (s[i] == '0') p++;
		else p--;

		if (t) {
			if ((x - p) % t == 0 && (x - p) / t >= 0)
				res++;
		} else {
			if (p == x)
				res++;
		}
	}

	if (t) {
		if (x == 0) res++;
		cout << res << endl;
	} else {
		if (res) cout << -1 << endl;
		else cout << 0 << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}