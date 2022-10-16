#include <cstdio>
#include <iostream>
using namespace std;
 
typedef long long LL;
 
const int L = 55;
 
const int INF = 2e9;
 
int n, K, len, ans[L], tmp[L], tot;
 
bool inline cmp() {
	if (tot < len) return true;
	if (tot > len) return false;
	for (int i = len; i; i--) { 
		if (ans[i] < tmp[i]) return false;
		if (ans[i] > tmp[i]) return true;
	}
	return false;
}
 
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		len = INF;
		scanf("%d%d", &n, &K);
		for (int i = 0; i < 10; i++) {
			int jw = 0, s = 0, now = i;
			for (int j = 0; j <= K; j++) {
				s += now % 10;
				if (now >= 10) jw++;
				now++;
			}
			if (s > n) continue;
			if (!jw) {
				if ((n - s) % (K + 1) == 0) {
					int p = (n - s) / (K + 1);
					tmp[1] = i; tot = 1;
					for (int j = 2; p; j++) {
						tmp[j] = min(p, 9);
						p -= min(p, 9);
						tot = j;
					}
					if (cmp()) {
						len = tot;
						for (int j = 1; j <= tot; j++)
							ans[j] = tmp[j];
					}
				}
			} else {
				for (int k = 0; k < 9; k++) {
					int o = k * (K + 1 - jw) + (k + 1) * jw;
					int sum = n - s - o;
					if (sum < 0) continue;
					if (sum % (K + 1) == 0) {
						int p = sum / (K + 1);
						if (!k) tmp[1] = i, tot = 1;
						else tmp[1] = i, tmp[2] = k, tot = 2;
						for (int j = 3; p; j++) {
							tmp[j] = min(p, 9);
							p -= min(p, 9);
							tot = j;
						}
						if (cmp()) {
							len = tot;
							for (int j = 1; j <= tot; j++)
								ans[j] = tmp[j];
						}
					}
				}
			}
		}
		if (len == INF) puts("-1");
		else {
			for (int i = len; i; i--) printf("%d", ans[i]);
			puts(""); 
		}
	}
	return 0;
}