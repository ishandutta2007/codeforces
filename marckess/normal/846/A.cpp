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

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	int c = 0, u = 0, n, a[105];

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == 1)
			u++;
	}

	int res = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] == 0) {
			c++;
			res = max(res, c+u);
		} else {
			res = max(res, c+u);
			u--;
		}
	}

	cout << res << endl;
	return 0;
}