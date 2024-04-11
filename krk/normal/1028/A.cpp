#include <bits/stdc++.h>
using namespace std;

const int Maxn = 205;

int n, m;
char B[Maxn][Maxn];
int mnr = Maxn, mxr = -Maxn;
int mnc = Maxn, mxc = -Maxn;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", B[i]);
		for (int j = 0; j < m; j++)
			if (B[i][j] == 'B') {
				mnr = min(mnr, i); mxr = max(mxr, i);
				mnc = min(mnc, j); mxc = max(mxc, j);
			}
	}
	printf("%d %d\n", (mnr + mxr) / 2 + 1, (mnc + mxc) / 2 + 1);
	return 0;
}