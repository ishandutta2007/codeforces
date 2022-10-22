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

typedef long long ll;

const int Maxn = 5005;
const int Maxl = 26;
const int mod = 1000000007;

int n;
string s;
int tot[Maxl];
int dp[Maxn][Maxn];
int res;

int main() 
{
	scanf("%d", &n);
	cin >> s;
	for (int j = 0; j < n; j++)
		dp[n][j] = 1;
	for (int i = n - 1; i >= 0; i--) {
		fill(tot, tot + Maxl, 0);
		for (int j = n - 1; j >= 0; j--) {
			dp[i][j] = (dp[i + 1][j] - tot[s[j] - 'a'] + mod) % mod;
			tot[s[j] - 'a'] = (tot[s[j] - 'a'] + dp[i][j]) % mod;
			dp[i][j] = (dp[i][j] + dp[i][j + 1]) % mod;
		}
	}
	printf("%d\n", dp[0][0]);
    return 0;
}