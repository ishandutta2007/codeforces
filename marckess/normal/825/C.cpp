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
#define setBit(S, j) (S | (1 << j ) )
#define LSB(S) (S & (-S))

int n, k, a[1005];

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	sort (a, a+n);
	int res = 0;

	for (int i = 0; i < n; i++) {
		while (k * 2 < a[i]) {
			k *= 2;
			res++;
		}
		k = max (k, a[i]);
	}

	cout << res << endl;

	return 0;
}