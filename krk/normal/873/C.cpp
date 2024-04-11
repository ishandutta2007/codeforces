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

const int Maxn = 105;

int n, m, k;
int B[Maxn][Maxn];
ii tres;

ii Better(const ii &a, const ii &b)
{
	if (a.first != b.first) return a.first > b.first? a: b;
	return a.second < b.second? a: b;
}

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &B[i][j]);
	for (int j = 0; j < m; j++) {
		ii res = ii(0, 0);
		int was = 0;
		for (int i = 0; i < n; i++) {
			int obt = 0;
			for (int i2 = i; i2 < i + k && i2 < n; i2++)
				obt += B[i2][j];
			res = Better(res, ii(obt, was));
			was += B[i][j] == 1;
		}
		tres.first += res.first; tres.second += res.second;
	}
	printf("%d %d\n", tres.first, tres.second);
	return 0;
}