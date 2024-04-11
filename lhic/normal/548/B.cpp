#include <iostream>

using namespace std;
const int maxn = 505;
int a[maxn][maxn];
int q;
int n, m;

inline int mymax(int a, int b) {
	return a > b ? a : b;
}

int main() {
	cin >> n >> m >> q;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> a[i][j];

	for (int u = 0; u < q; u++) {
		int x, y;
		int ans = 0;
		cin >> x >> y;
		int t = 0;
		int maxt = 0;
		a[x-1][y-1] = (a[x - 1][y - 1] + 1)%2;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] != 0)
					t++;
				else
					t = 0;
				maxt = mymax(maxt, t);
			}
			t = 0;
		}
		cout << maxt << '\n';

	}

	return 0;
}