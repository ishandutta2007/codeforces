#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))

typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;

char c[2005][2005];
int n, m, mv[] = {1, 0, -1, 0, 0, 1, 0, -1};
queue<int> h, g;

int esPos (int i, int j) {
	int res = 0;

	if (c[i][j] != '.')
		return 0;

	for (int l = 0; l < 4; l++) {
		int x = i + mv[l*2];
		int y = j + mv[l*2+1];

		if (x < 0 || y < 0 || x >= n || y >= m || c[x][y] != '.')
			continue;
		res++;
	}

	return res;
}

int obtRes () {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (esPos(i, j) == 1) {
				g.push(i);
				h.push(j);
			}
		}
	}

	while (g.size()) {
		int i = g.front(); g.pop();
		int j = h.front(); h.pop();
		bool f = 1;

		if (c[i][j] != '.')
			continue;

		for (int l = 0; l < 4; l++) {
			int x = i + mv[l*2];
			int y = j + mv[l*2+1];

			if (x >= 0 && y >= 0 && x < n && y < m && c[x][y] == '.') {
				f = 0;
				
				if (l == 0) {
					c[i][j] = '^';
					c[x][y] = 'v';
				} else if (l == 1) {
					c[i][j] = 'v';
					c[x][y] = '^';
				} else if (l == 2) {
					c[i][j] = '<';
					c[x][y] = '>';
				} else {
					c[i][j] = '>';
					c[x][y] = '<';
				}

				for (int l = 0; l < 4; l++) {
					if (esPos(i+mv[l*2], j+mv[l*2+1]) == 1) {
						g.push(i+mv[l*2]);
						h.push(j+mv[l*2+1]);
					}
					if (esPos(x+mv[l*2], y+mv[l*2+1]) == 1) {
						g.push(x+mv[l*2]);
						h.push(y+mv[l*2+1]);
					}
				}

				break;
			}
		}

		if (f)
			return 0;
	}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (c[i][j] == '.')
				return 0;

	return 1;
}

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> c[i];

	if (obtRes()) {
		for (int i = 0; i < n; i++)
			cout << c[i] << endl;
	} else {
		cout << "Not unique" << endl;
	}

	return 0;
}