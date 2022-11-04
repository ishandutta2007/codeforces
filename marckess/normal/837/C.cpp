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

int a, b, n, x[105], y[105];

int mxPos (int x1, int y1, int x2, int y2) {
	int mx = 0;
	
	if (y1 <= a && y2 <= a && x1 + x2 <= b)
		mx = x1 * y1 + x2 * y2;

	if (x1 <= b && x2 <= b && y1 + y2 <= a)
		mx = x1 * y1 + x2 * y2;

	return mx;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> a >> b;
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];

	int res = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			res = max(res, mxPos (x[i], y[i], x[j], y[j]));
			res = max(res, mxPos (y[i], x[i], x[j], y[j]));
			res = max(res, mxPos (x[i], y[i], y[j], x[j]));
			res = max(res, mxPos (y[i], x[i], y[j], x[j]));

		}
	}

	cout << res << endl;

	return 0;
}