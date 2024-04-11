#include <cstdio>
using namespace std;

const int Maxn = 305;

int n;
char B[Maxn][Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf(" %c", &B[i][j]);
	if (B[0][0] == B[0][1]) { printf("NO\n"); return 0; }
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (i == j || i == n - 1 - j) {
				if (B[i][j] != B[0][0]) { printf("NO\n"); return 0; }
			} else if (B[i][j] != B[0][1]) { printf("NO\n"); return 0; }
	printf("YES\n"); 
	return 0;
}