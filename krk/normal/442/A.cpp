#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const string rw = "RGBYW";

const int Maxn = 5;
const int Inf = 1000000000;

int n;
bool has[Maxn][Maxn];
int res = Inf;

bool Ok(int rmask, int cmask)
{
	for (int r1 = 0; r1 < Maxn; r1++)
		for (int c1 = 0; c1 < Maxn; c1++) if (has[r1][c1])
			for (int r2 = 0; r2 < Maxn; r2++)
				for (int c2 = 0; c2 < Maxn; c2++) if (has[r2][c2] && (r1 != r2 || c1 != c2))
					if (r1 == r2 && !(cmask & 1 << c1) && !(cmask & 1 << c2) ||
						c1 == c2 && !(rmask & 1 << r1) && !(rmask & 1 << r2) ||
						!(cmask & 1 << c1) && !(cmask & 1 << c2) && !(rmask & 1 << r1) && !(rmask & 1 << r2))
						return false;
	return true;
}

int Bits(int x)
{
	int res = 0;
	while (x) { res += x & 1; x >>= 1; }
	return res;
}

int main()
{
	char s[5];
	scanf("%d", &n);
	while (n--) {
		scanf("%s", s);
		has[rw.find(s[0])][s[1] - '1'] = true;
	}
	for (int i = 0; i < 1 << Maxn; i++)
		for (int j = 0; j < 1 << Maxn; j++)
			if (Ok(i, j)) {
				int cand = Bits(i) + Bits(j);
				res = min(res, cand);
			}
	printf("%d\n", res);
	return 0;
}