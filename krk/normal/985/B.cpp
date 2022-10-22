#include <bits/stdc++.h>
using namespace std;

const int Maxn = 2005;

int n, m;
char B[Maxn][Maxn];
int has[Maxn];

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", B[i]);
		for (int j = 0; j < m; j++)
			has[j] += B[i][j] == '1';
	}
	for (int i = 0; i < n; i++) {
		bool ok = true;
		for (int j = 0; j < m && ok; j++)
			ok = has[j] - (B[i][j] == '1') > 0;
		if (ok) { printf("YES\n"); return 0; }
	}
	printf("NO\n");
	return 0;
}