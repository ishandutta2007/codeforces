#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 2e5 + 10;
int n,cnt[30];
char s[maxn];
void work() {
	scanf("%s", s + 1); n = strlen(s + 1);
	for (int i = 0; i < 26; ++i) cnt[i] = 0;
	for (int i = 1; i <= n; ++i) ++cnt[s[i] - 'a'];
	for (int i = 1; i <= n; ++i) {
		if (cnt[s[i] - 'a'] > 1) --cnt[s[i] - 'a'];
		else {
			printf("%s\n", s + i);
			break;
		}
	}
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}