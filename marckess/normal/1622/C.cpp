// Powered by CP Editor (https://cpeditor.org)

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
int n;
ll a[MX], s, k;

ll floor (ll a, ll b) {
	if (a < 0) return a / b - bool(a % b);
	return a / b;
}

void main_() {
	cin >> n >> k;
	
	s = 0;
	forn (i, n) {
		cin >> a[i];
		s += a[i];
	}
	sort(a, a + n);
	
	if (s <= k) {
		cout << 0 << endl;
		return;
	}
	
	s -= a[0];
	ll res = 1e18;
	
	for (int i = 1; i <= n; i++) {
		ll mn = floor(k - s, i);
		ll p = max(0ll, a[0] - mn) + (i - 1);
		res = min(res, p);
		
		s -= a[n - i];
	}
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		main_();
	
	return 0;
}