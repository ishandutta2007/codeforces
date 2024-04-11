#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 100005;

int n;
int a[Maxn];
int mx[Maxn];
int cur[Maxn];
ll res;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		mx[i] = max(mx[i - 1], a[i]);
	}
	int got = mx[n] + 1;
	for (int i = n; i > 0; i--) {
		got = max(got - 1, mx[i] + 1);
		cur[i] = got;
		res += cur[i] - a[i] - 1;
	}
	cout << res << endl;
	return 0;
}