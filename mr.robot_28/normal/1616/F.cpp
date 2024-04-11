#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define sz(a) (int)a.size()
const int N = 256;
const int mod = 1e9 + 7;

int F[N][N];
int E[N][N];
int ans[N * N];
int R[N * N];
int C[N * N][300];
int sv[N * N];
int it = 0;

void add_(int a, int b, int c) {
	int r = 0;
	for (auto z : {a, b, c}) {
		if (ans[z] == -1) {
			C[it][z] = 1;
		}
		else {
			r = (r + 3 - ans[z]) % 3;
		}
	}
	R[it] = r;
	it++;
}
signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int test;
	cin >> test;
	while (test--) {
		it = 0;
		int n, m;
		cin >> n >> m;
		memset(E, 0, sizeof E);
		memset(F, 0, sizeof F);
		memset(ans, 0, sizeof ans);
		memset(sv, -1, sizeof sv);
		memset(C, 0, sizeof C);
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			a--;
			b--;
			F[a][b] = F[b][a] = i;
			E[a][b] = E[b][a] = 1;
			ans[i] = c;
			if (ans[i] == 3) {
				ans[i] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				for (int k = j + 1; k < n; k++) {
					if (E[i][j] && E[j][k] && E[k][i]) {
						add_(F[i][j], F[j][k], F[k][i]);
					}
				}
			}
		}
		int p = 0;
		for (int i = 0; i < m; i++) {
			int f = -1;
			for (int j = p; j < it; j++) {
				if (C[j][i]) {
					f = j;
					break;
				}
			}
			if (f == -1) {
				continue;
			}
			for (int j = i; j < m; j++) {
				swap(C[f][j], C[p][j]);
			}
			swap(R[f], R[p]);
			for (int j = p + 1; j < it; j++) {
				if (C[j][i] == 0) {
					continue;
				}
				int t = C[j][i] * C[p][i] % 3;
				for (int k = i; k < m; k++) {
					C[j][k] = (C[j][k] + 3 - C[p][k] * t % 3) % 3;
				}
				R[j] = (R[j] + 3 - R[p] * t % 3) % 3; 
			}
			sv[i] = p;
			p++;
		}
		int fl = 0;
	//	cout << p << " " << it << "\n";
		for (int i = p; i < it; i++) {
			if (R[i]) {
				fl = 1;
				cout << -1 << "\n";
				break;
			}
		}
		if (fl) {
			continue;
		}
		for (int i = m - 1; i >= 0; i--) {
			if (sv[i] == -1) {
				if (ans[i] == -1) {
					ans[i] = 0;
				}
				continue;
			}
			int t = sv[i];
			ans[i] = R[t];
			for (int j = i + 1; j < m; j++) {
				ans[i] = (ans[i] + 3 - ans[j] * C[t][j] % 3) % 3;
			}
			ans[i] = ans[i] * C[t][i] % 3;
		}
		for (int i = 0; i < m; i++) {
			if (ans[i] == 0) {
				ans[i] = 3;
			}
			cout << ans[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}