#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 1005;

int n, k, d;
int res[Maxn][Maxn];

bool Check(int n, int k, int d)
{
	ll cur = 1;
	while (cur < n && d) { cur *= k; d--; }
	return n <= cur;
}

void Solve(int num)
{
	int j = num;
	for (int i = d - 1; i >= 0; i--) {
		int cur = num % k + 1;
		res[i][j] = cur;
		num /= k;
	}
}

int main()
{
	scanf("%d %d %d", &n, &k, &d);
	if (Check(n, k, d)) {
		for (int i = 0; i < n; i++)
			Solve(i);
		for (int i = 0; i < d; i++)
			for (int j = 0; j < n; j++)
				printf("%d%c", res[i][j], j + 1 < n? ' ': '\n');
	} else printf("-1\n");
	return 0;
}