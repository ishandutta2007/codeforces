#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % abs(k)) + abs(k) ) % abs(k))
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

const int MX = 300005;
int n, a[MX], b[MX], m;
vi v;
ll res[MX];

tuple<ll, ll, ll> extendedGcd(ll a, ll b) {
	if (b == 0) {
		if (a > 0) return {a, 1, 0};
		else return {-a, -1, 0};
	} else {
		auto [d, x, y] = extendedGcd(b, a % b);
		return {d, y, x - y * (a / b)};
	}
}

ll find (ll a, ll b, ll g, ll x1, ll y1, ll ini) {
	ll mx = -1;
	
	forr (t, ini - 5, ini + 5) {
		ll x = x1 + (b / g) * t;
		ll y = y1 - (a / g) * t;
		
		if (0 <= x * a && x * a <= n)
		if (0 <= y * b && y * b <= n)
			mx = max(mx, res[x * a]);
	}
	
	return mx;
}

void main_() {
	cin >> n;
	forn (i, n) {
		cin >> a[i] >> b[i];
		res[0] += b[i];
		v.pb(a[i] - b[i]);
	}
	
	sort(all(v), greater<int>());
	forn (i, n)
		res[i + 1] = res[i] + v[i];
		
	int ind = 0;
	forn (i, n + 1)
		if (res[i] > res[ind])
			ind = i;
	
	cin >> m;
	while (m--) {
		int a, b;
		cin >> a >> b;
		
		auto [g, x0, y0] = extendedGcd(a, b);
		
		if (n % g != 0) {
			cout << -1 << endl;
			continue;
		}
		
		ll x1 = n / g * x0;
		ll y1 = n / g * y0;
		
		ll res = -1;
		res = max(res, find(a, b, g, x1, y1, max( -x1 / (b / g), (n / b - y1) / -(a / g) )));
		res = max(res, find(a, b, g, x1, y1, min( (n / a - x1) / (b / g), -y1 / -(a / g) )));
		res = max(res, find(a, b, g, x1, y1, (ind / a - x1) / (b / g)));
		
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