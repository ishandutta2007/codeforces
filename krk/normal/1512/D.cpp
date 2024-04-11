#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int Maxn = 200005;

int T;
int n;
int b[Maxn];

void Solve()
{
	ll sum = 0;
	for (int i = 0; i < n + 2; i++)
		sum += b[i];
	sort(b, b + n + 2);
	for (int i = 0; i < n + 2; i++) {
		ll x = b[i];
		int ind = i + 1 == n + 2? n: n + 1;
		if (sum - x == 2ll * ll(b[ind])) {
			bool was = false;
			for (int j = 0; j < n + 2; j++) if (j != ind && j != i) {
				if (was) printf(" ");
				else was = true;
				printf("%d", b[j]);
			}
			printf("\n");
			return;
		}
	}
	printf("-1\n");
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n + 2; i++)
			scanf("%d", &b[i]);
		Solve();
	}
    return 0;
}