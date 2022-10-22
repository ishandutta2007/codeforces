#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

typedef long long ll;

const int mod = 1000000007;
const int Maxn = 500005;
const int Maxm = 22;
const int Maxd = 4;
const int dy[Maxd] = {-1, 1, 0, 0};
const int dx[Maxd] = {0, 0, -1, 1};
const string DR = "UDLR";

struct pos {
	int r1, c1, r2, c2;
	int pr, pc;
	pos(int r1 = 0, int c1 = 0, int r2 = 0, int c2 = 0, int pr = 0, int pc = 0): r1(r1), c1(c1), r2(r2), c2(c2), pr(pr), pc(pc) {}
	pos Apply(int d, const pos &b) const {
		pos c;
		c.r1 = min(r1, pr + b.r1 + dy[d]); c.c1 = min(c1, pc + b.c1 + dx[d]);
		c.r2 = max(r2, pr + b.r2 + dy[d]); c.c2 = max(c2, pc + b.c2 + dx[d]);
		c.pr = pr + b.pr + dy[d]; c.pc = pc + b.pc + dx[d];
		return c;
	}
};

int n, h, w;
int S[Maxn];
pos dp[Maxn][Maxm];
pos cur;
int steps;
int res;

bool Same(const pos &a, const pos &b)
{
	return a.r1 == b.r1 && a.c1 == b.c1 && a.r2 == b.r2 && a.c2 == b.c2;
}

bool Cond()
{
	return cur.r2 - cur.r1 + 1 <= h && cur.c2 - cur.c1 + 1 <= w;
}

int main()
{
	scanf("%d %d %d", &n, &h, &w);
	for (int i = 0; i < n; i++) {
		char ch; scanf(" %c", &ch);
		S[i] = DR.find(ch);
	}
	for (int j = 1; j < Maxm; j++)
		for (int i = 0; i + (1 << j) <= n; i++) {
			dp[i][j] = dp[i][j - 1].Apply(S[i + (1 << j - 1)], dp[i + (1 << j - 1)][j - 1]);
		}
	while (Cond()) {
		int pnt = 0;
		while (pnt < n && Cond()) {
			for (int j = Maxm - 1; j >= 0; j--)
				if (pnt + (1 << j) <= n) {
					pos u = cur.Apply(S[pnt], dp[pnt][j]);
					if (Same(cur, u)) {
						steps = (steps + (1 << j)) % mod;
						pnt += 1 << j;
						cur = u;
					}
				}
			if (pnt < n) {
				steps = (steps + 1) % mod;
				if (S[pnt] < 2) res = (res + ll(steps) * ll(w - (cur.c2 - cur.c1))) % mod;
				else res = (res + ll(steps) * ll(h - (cur.r2 - cur.r1))) % mod;
				cur = cur.Apply(S[pnt], dp[pnt][0]); pnt++;
			}
		}
		if (cur.pr == 0 && cur.pc == 0) break;
	}
	if (Cond() && cur.pr == 0 && cur.pc == 0) {
		printf("-1\n"); return 0;
	}
	printf("%d\n", res);
	return 0;
}