#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 5005;

int n, m;
char B[Maxn][Maxn];
int H[Maxn][Maxn];
int res;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", B[i]);
		int j = -1;
		for (int l = 0; l < m; l++) if (B[i][l] == '1') {
			if (j < l) j = l;
			while (j < m && B[i][j] == '1') j++;
			H[l][j - 1]++;
		}
	}
	for (int i = 0; i < m; i++) {
		int got = 0;
		for (int j = m - 1; j >= i; j--) if (H[i][j]) {
			got += H[i][j];
			res = max(res, (j - i + 1) * got);
		}
	}
	printf("%d\n", res);
	return 0;
}