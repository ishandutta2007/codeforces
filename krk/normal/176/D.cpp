#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 2005;
const int Maxl = 26;

int n;
vector <int> let[Maxn][Maxl];
int m;
int ind[Maxn];
ii nxt[Maxn][Maxl];
string given;
ii dp[Maxn][Maxn];

ii getNxt(ii cur, int need)
{
	int wh = lower_bound(let[ind[cur.first]][need].begin(), let[ind[cur.first]][need].end(), cur.second) - let[ind[cur.first]][need].begin();
	if (wh == let[ind[cur.first]][need].size()) cur = nxt[cur.first + 1][need];
	else cur.second = let[ind[cur.first]][need][wh];
	cur.second++;
	return cur;
}

int main()
{
	std::ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		for (int j = 0; j < s.length(); j++)
			let[i][s[j] - 'a'].push_back(j);
	}
	cin >> m;
	for (int i = 0; i < m; i++) cin >> ind[i];
	for (int j = 0; j < Maxl; j++) nxt[m][j] = ii(m, 0);
	for (int i = m - 1; i >= 0; i--)
		for (int j = 0; j < Maxl; j++) {
			int wh = lower_bound(let[ind[i]][j].begin(), let[ind[i]][j].end(), 0) - let[ind[i]][j].begin();
			if (wh == let[ind[i]][j].size()) nxt[i][j] = nxt[i + 1][j];
			else nxt[i][j] = ii(i, let[ind[i]][j][wh]);
		}
	cin >> given;
	fill((ii*)dp, (ii*)dp + Maxn * Maxn, ii(m, 0)); dp[0][0] = ii(0, 0);
	for (int i = 0; i < given.length(); i++)
		for (int j = 0; j <= i; j++) if (dp[i][j] < ii(m, 0)) {
			dp[i + 1][j] = min(dp[i + 1][j], dp[i][j]);
			ii u = getNxt(dp[i][j], given[i] - 'a');
			dp[i + 1][j + 1] = min(dp[i + 1][j + 1], u);
		}
	int j = given.length();
	while (ii(m, 0) <= dp[given.length()][j]) j--;
	cout << j << endl;
	return 0;
}