#include <cstdio>
using namespace std;

const int Maxn = 52;

int n;
int A[Maxn][Maxn];
int res[Maxn];
bool tk[Maxn];

bool Check(int r, int &val)
{
	val = 0;
	for (int j = 0; j < n; j++)
		if (A[r][j])
			if (val && val != A[r][j]) return false;
			else val = A[r][j];
	return true;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &A[i][j]);
	for (int t = 0; t < n - 1; t++) {
		for (int i = 0; i < n; i++) {
			int got;
			if (!tk[i] && Check(i, got)) {
				tk[i] = true; res[i] = got;
				for (int j = 0; j < n; j++)
					A[j][i] = 0;
				break;
			}
		}
	}
	for (int i = 0; i < n; i++)
		if (!tk[i]) res[i] = n;
	for (int i = 0; i < n; i++)
		printf("%d%c", res[i], i + 1 < n? ' ': '\n');
	return 0;
}