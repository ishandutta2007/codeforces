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

	int n, m, izq, der, arr, aba, neg = 0;
	char c;
	cin >> n >> m;
	izq = arr = 101;
	der = aba = -1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			if ( c == 'B') {
				izq = min(izq, j);
				der = max(der, j);
				arr = min(arr, i);
				aba = max(aba, i);
				neg++;
			}
		}
	}

	if ( neg == 0 ) {
		cout << 1 << endl;
		return 0;
	}

	int anch = der - izq + 1;
	int alto = aba - arr + 1;
	int lado = max(anch, alto);

	if ( lado > n || lado > m ) {
		cout << -1 << endl;
		return 0;
	}

	cout << lado * lado - neg << endl;

	return 0;
}