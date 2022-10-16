#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 1e5 + 5;

int n, cnt[26];

LL g[26][26];

char s[N];

int main() {
	scanf("%s", s + 1); n = strlen(s + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 26; j++) 
			g[j][s[i] - 'a'] += 1ll * cnt[j];
		cnt[s[i] - 'a']++;
	}
	LL ans = 0;
	for (int i = 0; i < 26; i++)
		ans = max(ans, (LL)cnt[i]);
	for (int i = 0; i < 26; i++)
		for (int j = 0; j < 26; j++)
			ans = max(ans, g[i][j]);
	printf("%lld\n", ans);
	return 0;
}