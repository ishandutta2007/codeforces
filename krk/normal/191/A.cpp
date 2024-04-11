#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxl = 26;

int best[Maxl][Maxl];
int n;
char nam[15];
int res;

int main()
{
	fill((int*)best, (int*)best + Maxl * Maxl, -Inf);
	scanf("%d", &n);
	while (n--) {
		scanf("%s", nam); int len = strlen(nam);
		for (int i = 0; i < Maxl; i++)
			if (best[i][nam[0] - 'a'] != -Inf)
				best[i][nam[len - 1] - 'a'] = max(best[i][nam[len - 1] - 'a'], best[i][nam[0] - 'a'] + len);
		best[nam[0] - 'a'][nam[len - 1] - 'a'] = max(best[nam[0] - 'a'][nam[len - 1] - 'a'], len);
	}
	for (int i = 0; i < Maxl; i++) res = max(res, best[i][i]);
	printf("%d\n", res);
	return 0;
}