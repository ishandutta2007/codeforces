#include <bits/stdc++.h>
using namespace std;

int T;
int n, m;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		int res = 0;
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			res += a;
		}
		printf("%s\n", res == m? "YES": "NO");
	}
    return 0;
}