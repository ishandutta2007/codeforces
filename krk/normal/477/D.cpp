#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 5005;
const int mod = 1000000007;
const int Inf = 1000000000;

char X[Maxn];
int xlen;
ii cst[Maxn][Maxn];
int dp[Maxn][Maxn];

int Compar(int a, int alen, int b, int blen)
{
	if (alen != blen) return alen < blen? -1: 1;
	if (alen <= cst[a][b].first) return 0;
	return cst[a][b].second;
}

string Add(string s, int num)
{
	int car = 0;
	for (int i = s.length() - 1; i >= 0 && (num || car); i--) {
		car += (s[i] == '1') + (num & 1); num /= 2;
		s[i] = car % 2 + '0';
		car /= 2;
	}
	while (num || car) {
		car += (num & 1); num /= 2;
		s = string(1, car % 2 + '0') + s;
		car /= 2;
	}
	return s;
}

int getMinimum()
{
	fill((int*)dp, (int*)dp + Maxn * Maxn, Inf);
	for (int i = 0; i < xlen; i++)
		dp[0][i] = 1;
	for (int i = 1; i < xlen; i++) if (X[i] == '1') {
		int cur = i, best = Inf;
		for (int j = i; j < xlen; j++) {
			while (cur > 0 && Compar(cur - 1, i - cur + 1, i, j - i + 1) <= 0) {
				cur--; best = min(best, dp[cur][i - 1]);
			}
			dp[i][j] = min(dp[i][j], best + 1);
		}
	}
	string Xs = X;
	string curbest = string(Maxn, '1');
	string cand;
	for (int i = xlen - 1; i >= 0; i--)
		if (dp[i][xlen - 1] != Inf)
			if (xlen - i > curbest.length())
				break;
			else {
				cand = Add(Xs.substr(i), dp[i][xlen - 1]);
				if (cand.length() < curbest.length() || 
					cand.length() == curbest.length() && cand < curbest) curbest = cand;
			}
	int res = 0;
	for (int i = 0; i < curbest.length(); i++)
		res = (2 * res + curbest[i] - '0') % mod;
	return res;
}

int getWays()
{
	for (int i = 0; i < xlen; i++)
		dp[0][i] = 1;
	for (int i = 1; i < xlen; i++) if (X[i] == '1') {
		int cur = i, ways = 0;
		for (int j = i; j < xlen; j++) {
			while (cur > 0 && Compar(cur - 1, i - cur + 1, i, j - i + 1) <= 0) {
				cur--; ways = (ways + dp[cur][i - 1]) % mod;
			}
			dp[i][j] = (dp[i][j] + ways) % mod;
		}
	}
	int res = 0;
	for (int i = 0; i < xlen; i++)
		res = (res + dp[i][xlen - 1]) % mod;
	return res;
}


int main()
{
	scanf("%s", X); xlen = strlen(X);
	for (int i = xlen - 1; i >= 0; i--)
		for (int j = i; j < xlen; j++)
			if (X[i] < X[j]) cst[i][j] = ii(0, -1);
			else if (X[i] > X[j]) cst[i][j] = ii(0, 1);
			     else if (j + 1 < xlen) { cst[i][j] = cst[i + 1][j + 1]; cst[i][j].first++; }
			          else cst[i][j] = ii(1, 0);
	printf("%d\n", getWays());
	printf("%d\n", getMinimum());
	return 0;
}