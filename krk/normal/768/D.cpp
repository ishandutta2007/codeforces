#include <map>
#include <set>
#include <cmath>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cstdio>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long double ld;

const int Maxn = 8000;
const int Maxm = 1001;
const ld eps = 1e-11l;

int k, q;
ld p[Maxn][Maxm];

int main() 
{
	scanf("%d %d", &k, &q);
	p[0][0] = 1;
	for (int i = 0; i + 1 < Maxn; i++)
		for (int j = 0; j <= k; j++) {
			p[i + 1][j] += ld(j) / k * p[i][j];
			if (j + 1 <= k) p[i + 1][j + 1] += ld(k - j) / k * p[i][j];
		}
	while (q--) {
		int par; scanf("%d", &par);
		for (int i = 0; i < Maxn; i++)
			if (p[i][k] >= ld(par - eps) / 2000.0l) {
				printf("%d\n", i); break;
			}
	}
    return 0;
}