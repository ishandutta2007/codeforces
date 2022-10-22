#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;
typedef long long ll;

const int Maxm = 31700;
const int Maxn = 305;
const int mod = 1000000007;

int C[Maxn][Maxn];
int fac[Maxn];
bool prime[Maxm];
vector <int> pr;
int n;
map <int, int> M;
int dp[Maxn][Maxn];

int Proc(int x)
{
	int ok = 1;
	for (int i = 0; i < pr.size() && pr[i] * pr[i] <= x; i++) if (x % pr[i] == 0) {
		int cnt = 0;
		while (x % pr[i] == 0) { cnt++; x /= pr[i]; }
		if (cnt % 2) ok *= pr[i];
	}
	if (x > 1) ok *= x;
	return ok;
}

int getC(int n, int k)
{
	if (n < 0 || k < 0 || k > n) return 0;
	return C[n][k];
}

int main()
{
	fac[0] = 1;
	for (int i = 1; i < Maxn; i++)
		fac[i] = ll(i) * fac[i - 1] % mod;
	for (int i = 0; i < Maxn; i++) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; j++)
			C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
	}
	fill(prime + 2, prime + Maxm, true);
	for (int i = 2; i < Maxm; i++) if (prime[i]) {
		pr.push_back(i);
		for (int j = i + i; j < Maxm; j += i) prime[j] = false;
	}
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		M[Proc(a)]++;
	}
	dp[0][0] = 1;
	int sum = 0;
	for (map <int, int>::iterator it = M.begin(); it != M.end(); it++) {
		int nsum = sum + it->second;
		for (int h = 0; h <= sum; h++) if (dp[sum][h] != 0) {
			int oth = sum + 1 - h;
			for (int i = 0; i <= h && i <= it->second; i++)
				for (int j = 0; j <= oth && i + j <= it->second; j++) {
					int ways = ll(getC(h, i)) * getC(oth, j) % mod * getC(it->second - 1, i + j - 1) % mod * fac[it->second] % mod;
					int nholes = h - i + it->second - (i + j);
					dp[nsum][nholes] = (dp[nsum][nholes] + ll(ways) * dp[sum][h]) % mod;
				}
		}
		sum = nsum;
	}
	printf("%d\n", dp[sum][0]);
	return 0;
}