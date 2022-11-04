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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int acu[300], cn, res;
string s;

void solve () {
	acu['1'] = acu['2'] = acu['3'] = 0;
	res = 1e9;

	cin >> s;

	int i = 0, j = 0;
	while (i < s.size()) {
		while (j < s.size() && cn < 3) {
			if (!acu[s[j]]) cn++;
			acu[s[j]]++;
			j++;
		}

		if (cn == 3) {
			res = min(res, j - i);
		}

		acu[s[i]]--;
		if (!acu[s[i]]) cn--;
		i++;
	}

	if (res == 1e9) cout << 0 << endl;
	else cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();

	return 0;
}