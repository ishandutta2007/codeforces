#include <cstdio>
#include <algorithm>
using namespace std;

const int Maxn = 1048577;
const int Inf = 2000000000;

int n;
int cnt[Maxn], res[Maxn];
bool tk[Maxn];
int cost[Maxn];
int tmp[Maxn], tlen;
int tres = Inf;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		for (int i = 0; i <= 20; i++) {
			int num = a >> i;
			if (num == 0) continue;
			for (int j = 0; num < Maxn; j++, num *= 2)
				if (!tk[num]) { cost[num] = i + j; tmp[tlen++] = num; tk[num] = true; }
				else if (tk[num]) cost[num] = min(cost[num], i + j);
		}
		for (int j = 0; j < tlen; j++) {
			tk[tmp[j]] = false;
			cnt[tmp[j]]++; res[tmp[j]] += cost[tmp[j]];
		}
		tlen = 0;
	}
	for (int i = 0; i < Maxn; i++)
		if (cnt[i] == n) tres = min(tres, res[i]);
	printf("%d\n", tres);
	return 0;
}