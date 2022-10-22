#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 105;

int k;
bool neigh[Maxn][Maxn];
int cur;

int main()
{
	scanf("%d", &k);
	int x = 3;
	while (x * (x - 1) * (x - 2) / 6 <= k) x++;
	x--;
	for (int i = 0; i < x; i++)
		for (int j = i + 1; j < x; j++)
			neigh[i][j] = neigh[j][i] = true;
	cur = x;
	int lft = k - x * (x - 1) * (x - 2) / 6;
	while (lft) {
		for (int i = 0; i < x && i <= lft; i++) {
			neigh[cur][i] = neigh[i][cur] = true;
			lft -= i;
		}
		cur++;
	}
	printf("%d\n", cur);
	for (int i = 0; i < cur; i++) {
		for (int j = 0; j < cur; j++)
			printf("%d", neigh[i][j]);
		printf("\n");
	}
	return 0;
}