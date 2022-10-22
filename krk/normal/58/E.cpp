#include <cstdio>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

const int Inf = 1000000000;
const int Maxn = 8;

struct parent {
	int x, y, z, t1, t2, t3, t;
	parent(int x = 0, int y = 0, int z = 0, int t1 = 0, int t2 = 0, int t3 = 0, int t = 0): x(x), y(y), z(z), t1(t1), t2(t2), t3(t3), t(t) { }
};

struct with {
	int a, b, c;
	with(int a = 0, int b = 0, int c = 0): a(a), b(b), c(c) { }
};

int a, b, c;
string sa, sb, sc;
int dp[Maxn][Maxn][Maxn][2][2][2][2];
parent par[Maxn][Maxn][Maxn][2][2][2][2];
with wth[Maxn][Maxn][Maxn][2][2][2][2];
string ra, rb, rc;

string toString(int num)
{
	stringstream ss; ss << num;
	string res; ss >> res;
	return res;
}

int getVal(int a, int b, int c, int t1, int t2, int t3, int t)
{
	if (a == 0 && b == 0 && c == 0) return t? (t3? 1: Inf): 0;
	if (dp[a][b][c][t1][t2][t3][t] == Inf) {
		dp[a][b][c][t1][t2][t3][t]--;
		int res = Inf - 1; parent p; with w;
		for (int mask = 0; mask < 8; mask++) {
			int cost = t1 + t2 + t3;
			int na = a, nb = b, nc = c;
			if (mask & 1 << 2) { if (a == 0) continue; na = a - 1; }
			if (mask & 1 << 1) { if (b == 0) continue; nb = b - 1; }
			if (mask & 1 << 0) { if (c == 0) continue; nc = c - 1; }
			for (int ta = 0; ta < 10; ta++) if ((!(mask & 1 << 2) || ta == sa[a - 1] - '0') && (t1 || !ta))
				for (int tb = 0; tb < 10; tb++) if ((!(mask & 1 << 1) || tb == sb[b - 1] - '0') && (t2 || !tb)) {
					int tc = (ta + tb + t) % 10;
					if (mask & 1 << 0 && tc != sc[c - 1] - '0' || t3 == 0 && tc) continue;
					int nt = (ta + tb + t) / 10;
					for (int nt1 = 0; nt1 <= t1; nt1++) if (nt1 || na == 0)
						for (int nt2 = 0; nt2 <= t2; nt2++) if (nt2 || nb == 0)
							for (int nt3 = 0; nt3 <= t3; nt3++) if (nt3 || nc == 0) {
								int cand = getVal(na, nb, nc, nt1, nt2, nt3, nt) + cost;
								if (cand < res) { res = cand; p = parent(na, nb, nc, nt1, nt2, nt3, nt); w = with(ta, tb, tc); }
							}
				}
		}
		dp[a][b][c][t1][t2][t3][t] = res; par[a][b][c][t1][t2][t3][t] = p; wth[a][b][c][t1][t2][t3][t] = w;
	}
	return dp[a][b][c][t1][t2][t3][t];
}

void Collect(int a, int b, int c, int t1, int t2, int t3, int t)
{
	if (a == 0 && b == 0 && c == 0) {
		if (t) rc += "1";
		return;
	}
	parent p = par[a][b][c][t1][t2][t3][t]; with w = wth[a][b][c][t1][t2][t3][t];
	Collect(p.x, p.y, p.z, p.t1, p.t2, p.t3, p.t);
	if (t1) ra += string(1, '0' + w.a);
	if (t2) rb += string(1, '0' + w.b);
	if (t3) rc += string(1, '0' + w.c);
}

int main()
{
	scanf("%d+%d=%d", &a, &b, &c);
	sa = toString(a), sb = toString(b), sc = toString(c);
	fill((int*)dp, (int*)dp + Maxn * Maxn * Maxn * 2 * 2 * 2 * 2, Inf);
	getVal(sa.length(), sb.length(), sc.length(), 1, 1, 1, 0);
	Collect(sa.length(), sb.length(), sc.length(), 1, 1, 1, 0);
	printf("%s+%s=%s\n", ra.c_str(), rb.c_str(), rc.c_str());
	return 0;
}