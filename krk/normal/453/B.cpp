#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn = 105;
const int Maxm = 55;
const int Maxp = 16;
const int Inf = 1000000000;

vector <int> pr[Maxm];
int mask[Maxm];
int ID[Maxm];
int n;
int dp[Maxn][1 << Maxp];
int par[Maxn][1 << Maxp];
int res[Maxn];

int main()
{
	int id = 0;
	for (int i = 2; i < Maxm; i++) {
		int num = i;
		for (int j = 2; j * j <= num; j++)
			if (num % j == 0) {
				pr[i].push_back(j);
				while (num % j == 0) num /= j;
			}
		if (num > 1) {
			pr[i].push_back(num);
			if (num == i) ID[i] = id++;
		}
	}
	for (int i = 2; i < Maxm; i++)
		for (int j = 0; j < pr[i].size(); j++)
			mask[i] |= 1 << ID[pr[i][j]];
	fill((int*)dp, (int*)dp + Maxn * (1 << Maxp), Inf);
	dp[0][0] = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		for (int j = 0; j < 1 << Maxp; j++)
			for (int k = 1; k < Maxm; k++)
				if (!(j & mask[k])) {
					int cand = dp[i][j] + abs(a - k);
					if (cand < dp[i + 1][j | mask[k]]) {
						dp[i + 1][j | mask[k]] = cand;
						par[i + 1][j | mask[k]] = k;
					}
				}
	}
	int bj = 0;
	for (int j = 0; j < 1 << Maxp; j++)
		if (dp[n][j] < dp[n][bj]) bj = j;
	for (int i = n; i > 0; i--) {
		int got = par[i][bj];
		res[i - 1] = got;
		bj ^= mask[got];
	}
	for (int i = 0; i < n; i++)
		printf("%d%c", res[i], i + 1 < n? ' ': '\n');
	return 0;
}