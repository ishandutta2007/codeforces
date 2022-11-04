#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef pair<int, int> ii;
typedef vector<ii> vii;

#define fi first
#define se second
#define endl '\n'
#define MOD(n,k) ( (n % k) + k ) % k
#define isOn(S, j) (S & (1 << j) )
#define setBit(S, j) (S |= (1 << j ) )
#define LSB(S) (S & (-S))

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	ll f[3];
	ll n;

	cin >> n;
	f[0] = 0;
	f[1] = 1;

	for (ll i = 2; 1; i++ ) {
		f[i%3] = f[(i-1)%3] + f[(i-2)%3];
		if ( f[i%3] > n ) {
			cout << i - 3 << endl;
			return 0;
		}
	}

	return 0;
}