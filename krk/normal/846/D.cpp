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

const int Maxn = 505;
const int Maxm = Maxn * Maxn;

int B[Maxn][Maxn];
int n, m, k, q;
int X[Maxm], Y[Maxm], T[Maxm];
vector <int> un;

bool Check(int t)
{
	fill((int*)B, (int*)B + Maxn * Maxn, 0);
	for (int i = 0; i < q; i++)
		if (T[i] <= t) B[X[i]][Y[i]]++;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			B[i][j] += B[i - 1][j] + B[i][j - 1] - B[i - 1][j - 1];
	for (int i = k; i <= n; i++)
		for (int j = k; j <= m; j++)
			if (B[i][j] - B[i - k][j] - B[i][j - k] + B[i - k][j - k] >= k * k) return false;
	return true;
}

int main()
{
	scanf("%d %d %d %d", &n, &m, &k, &q);
	for (int i = 0; i < q; i++) {
		scanf("%d %d %d", &X[i], &Y[i], &T[i]);
		un.push_back(T[i]);
	}
	sort(un.begin(), un.end());
	int lef = 0, rig = int(un.size()) - 1;
	int res = -1;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (Check(un[mid])) lef = mid + 1;
		else { res = mid; rig = mid - 1; }
	}
	printf("%d\n", res == -1? -1: un[res]);
	return 0;
}