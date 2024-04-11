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

const int Maxn = 100005;

int n;
int f[Maxn];
int cur, inpos[Maxn];
int a[Maxn], b[Maxn];

int main() 
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &f[i]); 
		if (!inpos[f[i]]) { inpos[f[i]] = ++cur; b[cur] = f[i]; }
	}
	for (int i = 1; i <= n; i++)
		a[i] = inpos[f[i]];
	for (int i = 1; i <= cur; i++)
		if (a[b[i]] != i) { printf("-1\n"); return 0; }
	printf("%d\n", cur);
	for (int i = 1; i <= n; i++)
		printf("%d%c", a[i], i + 1 <= n? ' ': '\n');
	for (int i = 1; i <= cur; i++)
		printf("%d%c", b[i], i + 1 <= cur? ' ': '\n');
    return 0;
}