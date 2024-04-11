#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod = 1000000009;
const int Maxn = 1005;
const int Maxh = 31;
const int Maxm = 46500;
const int Maxd = 4;

int n, h;
int id, col[Maxh][Maxh][Maxh][Maxh];
vector <int> has[Maxm];
vector <int> cur(Maxd), tmp(Maxd);
bool tk[Maxd];
int dp[Maxn][Maxm];
int res;

int main()
{
	scanf("%d %d", &n, &h);
	for (cur[0] = 0; cur[0] <= h; cur[0]++)
		for (cur[1] = 0; cur[1] <= h; cur[1]++)
			for (cur[2] = 0; cur[2] <= h; cur[2]++)
				for (cur[3] = 0; cur[3] <= h; cur[3]++) {
					tmp = cur; sort(tmp.begin(), tmp.end());
					if (!col[tmp[0]][tmp[1]][tmp[2]][tmp[3]]) { col[tmp[0]][tmp[1]][tmp[2]][tmp[3]] = ++id; has[id] = tmp; }
					col[cur[0]][cur[1]][cur[2]][cur[3]] = col[tmp[0]][tmp[1]][tmp[2]][tmp[3]];
				}
	dp[0][col[0][0][0][0]] = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < Maxm; j++) if (dp[i][j]) {
			for (int k = 0; k < Maxd; k++)
				if (has[j][k] < h) { tk[k] = true; cur[k] = has[j][k] + 1; }
				else { tk[k] = false; cur[k] = h; }
			for (int k = 0; k < Maxd; k++) {
				int sav = cur[k]; 
				if (tk[k]) cur[k] = 0;
				dp[i + 1][col[cur[0]][cur[1]][cur[2]][cur[3]]] = (dp[i + 1][col[cur[0]][cur[1]][cur[2]][cur[3]]] + dp[i][j]) % mod;
				cur[k] = sav;
			}
		}
	for (int j = 0; j < Maxm; j++) if (dp[n][j] && has[j][0] < h)
		res = (res + dp[n][j]) % mod;
	printf("%d\n", res);
	return 0;
}