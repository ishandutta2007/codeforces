#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))

int n;
vector<ll> v;
vi pr;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	v = vector<ll>(n+2);
	for (int i = 1; i <= n; i++) {
		cin >> v[i];
		v[i] += v[i-1];
	}

	pr = vi(n+2);
	n++;

	for (int i = 1; i <= n; i++) {
		ll mx = -1e18;
		
		for (int j = i; j <= n; j++) {
			ll x = 0;

			x += v[j-1] - v[i-1];
			x -= v[n-1] - v[j-1];

			if (x > mx) {
				mx = x;
				pr[i] = j;
			}
		}
	}

	ll mx = -1e18, a, b, c;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			ll x = 0;

			x += v[i-1] - v[0];
			x -= v[j-1] - v[i-1];
			x += v[pr[j]-1] - v[j-1];
			x -= v[n] - v[pr[j]-1];

			if (x > mx) {
				mx = x;
				a = i;
				b = j;
				c = pr[j];
			}
		}
	}

	cout << a-1 << " " << b-1 << " " << c-1 << endl;

	return 0;
}