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

ll n, a[1000005], izqmx[1000005], dermx[1000005], izqmn[1000005], dermn[1000005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];

	stack<ii> mn, mx;
	//Izquierda
	mn.emplace(0, 0); mx.emplace(1e9, 0);
	for (int i = 1; i <= n; i++) {
		while ( mn.top().fi >= a[i] )
			mn.pop();
		while ( mx.top().fi <= a[i] )
			mx.pop();

		izqmn[i] = i - mn.top().se;
		izqmx[i] = i - mx.top().se;

		mn.emplace(a[i], i);
		mx.emplace(a[i], i);
	}

	while ( mn.size() ) mn.pop();
	while ( mx.size() ) mx.pop();

	//Derecha
	mn.emplace(0, n+1); mx.emplace(1e9, n+1);
	for (int i = n; i > 0; i--) {
		while ( mn.top().fi > a[i] )
			mn.pop();
		while ( mx.top().fi < a[i] )
			mx.pop();

		dermn[i] = mn.top().se - i;
		dermx[i] = mx.top().se - i;

		mn.emplace(a[i], i);
		mx.emplace(a[i], i);
	}

	ll res = 0;
	for (int i = 1; i <= n; i++)
		res += a[i] * ( izqmx[i] * dermx[i] - izqmn[i] * dermn[i] );

	cout << res << endl;

	return 0;
}