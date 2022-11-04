#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll n, a[100005], s = 0;

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	cout << n + 1 << endl;
	for (int i = n; i > 0; i--) {
		a[i] += s;
		a[i] %= n+1;
		s %= n + 1;

		if (a[i] <= i) {
			cout << 1 << " " << i << " " << i - a[i] << endl;
			s += i - a[i];
		} else {
			cout << 1 << " " << i << " " << i + n + 1 - a[i] << endl;
			s += i + n + 1 - a[i];
		}
	}

	cout << 2 << " " << n << " " << n+1 << endl;

	return 0;
}