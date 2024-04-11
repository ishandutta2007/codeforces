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

	int n;
	cin >> n;
	if ( n == 1 ) {
		cout << -1 << endl;
		return 0;
	}
	cout << n << " "
		 << n + 1 << " "
		 << n * (n + 1) << endl;

	return 0;
}