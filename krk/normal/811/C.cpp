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

const int Maxn = 5005;

int n;
int a[Maxn];
int dp[Maxn];
int prv[Maxn];
int lst[Maxn];

int main()
{
	fill(lst, lst + Maxn, -1);
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		prv[i] = lst[a[i]]; lst[a[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		dp[i + 1] = max(dp[i + 1], dp[i]);
		int mx = 0, add = 0;
		for (int j = i; j < n; j++) {
			if (prv[j] < i) 
				if (prv[j] < 0) add ^= a[j];
				else break;
			mx = max(mx, lst[a[j]]);
			if (mx == j) dp[mx + 1] = max(dp[mx + 1], dp[i] + add);
		}
	}
	printf("%d\n", dp[n]);
	return 0;
}