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

const int Maxn = 50;

int n, k, M;
int t[Maxn];
int res;

int main()
{
	scanf("%d %d %d", &n, &k, &M);
	for (int i = 0; i < k; i++)
		scanf("%d", &t[i]);
	sort(t, t + k);
	for (int i = 0; i <= n; i++) {
		int lft = M;
		for (int j = 0; j < k; j++)
			lft -= t[j] * i;
		if (lft < 0) break;
		int cand = (k + 1) * i;
		for (int j = 0; j < k; j++) {
			int tk = min(n - i, lft / t[j]);
			cand += tk; lft -= t[j] * tk;
		}
		res = max(res, cand);
	}
	printf("%d\n", res);
	return 0;
}