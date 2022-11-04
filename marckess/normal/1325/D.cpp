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
typedef vector<ii> vii;

const int MX = 1005;
ll a, b, res[MX];
int n;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> a >> b;

	if (b < a || (b % 2 != a % 2)) {
		cout << -1 << endl;
		return 0;
	}

	n = bool(b);
	b -= a;
	res[0] = a;

	if (b) {
		for (int i = 1; i < 60; i++)
			if ((1ll << i) & b) {
				if (res[0] & (1ll << i - 1)) {
					res[1] |= 1ll << i - 1;
					res[2] |= 1ll << i - 1;
					n = 3;
				} else {
					res[0] |= (1ll << i - 1);
					res[1] |= (1ll << i - 1);
					n = max(2, n);
				}
			}
	}

	cout << n << endl;
	for (int i = 0; i < n; i++)
		cout << res[i] << " ";
	cout << endl;

	return 0;
}