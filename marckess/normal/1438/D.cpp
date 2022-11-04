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
typedef pair<ll, ll> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

const int MX = 100005;
int n, a[MX];
vvi res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	forn (i, n) cin >> a[i];
	
	for (int i = 1; i + 1 < n; i += 2) {
		int x = a[0] ^ a[i] ^ a[i + 1];
		a[0] = a[i] = a[i + 1] = x;
		res.pb({0, i, i + 1});
	}
	
	for (int i = 1; i + 1 < n; i += 2) {
		int x = a[0] ^ a[i] ^ a[i + 1];
		a[0] = a[i] = a[i + 1] = x;
		res.pb({0, i, i + 1});
	}
	
	for (int i = 1; i < n; i++)
		if (a[i] != a[i - 1]) {
			cout << "NO" << endl;
			return 0;
		}
	
	cout << "YES" << endl;
	cout << res.size() << endl;
	for (vi &r : res) {
		for (int x : r)
			cout << x + 1 << " ";
		cout << endl;
	}
	
	return 0;
}