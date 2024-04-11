#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < (n); i++)
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

const int MX = 200005;
int n, a[MX];

void solve () {
	cin >> n;
	forn (i, n)
		cin >> a[i];
	sort(a, a + n);
	
	ll x = 0, y = 0;
	for (int i = n - 1; i >= 0; i -= 2)
		if (a[i] % 2 == 0)
			x += a[i];
	
	for (int i = n - 2; i >= 0; i -= 2)
		if (a[i] % 2 == 1)
			y += a[i];
	
	if (x > y) cout << "Alice" << endl;
	else if (x < y) cout << "Bob" << endl;
	else cout << "Tie" << endl;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
	
	return 0;
}