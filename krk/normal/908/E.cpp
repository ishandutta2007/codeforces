#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 1005;

int m, n;
vector <string> V;
int dp[Maxn][Maxn];
bool tk[Maxn];
vector <int> seq;
int ans[Maxn][Maxn];
int res;

bool Check(int a, int b)
{
	for (int i = 0; i < V.size(); i++)
		if (V[i][a] != V[i][b]) return false;
	return true;
}

int Fill(int v)
{
	tk[v] = true;
	int res = 1;
	for (int i = 0; i < m; i++) 
		if (!tk[i] && Check(v, i)) res += Fill(i);
	return res;
}

int main()
{
	dp[1][1] = 1;
	for (int i = 1; i + 1 < Maxn; i++)
		for (int j = 1; j <= i; j++) {
			dp[i + 1][j + 1] = (dp[i + 1][j + 1] + dp[i][j]) % mod;
			dp[i + 1][j] = (dp[i + 1][j] + ll(dp[i][j]) * j) % mod;
		}
	scanf("%d %d", &m, &n);
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		V.push_back(s);
	}
	for (int i = 0; i < m; i++) if (!tk[i])
		seq.push_back(Fill(i));
	ans[0][0] = 1;
	for (int i = 0; i < seq.size(); i++)
		for (int j = 0; j < Maxn; j++) if (ans[i][j] != 0)
			for (int k = 1; k <= seq[i]; k++)
				ans[i + 1][j + k] = (ans[i + 1][j + k] + ll(ans[i][j]) * dp[seq[i]][k]) % mod;
	for (int j = 0; j < Maxn; j++) if (ans[seq.size()][j] != 0)
		res = (res + ans[seq.size()][j]) % mod;
	printf("%d\n", res);
	return 0;
}