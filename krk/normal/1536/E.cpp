#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
const int Maxn = 2005;

int T;
int n, m;
char B[Maxn][Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		int res = 1;
		bool zer = false;
		for (int i = 0; i < n; i++) {
			scanf("%s", B[i]);
			for (int j = 0; j < m; j++)
				if (B[i][j] == '#') res = res * 2ll % mod;
				else zer = true;
		}
		if (!zer) res = (res - 1 + mod) % mod;
		printf("%d\n", res);
	}
    return 0;
}