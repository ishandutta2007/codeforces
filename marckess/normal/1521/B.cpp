#include <bits/stdc++.h>

//#define endl '\n'
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
int n, a[MX];

void solve () {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	int ind = 1;
	for (int i = 1; i <= n; i++)
		if (a[i] < a[ind])
			ind = i;
	
	vvi res;
	for (int i = ind; i + 1 <= n; i++) {
		res.pb({i, i + 1, a[i] + i - 1, a[i]});
		a[i + 1] = a[i];
		a[i] = a[i + 1] + i - 1;
	}
	
	if (ind > 1) {
		res.pb({ind - 1, n, a[n], a[n] + n - 1});
		a[ind - 1] = a[n];
		a[n] = a[ind - 1] + n - 1;
	} else if (n > 1) {
		res.pb({1, n, a[n], a[n] + n - 1});
	}
	
	for (int i = ind - 2; i >= 1; i--) {
		res.pb({i, i + 1, a[i + 1], a[i + 1] + i + 1 - 1});
		a[i] = a[i + 1];
		a[i + 1] = a[i] + i - 1;
	}
	
	cout << res.size() << endl;
	for (vi v : res) {
		for (int x : v)
			cout << x << " ";
		cout << endl;
	}
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
		
	return 0;
}