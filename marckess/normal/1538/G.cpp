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

int x, y, a, b;

void solve () {
	cin >> x >> y >> a >> b;
	
	if (x > y) swap(x, y);
	if (a > b) swap(a, b);
	
	if (a == b) {
		cout << min(x / a, y / b) << endl;
		return;
	}
	
	int d = x / a, res = 0;
	d = min(d, y / b);
	d = min(d, abs(y - x) / abs(b - a));
	
	x -= d * a;
	y -= d * b;
	res += d;
	
	d = min(x / (a + b), y / (a + b));
	x -= d * (a + b);
	y -= d * (a + b);
	res += 2 * d;
	
	if (x > y) swap(x, y);
	if (a > b) swap(a, b);
	res += min(x / a, y / b);
	
	cout << res << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}