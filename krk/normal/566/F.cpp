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

const int Maxn = 1000005;

int n;
int cnt[Maxn];
int res[Maxn];
int ans;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int a; scanf("%d", &a);
		cnt[a]++;
	}
	for (int i = 1; i < Maxn; i++) if (cnt[i] > 0) {
		res[i] += cnt[i]; ans = max(ans, res[i]);
		for (int j = i + i; j < Maxn; j += i)
			res[j] = max(res[j], res[i]);
	}
	printf("%d\n", ans);
	return 0;
}