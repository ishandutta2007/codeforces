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

typedef long long ll;

const int Maxn = 100005;

int n;
int a[Maxn];

ll C(int n, int k)
{
	ll res = 1;
	for (int i = 1; i <= k; i++)
		res *= ll(n - i + 1);
	for (int i = 2; i <= k; i++)
		res /= ll(i);
	return res;
}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int cnt = 1;
	while (2 - cnt >= 0 && a[2 - cnt] == a[2]) cnt++;
	int tot = 0;
	for (int i = 0; i < n; i++)
		tot += a[i] == a[2];
	printf("%I64d\n", C(tot, cnt));
	return 0;
}