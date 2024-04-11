#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

const int maxn = 2e5 + 10;
char s[maxn];
void work() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	if (s[n] != 'B') return printf("NO\n"), void();
	int cnt = 0;
	for (int i = 1; i <= n; ++i) {
		if (s[i] == 'A') cnt++;
		else if (cnt) --cnt;
		else return printf("NO\n"), void();
	}
	printf("YES\n");
}

int main() {
	int t; scanf("%d", &t);
	while (t--) work();
	return 0;
}