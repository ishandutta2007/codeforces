#include <cstdio>
using namespace std;

const int Maxn = 1005;

int n, m;
char B[Maxn][Maxn];
bool same[Maxn];
int res;

bool canTake(int c)
{
	for (int i = 1; i < n; i++)
		if (same[i] && B[i][c] < B[i - 1][c])
			return false;
	return true;
}

void Take(int c)
{
	for (int i = 1; i < n; i++)
		same[i] = same[i] && (B[i][c] == B[i - 1][c]);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", B[i]);
		same[i] = true;
	}
	for (int j = 0; j < m; j++)
		if (canTake(j)) Take(j);
		else res++;
	printf("%d\n", res);
	return 0;
}