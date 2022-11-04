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

ll n, c, x, res = 0;
vector<ll> a;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> x;
		c += x;
		a.push_back(x);
	}

	for (ll i = 1; i * i <= c; i = c / (c / i) + 1) {
		ll sum1 = 0, sum2 = 0, j = c / i;

		for (ll x : a) {
			sum1 += ((x + i - 1) / i) * i;
			sum2 += ((x + j - 1) / j) * j;
		}

		if (sum1 <= c)
			res = max(res, i);
	
		if (sum2 <= c)
			res = max(res, j);
	}

	cout << res << endl;

	return 0;
}