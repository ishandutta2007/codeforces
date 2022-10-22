#include <bits/stdc++.h>
using namespace std;

const int Maxn = 100005;

int T;
int n;
int t[Maxn], x[Maxn];

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int res = 0;
		for (int i = 0; i < n; i++)
			scanf("%d %d", &t[i], &x[i]);
		int cur = 0, nd = 0, lst = 0;
		for (int i = 0; i < n; i++) {
			int has = t[i] - lst; lst = t[i];
			if (abs(cur - nd) <= has) cur = nd;
			else if (cur < nd) cur += has;
			else cur -= has;
			if (cur == nd) nd = x[i];
			int lft = i + 1 < n? t[i + 1] - t[i]: 2000000000;
			if (cur <= nd && cur <= x[i] && x[i] <= nd && x[i] - cur <= lft ||
				cur >= nd && cur >= x[i] && x[i] >= nd && cur - x[i] <= lft)
				res++; 
		}
		printf("%d\n", res);
	}
    return 0;
}