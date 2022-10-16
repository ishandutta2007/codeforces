#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

typedef long long LL;

const int N = 200005;

int n, K, cnt[N], c[N], L[N], R[N];

int ans = 0, last = 0;

vector<int> res[N];

int main() {
	scanf("%d%d", &n, &K);
	for (int i = 1, x; i <= n; i++) scanf("%d", &x), cnt[x]++;
	for (int i = 1; i <= K; i++) scanf("%d", c + i);
	
	for (int i = K; i; i--) {
		int l = 1, r = ans;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (res[mid].size() == c[i]) l = mid + 1;
			else r = mid;
		}
		for (int j = l; ; j++) {
			int k = min(cnt[i], c[i] - (int)res[j].size());
			for (int u = 0; u < k; u++)
				res[j].push_back(i);
			cnt[i] -= k;
			ans = max(ans, j);
			if (cnt[i] == 0) break;
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= ans; i++) {
		printf("%d ", (int)res[i].size());
		for (int j = 0; j < res[i].size(); j++) printf("%d ", res[i][j]);
		puts("");
	}
	return 0;
}