#include <bits/stdc++.h>

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
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

const int MX = 100005;
int n;
ll a[MX];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	cout << "1 " << max(1, n - 1) << endl;
	for (int i = 1; i <= max(1, n - 1); i++) {
		ll x = MOD(a[i], n);
		ll y = x * max(1, n - 1);

		a[i] += y;
		cout << y << " ";
	}
	cout << endl;

	cout << n << " " << n << endl;
	ll x = MOD(a[n], n);
	a[n] -= x;
	cout << -x << endl;

	cout << 1 << " " << n << endl;
	for (int i = 1; i <= n; i++) {
		cout << -a[i] << " ";
	}
	cout << endl;

	return 0;
}