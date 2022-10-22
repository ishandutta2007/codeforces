#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n, k;
int p[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &k);
		for (int i = 1; i <= k; i++)
			p[i] = i;
		int a = k - (n - k);
		reverse(p + a, p + k + 1);
		for (int i = 1; i <= k; i++)
			printf("%d%c", p[i], i + 1 <= k? ' ': '\n');
	}
    return 0;
}