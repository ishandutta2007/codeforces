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

int n, l, r;
int a[Maxn];
int ind[Maxn];
int res[Maxn];

int main() 
{
	scanf("%d %d %d", &n, &l, &r);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n; i++) {
		int c; scanf("%d", &c); c--;
		ind[c] = i;
	}
	int from = l - r;
	for (int i = 0; i < n; i++) {
		int j = ind[i];
		if (a[j] + from < l) from = l - a[j];
		res[j] = a[j] + from;
		if (res[j] > r) { printf("-1\n"); return 0; }
		from++;
	}
	for (int i = 0; i < n; i++)
		printf("%d%c", res[i], i + 1 < n? ' ': '\n');
    return 0;
}