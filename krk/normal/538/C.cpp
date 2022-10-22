#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxm = 100005;

int n, m;
int D[Maxm], H[Maxm];
int res;

bool Possible()
{
	for (int i = 0; i + 1 < m; i++)
		if (abs(H[i] - H[i + 1]) > D[i + 1] - D[i])
			return false;
	return true;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &D[i], &H[i]);
		res = max(res, H[i]);
	}
	if (!Possible()) printf("IMPOSSIBLE\n");
	else {
		res = max(res, H[0] + (D[0] - 1));
		for (int i = 0; i + 1 < m; i++)
			res = max(res, (D[i + 1] - D[i] + H[i] + H[i + 1]) / 2);
		res = max(res, H[m - 1] + (n - D[m - 1]));
		printf("%d\n", res);
	}
	return 0;
}