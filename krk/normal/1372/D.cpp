#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int n;
int a[Maxn];
ll L[Maxn], R[Maxn];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		L[i] = a[i];
		if (i - 2 >= 0) L[i] += L[i - 2];
	}
	for (int i = n - 1; i >= 0; i--) {
		R[i] = a[i];
		if (i + 2 < n) R[i] += R[i + 2];
	}
	ll res = R[0];
	for (int i = 0; i + 1 < n; i++)
		res = max(res, L[i] + R[i + 1]);
	cout << res << endl;
    return 0;
}