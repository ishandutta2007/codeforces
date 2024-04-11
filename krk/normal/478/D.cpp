#include <cstdio>
#include <algorithm>
using namespace std;

const int mod = 1000000007;
const int Maxn = 200005;

int r, g;
int ways[2][Maxn];
int cur;
int res;

int main()
{
	scanf("%d %d", &r, &g);
	int h = 1;
	while (h * (h + 1) / 2 <= r + g) h++;
	h--;
	int ex = r + g - (h * (h + 1) / 2);
	ways[0][0] = 1;
	for (int i = 1; i <= h; i++) {
		int to = min(i * (i + 1) / 2, Maxn - 1);
		cur = !cur;
		for (int j = 0; j <= to; j++) {
			if (j < i) ways[cur][j] = ways[!cur][j];
			else ways[cur][j] = (ways[!cur][j] + ways[!cur][j - i]) % mod;
		}
	}
	if (r > g) swap(r, g);
	for (int i = 0; i <= ex && g - i >= 0; i++)
		res = (res + ways[cur][g - i]) % mod;
	printf("%d\n", res);
	return 0;
}