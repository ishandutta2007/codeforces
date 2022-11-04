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

ll n, m, k;

bool esPos (ll x) {
	ll res = 0;
	for (ll i = 1; i <= n; i++)
		res = res + min ( m, (x - 1) / i );
	return res < k;
}

ll obtRes () {
	ll i = 1, j = n * m + 1LL, mit = (i + j) / 2;
	for (int l = 0; l < 40; l++) {
		if ( esPos(mit) )
			i = mit;
		else
			j = mit;
		mit = (i + j) / 2;
	}
	return mit;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> m >> k;
	cout << obtRes() << endl;

	return 0;
}