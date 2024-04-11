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

int n, m, a[10005], l, r, x, acu;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> a[i];

	while (m--) {
		cin >> l >> r >> x;

		acu = 0;
		for (int i = l-1; i < r; i++)
			if (a[i] < a[x-1])
				acu++;

		if (l + acu == x)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}

	return 0;
}