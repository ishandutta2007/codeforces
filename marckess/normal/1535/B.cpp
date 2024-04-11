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
typedef vector<ll> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n;
vi a, b;

void solve () {
	cin >> n;
	
	a.clear();
	b.clear();
	
	forn (i, n) {
		int x;
		cin >> x;
		if (x % 2) a.pb(x);
		else b.pb(x);
	}
	
	int res = a.size() * b.size();
	res += b.size() * (int(b.size()) - 1) / 2;
	
	forn (i, a.size())
		forn (j, i)
			res += __gcd(a[i], a[j]) > 1;
	
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