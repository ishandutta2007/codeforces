#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair <int, int> pii;
typedef vector <int> vi;
#define fir first
#define sec second

const int maxn = 210;
int n, k, cnt[26], ans[maxn];
char s[maxn];
void work() {
	memset(cnt, 0, sizeof cnt);
	scanf("%d%d%s", &n, &k, s + 1);
	for (int i = 1; i <= n; ++i) cnt[s[i] - 'a']++, ans[i] = 0;
	for (int i = 0; i < 26 && i < n / k; ++i)
		for (int j = 1; j <= k && j <= cnt[i]; ++j) if (ans[j] == i) ++ans[j];
	for (int i = 1; i <= k; ++i) putchar(ans[i] + 'a');
	putchar('\n');
}

int main() {
	int T; scanf("%d", &T);
	while (T--) work();
	return 0;
}