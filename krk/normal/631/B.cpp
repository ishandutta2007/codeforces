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

typedef pair <int, int> ii;

const int Maxn = 5005;

int n, m, k;
ii R[Maxn], C[Maxn];

int main() 
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= k; i++) {
		int typ, a, b; scanf("%d %d %d", &typ, &a, &b);
		if (typ == 1) R[a] = ii(i, b);
		else C[a] = ii(i, b);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			printf("%d%c", R[i].first > C[j].first? R[i].second: C[j].second, j + 1 <= m? ' ': '\n');
    return 0;
}