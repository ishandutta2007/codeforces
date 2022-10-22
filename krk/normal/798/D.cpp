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

const int Maxn = 200005;

int n, N;
ll a[Maxn], b[Maxn];

int main()
{
	scanf("%d", &n); N = 2 * n;
	for (int i = 1; i <= n; i++) {
		scanf("%I64d", &a[i]); a[i + n] = a[i];
	}
	for (int i = 1; i <= n; i++) {
		scanf("%I64d", &b[i]); b[i + n] = b[i];
	}
	for (int i = 1; i <= N; i++) {
		a[i] += a[i - 1]; b[i] += b[i - 1];
	}
	int k = n / 2 + 1;
	for (int i = k; i <= N; i++)
		if (2ll * (a[i] - a[i - k]) > a[n] && 2ll * (b[i] - b[i - k]) > b[n]) {
			printf("%d\n", k);
			for (int j = i - k; j < i; j++)
				printf("%d%c", j % n + 1, j + 1 < i? ' ': '\n');
			return 0;
		}
	return 0;
}