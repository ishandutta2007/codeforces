#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair <int, int> ii;

const int Maxs = 2005;
const int Maxp = 505;
const int Inf = 1000000000;

char s[Maxs];
char p[Maxp];
int slen, plen;
int best[Maxs][Maxs];
vector <int> toprint;

int main()
{
	scanf("%s", s); slen = strlen(s);
	scanf("%s", p); plen = strlen(p);
	fill((int*)best, (int*)best + Maxs * Maxs, Inf); best[0][0] = 0;
	for (int i = 0; i <= slen; i++)
		for (int j = 0; j <= i; j++) if (best[i][j] != Inf) {
			best[i + 1][j] = min(best[i + 1][j], best[i][j] + 1);
			if (s[i] == p[j % plen]) best[i + 1][j + 1] = min(best[i + 1][j + 1], best[i][j]);
			if (j % plen == 0) best[i + 1][j] = min(best[i + 1][j], best[i][j]);
		}
	int i = 0;
	while (i + plen <= slen && best[slen][i + plen] != Inf) i += plen;
	int res = i / plen;
	int hm = best[slen][i];
	int curtims = 0;
	for (int i = 0; i <= hm; i++) {
		while (curtims < res && i >= best[slen][(curtims + 1) * plen]) curtims++;
		toprint.push_back(curtims);
	}
	int lft = slen - hm - res * plen;
	while (lft--) toprint.push_back(res);
	for (int i = res * plen - 1; i >= 0; i--)
		toprint.push_back(i / plen);
	for (int i = 0; i < toprint.size(); i++)
		printf("%d%c", toprint[i], i + 1 < toprint.size()? ' ': '\n');
	return 0;
}