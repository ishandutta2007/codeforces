#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n;
int B[Maxn][Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		if (n == 1) { printf("1\n"); continue; }
		if (n == 2) { printf("-1\n"); continue; }
		int nxt = 1;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if ((i + j) % 2 == 0) B[i][j] = nxt++;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if ((i + j) % 2 == 1) B[i][j] = nxt++;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				printf("%d%c", B[i][j], j + 1 < n? ' ': '\n');
	}
    return 0;
}