#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 300005;

int T;
int n;
int a[Maxn];
ll r[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		r[n - 1] = 0;
		for (int i = n - 1; i > 0; i--) {
			r[i - 1] = r[i];
			if (a[i - 1] > a[i])
				r[i - 1] += a[i - 1] - a[i];
		}
		bool ok = true;
		for (int i = 0; i < n && ok; i++)
			ok = a[i] >= r[i];
		printf("%s\n", ok? "YES": "NO");
	}
    return 0;
}