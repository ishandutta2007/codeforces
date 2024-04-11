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

typedef vector<vvi> vvvi;
int n, q, c, x1, x2, y, y2, s, t;
vvvi v(12, vvi(105, vi(105, 0)));

void con () {
	for (int l = 0; l < c; l++) 
		for (int i = 1; i <= 100; i++)
			for (int j = 1; j <= 100; j++)
				v[l][i][j] += v[l][i-1][j] + v[l][i][j-1] - v[l][i-1][j-1];
}

int query (int l) {
	return v[l][x2][y2] - v[l][x1-1][y2] - v[l][x2][y-1] + v[l][x1-1][y-1];
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> q >> c;
	c++;

	for (int i = 0; i < n; i++) {
		cin >> x1 >> y >> s;
		v[s][x1][y]++;
	}

	con();

	while (q--) {
		cin >> t >> x1 >> y >> x2 >> y2;
		int res = 0;
		for (int l = 0; l < c; l++)
			res += query(l) * ((l + t) % c);
		cout << res << endl;
	}

	return 0;
}