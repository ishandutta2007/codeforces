#include <cstdio>
using namespace std;

const int Maxn = 100005;

int n;
int res[Maxn];

int main()
{
	scanf("%d", &n);
	if (n % 4 > 1) printf("-1\n");
	else {
		int lef = 1, rig = n;
		int l = 0, r = n - 1;
		while (l < r) {
			res[l] = lef + 1, res[l + 1] = rig, res[r - 1] = lef, res[r] = rig - 1;
			l += 2; r -= 2; lef += 2; rig -= 2;
		}
		if (l == r) res[l] = lef;
		for (int i = 0; i < n; i++)
			printf("%d%c", res[i], i + 1 < n? ' ': '\n');
	}
	return 0;
}