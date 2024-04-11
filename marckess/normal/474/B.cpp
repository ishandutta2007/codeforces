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

int n, q, x;
vi a(1e5+5);

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		a[i] = x + a[i-1];
	}

	cin >> q;
	while (q--) {
		cin >> x;
		auto it = lower_bound(a.begin(), a.begin() + n, x);
		cout << it - a.begin() << endl;
	}

	return 0;
}