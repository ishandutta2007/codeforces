#include <bits/stdc++.h>
using namespace std;

const int N = 505, M = 15;

long long ans = 0;
int a[N * M];
int f[N * M][N];
int F[N], h[M], cnt1[100005], cnt2[100005];
int n, k;

int main() {
	cin >> n >> k;
	for(int i = 1; i <= n * k; i++) scanf("%d", &a[i]), cnt1[a[i]]++;
	for(int i = 1; i <= n; i++) scanf("%d", &F[i]), cnt2[F[i]]++;
	for(int i = 1; i <= k; i++) scanf("%d", &h[i]);
	for(int i = 1; i <= n * k; i++) {
		for(int j = 1; j <= n; j++) {
			for(int t = 1; t <= min(i, k); t++) {
				f[i][j] = max(f[i][j], f[i - t][j - 1] + h[t]);
			}
		}
	}
	for(int i = 1; i <= n * k; i++) {
		for(int j = 1; j <= n; j++) {
			f[i][j] = max(f[i][j], f[i - 1][j]);
			f[i][j] = max(f[i][j], f[i][j - 1]);
		}
	}
	for(int i = 1; i <= 100000; i++) {
		if(cnt2[i]) {
			ans += f[cnt1[i]][cnt2[i]];
		}
	}
	cout << ans << endl;
	return 0;
}