#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
using namespace std;

const int Maxn = 2505;

int n, m, q;
int my[Maxn][Maxn];

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= q; i++) {
		int t, r1, c1, r2, c2; scanf("%d %d %d %d %d", &t, &r1, &c1, &r2, &c2);
		if (t == 1)
			for (int r = r1; r <= r2; r++) {
				my[r][c1] = i; my[r][c2 + 1] = -1;
			}
		else if (t == 2)
			for (int r = r1; r <= r2; r++)
				my[r][c1] = my[r][c2 + 1] = 0;
		else {
			int st = 0;
			int res1 = 0, res2 = 0; 
			for (int i = c1; i >= 0; i--)
				if (my[r1][i] > 0) if (st == 0) { res1 = my[r1][i]; break; }
								   else st++;
				else if (my[r1][i] < 0) st--;
			st = 0;
			for (int i = c2; i >= 0; i--)
				if (my[r2][i] > 0) if (st == 0) { res2 = my[r2][i]; break; }
								   else st++;
				else if (my[r2][i] < 0) st--;
			printf("%s\n", res1 == res2? "Yes": "No");
		}
	}
	return 0;
}