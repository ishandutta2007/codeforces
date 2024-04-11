#include <cstdio>
using namespace std;

const int Maxn = 105;

int m, n;
int B[Maxn][Maxn];
bool emptyr[Maxn], emptyc[Maxn];
int A[Maxn][Maxn];
bool hasr[Maxn], hasc[Maxn];

int main()
{
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &B[i][j]);
			if (B[i][j] == 0) { emptyr[i] = true; emptyc[j] = true; }
		}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) {
			A[i][j] = emptyr[i] || emptyc[j]? 0: 1;
			if (A[i][j] == 1) { hasr[i] = true; hasc[j] = true; }
		}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (B[i][j] && !hasr[i] && !hasc[j]) { printf("NO\n"); return 0; }
	printf("YES\n");
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			printf("%d%c", A[i][j], j + 1 < n? ' ': '\n');
	return 0;
}