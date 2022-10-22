#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int x[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int lst = 0, res = 0;
		for (int i = 0; i < n; i++) {
			int a; scanf("%d", &a);
			if (lst < a) { res++; lst = a; }
			else if (lst == a) { res++; lst = a + 1; }
		}
		printf("%d\n", res);
	}
    return 0;
}