#include <bits/stdc++.h>
using namespace std;

const int Maxn = 1005;

int T;
int n, x;
int a[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &x);
		int sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]); sum += a[i];
		}
		if (sum == x) { printf("NO\n"); continue; }
		sum = 0;
		for (int i = 0; i < n; i++) {
			sum += a[i];
			if (sum == x) {
				sum -= a[i];
				swap(a[i], a[i + 1]);
				sum += a[i];
			}
		}
		printf("YES\n");
		for (int i = 0; i < n; i++)
			printf("%d%c", a[i], i + 1 < n? ' ': '\n');
	}
    return 0;
}