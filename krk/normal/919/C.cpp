#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <queue>
#include <iomanip>
#include <algorithm>
using namespace std;

const int Maxn = 2005;

int n, m, k;
char S[Maxn][Maxn];
int R[Maxn][Maxn], C[Maxn][Maxn];
int res;

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%s", S[i] + 1);
		for (int j = 1; j <= m; j++) {
			R[i][j] = R[i][j - 1] + (S[i][j] == '*');
			C[i][j] = C[i - 1][j] + (S[i][j] == '*');
			if (i >= k) res += C[i][j] == C[i - k][j];
			if (k != 1 && j >= k) res += R[i][j] == R[i][j - k];
		}
	}
	printf("%d\n", res);
	return 0;
}