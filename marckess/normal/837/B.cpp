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

typedef tuple<int, int, int, int, int> iii;

int n, m, mov[] = {1, 0, -1, 0, 0, 1, 0, -1};
char v[105][105];
bitset<105> bs[105];
vi cub(3);
map<char, int> mp = {
	{'R', 0},
	{'G', 1},
	{'B', 2}
};

iii bfs (int i, int j, char col) {
	if (i < 0 || j < 0 || i >= n || j >= m || bs[i][j] || v[i][j] != col)
		return iii(n,0,m,0,0);

	bs[i][j] = 1;

	int x1 = i, x2 = i, y1 = j, y2= j, tam = 1, a, b, c, d, e;
	for (int l = 0; l < 4; l++) {
		tie (a, b, c, d, e) = bfs(i + mov[l*2], j + mov[l*2+1], col);
		x1 = min(x1, a);
		x2 = max(x2, b);
		y1 = min(y1, c);
		y2 = max(y2, d);
		tam += e;
	}

	return iii(x1, x2, y1, y2, tam);
}

bool res () {
	int x1, x2, y1, y2, tam, an, al, c = 0;

	if (n * m % 3)
		return false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!bs[i][j]) {
				tie (x1, x2, y1, y2, tam) = bfs(i, j, v[i][j]);
				an = x2 - x1 + 1;
				al = y2 - y1 + 1;

				if (an * al != tam)
					return false;

				cub[mp[v[i][j]]] += tam;

				if ((x1 != 0 || x2 != n - 1) && (y1 != 0 || y2 != m - 1))
					return false;

				c++;
				if (c > 3)
					return false;
			}
		}
	}

	for (int i = 0; i < 3; i++)
		if (cub[i] != n * m / 3)
			return false;

	return true;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> v[i];

	if (res())
		cout << "YES";
	else
		cout << "NO";	

	return 0;
}