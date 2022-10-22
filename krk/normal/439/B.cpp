#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n, x;
int c[Maxn];
ll res;

int main()
{
	scanf("%d %d", &n, &x);
	for (int i = 0; i < n; i++)
		scanf("%d", &c[i]);
	sort(c, c + n);
	for (int i = 0; i < n; i++)
		res += ll(max(1, x - i)) * c[i];
	printf("%I64d\n", res);
	return 0;
}