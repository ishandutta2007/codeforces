#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 5005;

int n;
int a[Maxn];
int b[Maxn];
ll L[Maxn], R[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		L[i] = L[i - 1] + ll(a[i]) * b[i];
	}
	for (int i = n; i > 0; i--)
		R[i] = R[i + 1] + ll(a[i]) * b[i];
	ll res = R[1];
	for (int i = 1; i <= n; i++) {
		ll cur = ll(a[i]) * b[i];
		for (int j = 1; i - j > 0 && i + j <= n; j++) {
			cur += ll(a[i - j]) * b[i + j] + ll(a[i + j]) * b[i - j];
			res = max(res, cur + L[i - j - 1] + R[i + j + 1]);
		}
	}
	for (int i = 1; i + 1 <= n; i++) {
		ll cur = 0;
		for (int j = 1; i + 1 - j > 0 && i + j <= n; j++) {
			cur += ll(a[i + 1 - j]) * b[i + j] + ll(a[i + j]) * b[i + 1 - j];
			res = max(res, cur + L[i - j] + R[i + j + 1]);
		}
	}
	printf("%I64d\n", res);
    return 0;
}