#include <bits/stdc++.h>
using namespace std;

const int Maxn = 305;

int T;
int n;
char B[Maxn][Maxn];

void Solve(int X[], int O[], int all)
{
	for (int i = 0; i < 3; i++) 
		for (int j = 0; j < 3; j++) if (i != j)
			if (X[i] + O[j] <= all / 3) {
				for (int r = 0; r < n; r++) {
					for (int c = 0; c < n; c++)
						if (B[r][c] == 'X' && (r + c) % 3 == i)
							B[r][c] = 'O';
						else if (B[r][c] == 'O' && (r + c) % 3 == j)
							B[r][c] = 'X';
					printf("%s\n", B[r]);
				}
				return;
			}
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		int X[3] = {};
		int O[3] = {};
		int all = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%s", B[i]);
			for (int j = 0; j < n; j++)
				if (B[i][j] == 'X') { X[(i + j) % 3]++; all++; }
				else if (B[i][j] == 'O') { O[(i + j) % 3]++; all++; }
		}
		Solve(X, O, all);
	}
    return 0;
}