#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

string s, res, t;
int n, x;

void solve () {
	cin >> s >> x;
	n = s.size();
	res = string(n, '1');

	forn (i, n)
		if (s[i] == '0')  {
			if (i - x >= 0) res[i - x] = '0';
			if (i + x < n) res[i + x] = '0';
		}

	t = string(n, '0');
	forn (i, n) {
		if (i - x >= 0 && res[i - x] == '1') t[i] = '1';
		if (i + x < n && res[i + x] == '1') t[i] = '1';
	}

	if (s == t) cout << res << endl;
	else cout << -1 << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}