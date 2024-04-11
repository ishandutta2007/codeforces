#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, h, k;
int a[Maxn];
ll res;

int main()
{
	scanf("%d %d %d", &n, &h, &k);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int cur = 0;
	int l = 0;
	while (cur > 0 || l < n) {
		while (l < n && cur + a[l] <= h) cur += a[l++];
		res++; cur = max(0, cur - k);
		int reach = 0;
		if (l < n) {
			reach = max(reach, h - a[l]);
		}
		if (reach <= cur) {
			int tims = (cur - reach) / k;
			res += tims;
			cur = max(0, cur - k * tims);
		}
	}
	printf("%I64d\n", res);
	return 0;
}