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

inline void impr (char c) {
	cout << c << endl << flush;
}

int n, m, mov[] = {1, 0, -1, 0, 0, 1, 0, -1};
char v[105][105];
bitset<105> bs[105];
stack<ii> cam;

map<ii, ii> dir = { 
	{ {1, 0}, {1, 0} },
	{ {-1, 0}, {0, 0} },
	{ {0, 1}, {1, 1} },
	{ {0, -1}, {0, 1} } 
};
map<ii, char> res = {
	{ {1, 0}, 'U' },
	{ {0, 0}, 'D' },
	{ {1, 1}, 'L' },
	{ {0, 1}, 'R' }
};

bool dfs (int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m || bs[x][y] || v[x][y] == '*')
		return false;

	if ( v[x][y] == 'F' ) {
		cam.emplace(x, y);
		return true;
	}

	bs[x][y] = 1;

	for (int i = 0; i < 4; i++)
		if ( dfs(x + mov[2*i], y + mov[2*i+1]) ) {
			cam.emplace(x, y);
			return true;
		}

	return false;
}

void obtRes () {
	int x, y, i = 0, j = 0, eje, ori, rev[2] = {0, 0}, inv[2], x2, y2;
	while ( cam.size() ) {
		tie(x, y) = cam.top(); cam.pop();
		tie(ori, eje) = dir[ii(i-x, j-y)];

		if ( rev[eje] ) {
			impr(res[ii(ori ^ inv[eje], eje)]);
			cin >> x2 >> y2;
		} else {
			impr(res[ii(ori, eje)]);
			cin >> x2 >> y2;
			if ( x2 == i + 1 && y2 == j + 1 ) {
				inv[eje] = 1;
				impr(res[ii(ori ^ inv[eje], eje)]);
				cin >> x2 >> y2;
			} else {
				inv[eje] = 0;
			}
			rev[eje] = 1;
		}
		i = x, j = y;
	}

	return;
}

int main () {
	//ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++)
			cin >> v[i][j];

	dfs(0, 0);
	cam.pop();
	obtRes();

	return 0;
}