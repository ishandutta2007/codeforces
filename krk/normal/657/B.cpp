#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n, k;
int a[Maxn];
ll got[Maxn];
int res;

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i <= n; i++)
		scanf("%d", &a[i]);
	got[n + 1] = 0;
	for (int i = n; i >= 0; i--)
		got[i] = -k <= got[i + 1] && got[i + 1] <= k? got[i + 1] * 2ll + a[i]: got[i + 1];
	ll carry = 0;
	for (int i = 0; i <= n; i++) {
		if (carry % 2 != 0) { printf("%d\n", res); return 0; }
		carry /= 2;
		if (-k <= got[i + 1] && got[i + 1] <= k) {
			ll need = carry + got[i] - a[i];
			if (-k <= need && need <= k && (i < n || i == n && need != 0))
				res++;
		}
		carry += a[i];
	}
	printf("%d\n", res);
	return 0;
}