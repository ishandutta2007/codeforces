#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, d[MX];

void solve () {
	cin >> n;
	forn (i, n)
		cin >> d[i];
	sort(d + 1, d + n);
	
	ll acu = 0, res = 0;
	forn (i, n) {
		if (i) res += d[i] - d[i - 1];
		res -= 1ll * d[i] * i - acu;
		acu += d[i];
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}