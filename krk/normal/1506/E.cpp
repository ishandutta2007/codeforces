#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n;
int a[Maxn];
set <int> S1, S2;
int res1[Maxn], res2[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		a[0] = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			if (a[i - 1] < a[i]) {
				for (int j = a[i - 1] + 1; j < a[i]; j++) {
					S1.insert(j);
					S2.insert(j);
				}
				res1[i] = res2[i] = a[i];
			} else {
				res1[i] = *S1.begin(); S1.erase(S1.begin());
				auto it = S2.end(); it--;
				res2[i] = *it; S2.erase(it);
			}
		}
		for (int i = 1; i <= n; i++)
			printf("%d%c", res1[i], i + 1 <= n? ' ': '\n');
		for (int i = 1; i <= n; i++)
			printf("%d%c", res2[i], i + 1 <= n? ' ': '\n');
	}
    return 0;
}