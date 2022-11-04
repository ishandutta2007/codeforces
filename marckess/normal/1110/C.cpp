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
int a;

bool p2 (int n) {
	return n - (n & -n) == 0;
}

void solve () {
	cin >> a;

	if (p2(a + 1)) {
		int res = 1;

		for (int i = 2; i * i <= a; i++)
			if (a % i == 0) {
				res = max(res, __gcd(a ^ i, a & i));
				res = max(res, __gcd(a ^ (a / i), a & (a / i)));
			}

		cout << res << endl;
	} else {
		for (int i = 0; (1 << i) < a; i++)
			if (!(a & (1 << i)))
				a += 1 << i;
		cout << a << endl;
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