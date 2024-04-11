#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

const int Maxn = 100005;

int n;
int a[Maxn];
int cur, best;

int main()
{
	scanf("%d", &n);
	int lst = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		if (lst < a[i]) cur++;
		else cur = 1;
		lst = a[i];
		best = max(best, cur);
	}
	printf("%d\n", best);
	return 0;
}