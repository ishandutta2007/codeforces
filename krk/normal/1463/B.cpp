#include <bits/stdc++.h>
using namespace std;

const int Maxn = 52;

int T;
int n;
int a[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		for (int i = 0; i < n; i++) {
			int p = 1;
			while (p * 2 <= a[i]) p *= 2;
			printf("%d%c", p, i + 1 < n? ' ': '\n');
		}
	}
    return 0;
}