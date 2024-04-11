#include <bits/stdc++.h>
using namespace std;

int n, m;
char c[120][120];
int mnx, mny, mxx, mxy;

int main() {
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	mnx = n + 1, mxx = 0;
	mny = m + 1, mxy = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cin >> c[i][j];
			if (c[i][j] == 'B') {
				mnx = min(mnx, i), mxx = max(mxx, i);
				mny = min(mny, j), mxy = max(mxy, j);
			}
		}
	}  
	cout << (mnx + mxx) / 2 << ' ' << (mny + mxy) / 2 << '\n';
}