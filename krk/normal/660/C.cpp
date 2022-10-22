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

const int Maxn = 300005;

int n, k;
int a[Maxn], cnt[Maxn];

int Get(int x)
{
	for (int i = x; i <= n; i++)
		if (x - (cnt[i] - cnt[i - x]) <= k) return i;
	return -1;
}

int main() 
{
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]); cnt[i] = a[i] + cnt[i - 1];
	}
	int lef = 0, rig = n;
	int res = -1;
	while (lef <= rig) {
		int mid = lef + rig >> 1;
		if (Get(mid) != -1) { res = mid; lef = mid + 1; }
		else rig = mid - 1;
	}
	printf("%d\n", res);
	int r = Get(res);
	for (int i = 1; i <= n; i++) {
		int my = (r - res < i && i <= r)? 1: a[i];
		printf("%d%c", my, i + 1 <= n? ' ': '\n');
	}
    return 0;
}