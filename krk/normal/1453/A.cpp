#include <bits/stdc++.h>
using namespace std;

int T;
int n, m;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		set <int> S;
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			S.insert(a);
		}
		for (int i = 0; i < m; i++) {
			int a; scanf("%d", &a);
			S.insert(a);
		}
		printf("%d\n", n + m - int(S.size()));
	}
    return 0;
}