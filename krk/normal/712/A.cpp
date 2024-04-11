#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
ll a[Maxn];
ll b[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%I64d", &a[i]);
	ll add = 0, sub = 0;
	for (int i = n - 1; i >= 0; i--) {
		swap(add, sub);
		b[i] = a[i] - add + sub;
		add += b[i];
	}
	for (int i = 0; i < n; i++)
		printf("%I64d%c", b[i], i + 1 < n? ' ': '\n');
	return 0;
}