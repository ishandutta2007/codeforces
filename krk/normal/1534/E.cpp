#include <bits/stdc++.h>
using namespace std;

const int Maxn = 505;

int n, k;
bool dp[Maxn][Maxn];
int par[Maxn][Maxn];
int res;

int Get(set <int> &S)
{
	printf("?");
	for (auto it = S.begin(); it != S.end(); it++)
		printf(" %d", *it);
	printf("\n"); 
	fflush(stdout);
	int res; scanf("%d", &res);
	return res;
}

int main()
{
	scanf("%d %d", &n, &k);
	dp[0][0] = true;
	int ni = -1;
	for (int i = 0; i + 1 < Maxn; i++)
		if (dp[i][n]) { ni = i; break; }
		else for (int j = 0; j < n; j++) if (dp[i][j])
			for (int l = 0; l <= j && l <= k; l++) if (j + k - l <= n) {
				int nj = j - l + k - l;
				if (nj > n) continue;
				if (!dp[i + 1][nj]) {
					dp[i + 1][nj] = true;
					par[i + 1][nj] = l;
				}
			}
	if (ni == -1) {
		printf("-1\n"); fflush(stdout); 
		return 0; 
	}
	set <int> S;
	for (int i = 1; i <= n; i++)
		S.insert(i);
	int nj = n;
	while (ni > 0) {
		int l = par[ni][nj];
		set <int> oth;
		for (int z = 1; z <= n && oth.size() < l; z++) if (S.find(z) == S.end())
			oth.insert(z);
		assert(oth.size() == l);
		set <int> quer = oth;
		for (int z = 0; z < k - l; z++) {
			quer.insert(*S.begin());
			S.erase(S.begin());
		}
		res ^= Get(quer);
		for (auto it = oth.begin(); it != oth.end(); it++)
			S.insert(*it);
		nj += 2 * l - k;
		ni--;
	}
	printf("! %d\n", res);
	fflush(stdout);
    return 0;
}