#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define read(a) scanf("%d", &a)
#define x first
#define y second

int n, m, K;
int a[4001];
void work() {
	read(n); read(m); read(K);
	for (int i = 1; i <= n; i++) {
		read(a[i]);
	}
	K = min(K, m - 1);
	int left = n - m + 1, ret = 0;
	for (int i = 0; i <= K; i++) {
		int j = K - i;
		int ans = 0x3f3f3f3f;
		for (int k = i + 1; k + left <= n - j + 1; k++) {
			ans = min(ans, max(a[k], a[k + left - 1]));
		}
		ret = max(ret, ans);
	}
	printf("%d\n", ret);

}

int main() {
	int T;
	read(T);
	while (T--) work();

}