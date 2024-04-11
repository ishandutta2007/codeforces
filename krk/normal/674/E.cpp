#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 500005;
const int Maxm = 65;

int q;
int n = 2;
int P[Maxn];
ld has[Maxn][Maxm];

void Change(int v, int lvl, ld cur, ld old)
{
	if (!v || lvl >= Maxm) return;
	ld nold = has[v][lvl];
	ld x = (has[v][lvl] - old) / (1.0l - old);
	has[v][lvl] = x + cur - x * cur;
	Change(P[v], lvl + 1, has[v][lvl] / 2, nold / 2);
}

int main()
{
	scanf("%d", &q);
	while (q--) {
		int typ, v; scanf("%d %d", &typ, &v);
		if (typ == 1) { P[n++] = v; Change(n - 1, 0, 1.0l, 0.0l); }
		else {
			ld res = 0;
			for (int i = 1; i < Maxm; i++)
				res += has[v][i];
			printf("%.15lf\n", double(res));
		}
	}
	return 0;
}