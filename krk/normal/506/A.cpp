#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 30005;
const int Maxm = 615;
const int nil = 305;

int n, d;
int cnt[Maxn];
int cur[Maxn][Maxm];
int res;

int main()
{
	scanf("%d %d", &n, &d);
	while (n--) {
		int pos; scanf("%d", &pos);
		cnt[pos]++;
	}
	fill((int*)cur, (int*)cur + Maxn * Maxm, -Inf);
	cur[d][nil] = cnt[d];
	for (int i = d; i < Maxn; i++)
		for (int j = 0; j < Maxm; j++) if (cur[i][j] != -Inf) {
			res = max(res, cur[i][j]);
			int bas = j - nil + d;
			for (int go = -1; go <= 1 && i + go + bas < Maxn; go++) 
				if (go + bas > 0)
					cur[i + go + bas][j + go] = max(cur[i + go + bas][j + go], cur[i][j] + cnt[i + go + bas]);
		}
	printf("%d\n", res);
	return 0;
}