#include <bits/stdc++.h>
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb push_back
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<ii> vii;

ll n, cn, p;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (ll i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			cn++;
			p = i;
			while (n % i == 0)
				n /= i;
		}
	}
	if (n > 1) {
		p = n;
		cn++;
	}
	if (cn == 1)
		cout << max(p, 1ll) << endl;
	else
		cout << 1 << endl;

	return 0;
}