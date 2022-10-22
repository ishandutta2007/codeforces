#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

const int Maxb = 20;
const int Maxn = 77;
const int mod = 1000000007;

int n;
char str[Maxn];
int nxt[Maxn];
int dp[Maxn][1 << Maxb];
bool ok[1 << Maxb];
int res;

int main() 
{
	for (int i = 1; i <= Maxb; i++)
		ok[(1 << i) - 1] = true;
	scanf("%d", &n);
	scanf("%s", str);
	nxt[n] = n;
	for (int i = n - 1; i >= 0; i--)
		nxt[i] = str[i] == '1'? i: nxt[i + 1];
	for (int i = 0; i < n; i++)
		dp[i][0] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 1 << Maxb; j++) if (dp[i][j] > 0) {
			if (ok[j]) res = (res + dp[i][j]) % mod;
			int mi = nxt[i];
			int v = 0;
			for (int k = 1; k <= 5 && mi + k <= n; k++) {
				v = 2 * v + bool(str[mi + k - 1] == '1');
				if (0 < v && v <= Maxb)
					dp[mi + k][j | 1 << (v - 1)] = (dp[mi + k][j | 1 << (v - 1)] + dp[i][j]) % mod;
			}
		}
	for (int j = 0; j < 1 << Maxb; j++)
		if (ok[j]) res = (res + dp[n][j]) % mod;
	printf("%d\n", res);
    return 0;
}