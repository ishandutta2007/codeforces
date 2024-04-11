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

const int Maxn = 105;

int n, m;
char B[Maxn][Maxn];

char Get(int r1, int r2, int c1, int c2)
{
	char ch = B[r1][c1];
	for (int i = r1; i < r2; i++)
		for (int j = c1; j < c2; j++)
			if (B[i][j] != ch) return '?';
	return ch;
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", B[i]);
	if (n % 3 == 0) {
		char a = Get(0, n / 3, 0, m), b = Get(n / 3, 2 * n / 3, 0, m), c = Get(2 * n / 3, n, 0, m);
		if (a == '?' || b == '?' || c == '?' || a == b || a == c || b == c) ;
		else { printf("YES\n"); return false; }
	}
	if (m % 3 == 0) {
		char a = Get(0, n, 0, m / 3), b = Get(0, n, m / 3, 2 * m / 3), c = Get(0, n, 2 * m / 3, m);
		if (a == '?' || b == '?' || c == '?' || a == b || a == c || b == c) ;
		else { printf("YES\n"); return false; }
	}
	printf("NO\n");
	return 0;
}