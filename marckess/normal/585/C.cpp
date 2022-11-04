#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define FOR(i,n) for (int i = 0; i < n; i++)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;

ll gcd (ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}

int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    ll x, y;
    string res;

	cin >> x >> y;

	if (gcd(x, y) != 1) {
		cout << "Impossible" << endl;
		return 0;
	}

	while (x && y) {
		if (x > y) {
			res += to_string(x / y - int(y == 1)) + "A";
			x %= y;
		} else {
			res += to_string(y / x - int(x == 1)) + "B";
			y %= x;
		}
	}

	cout << res << endl;

    return 0;
}