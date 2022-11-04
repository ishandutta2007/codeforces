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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, k;
string res, s;

void solve () {
	cin >> n >> k >> s;
	sort(all(s));

	if (s[0] != s[k - 1]) {
		cout << s[k - 1] << endl;
		return;
	}

	if (s[k] != s[n - 1]) {
		cout << s.substr(k - 1) << endl;
		return;
	}

	res.clear();
	for (int i = n - 1; i >= 0; i -= k)
		res.pb(s[i]);
	reverse(all(res));
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