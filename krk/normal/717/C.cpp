#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod = 10007;
const int Maxn = 100005;

int n;
int a[Maxn];
int res;

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0; i < n; i++)
		res = (res + ll(a[i]) * ll(a[n - 1 - i])) % mod;
	printf("%d\n", res);
	return 0;
}