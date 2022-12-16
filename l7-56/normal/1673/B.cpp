#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 2e5 + 10;
char s[maxn];
int n,cnt[30];
void work() {
	scanf("%s", s + 1), n = strlen(s + 1);
	for (int i = 0; i < 26; ++i) cnt[i] = 0;
	for (int i = 1; i <= n; ++i) cnt[s[i] - 'a']++;
	for (int u = 0; u < 26; ++u) if (cnt[u])
		for (int v = 0; v < 26; ++v) if (cnt[v]) {
			int mn = 0, sum = 0;
			for (int i = 1; i <= n; ++i) {
				sum += (s[i] - 'a' == u) - (s[i] - 'a' == v);
				if (sum - mn > 1) return printf("NO\n"), void();
				mn = min(mn, sum);
			}
		}
	printf("YES\n");
}

int main() {
	int T; scanf("%d", &T);
	while (T--) work();
	return 0;
}