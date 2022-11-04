#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

ll x, y;
ll c1, c2, c3, c4, c5, c6;
ll res;

void solve () {
	cin >> x >> y;
	swap(x, y);
	cin >> c1 >> c2 >> c3 >> c4 >> c5 >> c6;
	
	res = 0;
	if (x < 0) res += -x * c5;
	else res += x * c2;
	if (y < 0) res += -y * c3;
	else res += y * c6;
	
	if (x == y) {
		if (x < 0) res = min(res, -x * c4);
		else res = min(res, x * c1);
	}
	
	ll p = 0;
	if (x < 0) p += -x * c4;
	else p += x * c1;
	if (y < x) p += abs(x - y) * c3;
	else p += abs(x - y) * c6;
	res = min(res, p);
	
	p = 0;
	if (y < 0) p += -y * c4;
	else p += y * c1;
	if (x < y) p += abs(x - y) * c5;
	else p += abs(x - y) * c2;
	res = min(res, p);
	
	cout << res << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t = 1;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}