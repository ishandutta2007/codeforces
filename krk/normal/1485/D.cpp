#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;
const int Maxd = 17;

int best[Maxd];
int n, m;
int B[Maxn][Maxn];

bool Check(int x)
{
	int i = 1;
	while (i * i * i * i < x)
		i++;
	return i * i * i * i == x;
}

int main()
{
	int my = 720720;
	for (int i = 1; i <= 16; i++) {
		bool ok = false;
		for (int j = i; j < my && !ok; j += i)
			if (Check(my - j)) { best[i] = j; ok = true; }
	}
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			scanf("%d", &B[i][j]);
			if ((i + j) % 2 == 0) B[i][j] = my;
			else B[i][j] = best[B[i][j]];
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			printf("%d%c", B[i][j], j + 1 < m? ' ': '\n');
    return 0;
}