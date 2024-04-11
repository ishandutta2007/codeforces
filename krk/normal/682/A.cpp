#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int mod = 5;

int n, m;
int has[mod];
ll res;

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++)
		has[i % mod]++;
	for (int i = 1; i <= n; i++)
		res += has[(mod - i % mod) % mod];
	printf("%I64d\n", res);
	return 0;
}