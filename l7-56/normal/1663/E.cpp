#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;

int n, flg1, flg2;
char s[110][110];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) scanf("%s", s[i] + 1);
	for (int i = 1; i <= n - 6; ++i)
		for (int j = 1; j <= n - 6; ++j) {
			if (s[i][j] == 't' && s[i + 1][j + 1] == 'h' && s[i + 2][j + 2] == 'e' && s[i + 3][j + 3] == 's'
			&& s[i + 4][j + 4] == 'e' && s[i + 5][j + 5] == 'u' && s[i + 6][j + 6] == 's') return printf("YES\n"), 0;
		}
	printf("NO\n");
	return 0;
}