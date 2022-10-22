#include <cstdio>
#include <string>
#include <sstream>
using namespace std;

typedef long long ll;

const int Maxn = 20;
const int Maxd = 10;
const int Maxr = 6;

int t;
ll n;
string s;
int dp[Maxn][Maxd], a[Maxn][Maxd], b[Maxn][Maxd];
string res[Maxr];

bool Get(int r, int c)
{
	if (r < 0) return c == 0;
	if (dp[r][c] == 0) {
		dp[r][c] = -1;
		for (int i = 0; i <= Maxr && dp[r][c] == -1; i++)
			for (int j = 0; i + j <= Maxr && dp[r][c] == -1; j++) {
				int has = c + 4 * i + 7 * j;
				if (has % 10 + '0' == s[r] && Get(r - 1, has / 10)) {
					dp[r][c] = 1; a[r][c] = i; b[r][c] = j;
				}
			}
	}
	return dp[r][c] == 1;
}

int main()
{
	scanf("%d", &t);
	while (t--) {
		scanf("%I64d", &n);
		stringstream ss; ss << n;
		ss >> s;
		for (int i = 0; i < s.length(); i++)
			for (int j = 0; j < Maxd; j++)
				dp[i][j] = 0;
		if (Get(s.length() - 1, 0)) {
			for (int i = 0; i < Maxr; i++)
				res[i] = "";
			int r = s.length() - 1, c = 0;
			while (r >= 0) {
				int ind = 0;
				for (int i = 0; i < a[r][c]; i++) { res[ind] = "4" + res[ind]; ind++; }
				for (int i = 0; i < b[r][c]; i++) { res[ind] = "7" + res[ind]; ind++; }
				while (ind < Maxr) { res[ind] = "0" + res[ind]; ind++; }
				c = (c + a[r][c] * 4 + b[r][c] * 7) / 10; r--;
			}
			for (int i = 0; i < Maxr; i++) {
				stringstream ss(res[i]);
				ll num; ss >> num;
				printf("%I64d%c", num, i + 1 < Maxr? ' ': '\n');
			}
		} else printf("-1\n");
	}
	return 0;
}