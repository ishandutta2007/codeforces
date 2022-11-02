#include <iostream>
#include <cstdio>

using namespace std;

const int N = 200005;

int n, K, f[N], cnt[N][26];
char s[N];


int find(int x) {
	return x == f[x] ? x : f[x] = find(f[x]);
}
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d%s", &n, &K, s + 1);
		for (int i = 1; i <= n; i++) {
			f[i] = i;
			for (int j = 0; j < 26; j++)
				cnt[i][j] = 0;
		}
		for (int i = 1; i <= K; i++) {
			for (int j = i; j <= n; j += K) {
				if (j + K <= n) f[find(j)] = find(j + K);
			}
		}
		for (int i = 1; i * 2 <= n; i++) {
			f[find(i)] = find(n - i + 1);
		}

		int ans = 0;
		for (int i = 1; i <= n; i++) {
			cnt[find(i)][s[i] - 'a']++;
		}

		for (int i = 1; i <= n; i++) {
			if (find(i) == i) {
				int s = 0, v = 0;
				for (int j = 0; j < 26; j++) 
					s += cnt[i][j], v = max(v, cnt[i][j]);
				ans += s - v;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}