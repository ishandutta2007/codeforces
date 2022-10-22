#include <cstdio>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 105;
const int Maxm = 20;

int n;
int s[Maxn];
int m;
char op[Maxm];
int team[Maxm];
int dp[Maxm + 1][1 << Maxm];

bool Less(const int &a, const int &b)
{
	return a > b;
}

int getDP(int id, int mask)
{
	if (id == m) return 0;
	if (dp[id][mask] == Inf) {
		int &res = dp[id][mask];
		if (op[id] == 'p')
			if (team[id] == 1) {
				int j = 0;
				while (mask & 1 << j) j++;
				res = s[j] + getDP(id + 1, mask | 1 << j);
			} else {
				int j = 0;
				while (mask & 1 << j) j++;
				res = -s[j] + getDP(id + 1, mask | 1 << j);
			}
		else if (team[id] == 1) {
				res = getDP(id + 1, mask);
				for (int j = 0; j < m; j++)
					if (!(mask & 1 << j)) res = max(res, getDP(id + 1, mask | 1 << j));
			} else {
				res = getDP(id + 1, mask);
				for (int j = 0; j < m; j++)
					if (!(mask & 1 << j)) res = min(res, getDP(id + 1, mask | 1 << j));
			}
	}
	return dp[id][mask];
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &s[i]);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf(" %c %d", &op[i], &team[i]);
	sort(s, s + n, Less);
	fill((int*)dp, (int*)dp + (Maxm + 1) * (1 << Maxm), Inf);
	printf("%d\n", getDP(0, 0));
	return 0;
}