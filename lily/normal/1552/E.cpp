#include <bits/stdc++.h>
using namespace std;

const int N = 10111;
int n, K, m;
int a[N];
vector <int> c[105], d[105];
int ans[105][2];
bool vis[111];
int main() {
	scanf("%d%d", &n, &K);
	m = n *K;
	for (int i = 1; i <= m; i++) {
		scanf("%d", a + i);
		c[a[i]].push_back(i);
		d[a[i]].push_back(0);
	}
	int upper = (n + K - 2) / (K - 1);
	for (int i = 1; i <= n; i++) {
		int mina = 1e9, id = -1, p = 0;
		for (int j = 1; j <= n; j++) if (!vis[j]) {
			for (int k = 1; k < K; k++) {
				if (d[j][k] < upper) {
		//			cerr << "j" << j << " " << k<< " : " << d[j][k - 1] << " " << d[j][k] << " " << " :: " << c[j][k] << endl;
					if (mina > c[j][k]) {
						mina = c[j][k];
						id = j;
						p = k;
					}
					break;
				}
			}
		}
		assert (id != -1);
		vis[id] = 1;
		ans[id][0] = c[id][p - 1];
		ans[id][1] = c[id][p];
		for (int j = 1; j<= n; j++) {
			for (int k = 1; k < K; k++) {
				if (c[id][p - 1] <= c[j][k] && c[id][p] >= c[j][k - 1]) {
		//			cerr << "!!!" << " " << j << " " << k << endl;
					d[j][k] ++;
				}
			}
		}
	}
	for (int i =1 ; i<= n; i++) {
		printf("%d %d\n", ans[i][0], ans[i][1]);
	}
}