#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)
#define FORR(i,a,b) for (int i = a; i <= b; i++)
#define ALL(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;

const int MX = 1005;
int n, m, q, l, r, a[MX];
string s, t;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> q >> s >> t;

	for (int i = 0; i + m - 1 < n; i++)
		a[i+1] = s.substr(i, m) == t;

	for (int i = 1; i <= n; i++)
		a[i] += a[i-1];

	while (q--) {
		cin >> l >> r;
		r = r - m + 1;
		if (l > r) cout << 0 << endl;
		else cout << a[r] - a[l-1] << endl;
	}

	return 0;
}