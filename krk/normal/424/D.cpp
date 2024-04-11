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

typedef pair <int, int> ii;

const int Maxn = 305;
const int Inf = 2000000007;

int n, m, t;
int tp, tu, td;
int B[Maxn][Maxn];
int U[Maxn][Maxn], D[Maxn][Maxn];
map <int, int> T;
int add;
int res = Inf;
int ai, aj, bi, bj;

int Get(int a, int b)
{
	if (a == b) return tp;
	if (a < b) return tu;
	return td;
}

ii Obtain(int val)
{
	map <int, int>::iterator it = T.lower_bound(val), it2;
	it2 = it;
	if (it2 != T.begin()) it2--;
	if (it == T.end()) it--;
	if (abs(it->first - val) < abs(it2->first - val)) return *it;
	else return *it2;
}

int main()
{
	scanf("%d %d %d", &n, &m, &t);
	scanf("%d %d %d", &tp, &tu, &td);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &B[i][j]);
	for (int j = 1; j <= m; j++)
		for (int i = 2; i <= n; i++) {
			U[i][j] = U[i - 1][j] + Get(B[i][j], B[i - 1][j]);
			D[i][j] = D[i - 1][j] + Get(B[i - 1][j], B[i][j]);
		}
	for (int i1 = 1; i1 <= n; i1++)
		for (int i2 = i1 + 2; i2 <= n; i2++) {
			add = 0; T.clear(); T[D[i2][m] - D[i1][m]] = m;
			for (int j = m - 2; j >= 1; j--) {
				add += Get(B[i1][j + 1], B[i1][j + 2]) + Get(B[i2][j + 2], B[i2][j + 1]);
				int my = U[i2][j] - U[i1][j] + Get(B[i1][j], B[i1][j + 1]) + Get(B[i2][j + 1], B[i2][j]) + add;
				ii g = Obtain(t - my);
				int cand = abs(t - my - g.first);
				if (cand < res) {
					res = cand;
					ai = i1; aj = j; bi = i2; bj = g.second;
				}
				T[D[i2][j + 1] - D[i1][j + 1] - add] = j + 1;
			}
		}
	printf("%d %d %d %d\n", ai, aj, bi, bj);
	return 0;
}