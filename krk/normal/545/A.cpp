#include <cstdio>
#include <vector>
using namespace std;

const int Maxn = 105;

int n;
int A[Maxn][Maxn];
bool bad[Maxn];
vector <int> res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			scanf("%d", &A[i][j]);
			if (A[i][j] == 1 || A[i][j] == 3) bad[i] = true;
			if (A[i][j] == 2 || A[i][j] == 3) bad[j] = true;
		}
	for (int i = 1; i <= n; i++)
		if (!bad[i]) res.push_back(i);
	printf("%d\n", res.size());
	for (int i = 0; i < res.size(); i++)
		printf("%d%c", res[i], i + 1 < res.size()? ' ': '\n');
	return 0;
}