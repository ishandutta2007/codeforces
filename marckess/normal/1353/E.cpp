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

const int MX = 200005;
int n, k, res, tot;
string s, t;

void solve () {
	cin >> n >> k >> s;

	tot = 0;
	for (char c : s)
		tot += c == '1';

	res = tot;
	forn (i, k) {
		t.clear();
		int mx = 0, acu = 0;

		for (int j = i; j < n; j += k)
			t.pb(s[j]);

		for (char c : t) {
			if (c == '1') acu--;
			else acu++;

			res = min(res, tot + acu - mx);
			mx = max(mx, acu);
		}
	}

	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();	

	return 0;
}