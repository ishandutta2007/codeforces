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

typedef long long ll;
typedef pair <ll, ll> ii;

const int Maxd = 3;

int tk[Maxd][Maxd];
ii got[Maxd][Maxd];
ll k;
int a, b;
int A[Maxd][Maxd], B[Maxd][Maxd];

ii Add(const ii &a, int p1, int p2)
{
	if (p1 == p2) return a;
	if ((p1 + 1) % Maxd == p2) return ii(a.first, a.second + 1);
	return ii(a.first + 1, a.second);
}

int main()
{
	scanf("%I64d %d %d", &k, &a, &b); a--; b--;
	for (int i = 0; i < Maxd; i++)
		for (int j = 0; j < Maxd; j++) {
			scanf("%d", &A[i][j]); A[i][j]--;
		}
	for (int i = 0; i < Maxd; i++)
		for (int j = 0; j < Maxd; j++) {
			scanf("%d", &B[i][j]); B[i][j]--;
		}
	ii cur = ii(0, 0);
	int t;
	for (t = 1; t <= k && !tk[a][b]; t++) {
		tk[a][b] = t;
		got[a][b] = cur;
		cur = Add(cur, a, b);
		int nxta = A[a][b], nxtb = B[a][b];
		a = nxta; b = nxtb;
	}
	k -= (t - 1);
	if (k > 0) {
		int len = t - tk[a][b];
		ii dif = ii(cur.first - got[a][b].first, cur.second - got[a][b].second);
		ll tims = k / len; k -= tims * len;
		cur.first += dif.first * tims; cur.second += dif.second * tims;
		while (k--) {
			cur = Add(cur, a, b);
			int nxta = A[a][b], nxtb = B[a][b];
			a = nxta; b = nxtb;
		}
	}
	printf("%I64d %I64d\n", cur.first, cur.second);
	return 0;
}