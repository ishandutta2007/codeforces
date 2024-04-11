#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int a[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < 2 * n; i++)
		scanf("%d", &a[i]);
	sort(a, a + 2 * n);
	ll res = ll(a[n - 1] - a[0]) * (a[2 * n - 1] - a[n]);
	for (int i = 0; i + n <= 2 * n; i++)
		res = min(res, ll(a[2 * n - 1] - a[0]) * (a[i + n - 1] - a[i]));
	cout << res << endl;
	return 0;
}