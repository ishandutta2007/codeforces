#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;
const int Maxm = 62;
const int Maxp = 15;

int bits[1 << Maxp];
int n, m, p;
char B[Maxn][Maxm];
int ans;
char res[Maxm];
int dp[1 << Maxp];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main()
{
	for (int i = 0; i < 1 << Maxp; i++)
		bits[i] = __builtin_popcount(i);
	scanf("%d %d %d", &n, &m, &p);
	for (int i = 0; i < n; i++)
		scanf("%s", B[i]);
	fill(res, res + m, '0');
	for (int t = 0; t < 40; t++) {
		vector <int> seq;
		int ind = uniform_int_distribution<int>(0, n - 1)(rng);
		for (int j = 0; j < m; j++)
			if (B[ind][j] == '1') seq.push_back(j);
		fill((int*)dp, (int*)dp + (1 << int(seq.size())), 0);
		for (int i = 0; i < n; i++) {
			int mask = 0;
			for (int j = 0; j < seq.size(); j++)
				if (B[i][seq[j]] == '1') mask |= 1 << j;
			dp[mask]++;
		}
		for (int j = 0; j < seq.size(); j++)
			for (int i = 0; i < 1 << int(seq.size()); i++)
				if (i & 1 << j) dp[i ^ (1 << j)] += dp[i];
		int nd = (n + 1) / 2;
		for (int i = 0; i < 1 << int(seq.size()); i++)
			if (dp[i] >= nd && bits[i] > ans) {
				ans = bits[i];
				fill(res, res + m, '0');
				for (int j = 0; j < seq.size(); j++)
					if (i & 1 << j) res[seq[j]] = '1';
			}
	}
	res[m] = '\0';
	printf("%s\n", res);
    return 0;
}