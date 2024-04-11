#include <bits/stdc++.h>
using namespace std;

const int Maxn = 52;

int T;
int n, m;
char B[Maxn][Maxn];
char res[Maxn][Maxn];

bool Solve(char a, char b)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			res[i][j] = (i + j) % 2? a: b;
			if (B[i][j] != '.' && B[i][j] != res[i][j])
				return false;
		}
	return true;
}

void Print()
{
	printf("YES\n");
	for (int i = 0; i < n; i++) {
		res[i][m] = '\0';
		printf("%s\n", res[i]);
	}
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%s", B[i]);
		if (Solve('W', 'R'))
			Print();
		else if (Solve('R', 'W'))
			Print();
		else printf("NO\n");
	}
    return 0;
}