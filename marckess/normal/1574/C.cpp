
// Problem : C. Slay the Dragon
// Contest : Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
// URL : https://codeforces.com/contest/1574/problem/C
// Memory Limit : 256 MB
// Time Limit : 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < int(n); i++)
#define forr(i,a,b) for (int i = int(a); i <= int(b); i++)
#define all(v) v.begin(), v.end()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 200005;
int n, m;
ll a[MX], sum;

ll go (ll a, ll x, ll y) {
	ll res = 0;
	if (a < x) res += x - a;
	if (sum - a < y) res += y - (sum - a);
	return res;
}

void main_() {
	cin >> n;
	
	sum = 0;
	forn (i, n) {
		cin >> a[i];
		sum += a[i];
	}
	sort(a, a + n);
	
	cin >> m;
	while (m--) {
		ll x, y;
		cin >> x >> y;
		
		int i = lower_bound(a, a + n, x) - a;
		
		ll res = x + y;
		if (i < n) res = min(res, go(a[i], x, y));
		if (i) res = min(res, go(a[i - 1], x, y));
		
		cout << res << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	// cin >> t;
	while (t--)
		main_();
	
	return 0;
}