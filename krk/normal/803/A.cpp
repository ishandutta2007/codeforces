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

const int Maxn = 105;

int B[Maxn][Maxn];
int n, k;

int main()
{
	scanf("%d %d", &n, &k);
	if (k > n * n) { printf("-1\n"); return 0; }
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (i == j && k >= 1) {
				B[i][j] = 1; k--;
			} else if (i != j && k >= 2) {
				B[i][j] = B[j][i] = 1; k -= 2;
			}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			printf("%d%c", B[i][j], j + 1 < n? ' ': '\n');
	return 0;
}