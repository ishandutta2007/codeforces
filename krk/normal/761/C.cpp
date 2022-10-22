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

const int Maxn = 55;
const int Inf = 100000000;

int n, m;
char str[Maxn][Maxn];
int dig[Maxn], let[Maxn], symb[Maxn];
int res = Inf;

int main() 
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", str[i]);
		dig[i] = let[i] = symb[i] = Inf;
		for (int j = 0; j < m; j++) {
			int dist = min(j, m - j);
			if ('a' <= str[i][j] && str[i][j] <= 'z') let[i] = min(let[i], dist);
			else if ('0' <= str[i][j] && str[i][j] <= '9') dig[i] = min(dig[i], dist);
			else if (str[i][j] == '#' || str[i][j] == '*' || str[i][j] == '&') symb[i] = min(symb[i], dist);
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) if (i != j)
			for (int k = 0; k < n; k++) if (k != j && k != i)
				res = min(res, dig[i] + let[j] + symb[k]);
	printf("%d\n", res);
    return 0;
}