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

const int Maxn = 200005;

int n, m;
int a[Maxn];
int lef[Maxn];

int main() 
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		lef[i] = a[i] == a[i - 1]? lef[i - 1]: i;
	}
	while (m--) {
		int l, r, x; scanf("%d %d %d", &l, &r, &x);
		if (a[r] != x) printf("%d\n", r);
		else if (l < lef[r]) printf("%d\n", lef[r] - 1);
		else printf("-1\n");
	}
    return 0;
}