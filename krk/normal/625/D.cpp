#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxn = 100005;
const int Maxd = 10;

char tmp[Maxn];
string n;
int dp[Maxn][2][2];
ii my[Maxn][2][2];
ii par[Maxn][2][2];

int Get(int l, int r, int fl1, int fl2)
{
	if (l > r) return 1;
	if (!dp[l][fl1][fl2]) {
		int res = -1;
		if (l == r) {
			for (int i = l == 0? 1: 0; i < Maxd; i++)  {
				int sum = i + i + fl2;
				if (n[l] == sum % 10 + '0' && sum / 10 == fl1) {
					res = 1;
					my[l][fl1][fl2] = ii(i, i);
				}
			}
		} else if (l + 1 == r) {
			for (int i = l == 0? 1: 0; i < Maxd; i++)
				for (int j = 0; j < Maxd; j++) {
					int sum2 = i + j + fl2;
					int sum1 = i + j + sum2 / 10;
					if (n[r] == sum2 % 10 + '0' && n[l] == sum1 % 10 + '0' && fl1 == sum1 / 10) {
						res = 1;
						my[l][fl1][fl2] = ii(i, j);
					}
				}
		} else for (int i = l == 0? 1: 0; i < Maxd; i++)
					for (int j = 0; j < Maxd; j++)
						for (int nxt = 0; nxt < 2; nxt++) {
							int sum1 = i + j + nxt;
							int sum2 = i + j + fl2;
							if (n[r] == sum2 % 10 + '0' && n[l] == sum1 % 10 + '0' && fl1 == sum1 / 10 &&
								Get(l + 1, r - 1, nxt, sum2 / 10) > 0) {
								res = 1;
								my[l][fl1][fl2] = ii(i, j);
								par[l][fl1][fl2] = ii(nxt, sum2 / 10);
							}
						}
		dp[l][fl1][fl2] = res;
	}
	return dp[l][fl1][fl2];
}

void Print(int l, int r, ii fl)
{
	if (l > r) return;
	printf("%d", my[l][fl.first][fl.second].first);
	Print(l + 1, r - 1, par[l][fl.first][fl.second]);
	if (l != r) printf("%d", my[l][fl.first][fl.second].second);
}

int main()
{
	scanf("%s", tmp); n = tmp;
	if (n[0] == '0') { printf("0\n"); return 0; }
	if (n == "1") { printf("0\n"); return 0; }
	if (n[0] == '1') {
		if (n[n.length() - 1] == '1' && Get(1, n.length() - 2, 0, 0) > 0) {
			printf("1");
			Print(1, n.length() - 2, ii(0, 0));
			printf("0\n");
			return 0;
		}
		if (n.length() == 1) { printf("0\n"); return 0; }
		else {
			n.erase(0, 1);
			fill((int*)dp, (int*)dp + Maxn * 2 * 2, 0);
			if (Get(0, n.length() - 1, 1, 0) > 0) {
				Print(0, n.length() - 1, ii(1, 0));
				printf("\n");
				return 0;
			} else { printf("0\n"); return 0; }
		}
	}
	if (Get(0, n.length() - 1, 0, 0) > 0) {
		Print(0, n.length() - 1, ii(0, 0));
		printf("\n");
	} else printf("0\n");
	return 0;
}