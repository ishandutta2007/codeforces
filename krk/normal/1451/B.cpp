#include <bits/stdc++.h>
using namespace std;

const int Maxn = 105;

int T;
int n, q;
char str[Maxn];

bool Check(int i, int l, int r)
{
	while (i <= n) {
		if (str[i] == str[l]) l++;
		if (l > r) return true;
		i++;
	}
	return false;
}

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &q);
		scanf("%s", str + 1);
		while (q--) {
			int l, r; scanf("%d %d", &l, &r);
			bool ok = false, al = false;
			for (int i = 1; i <= n; i++) {
				if (str[i] == str[l]) { al = true; l++; }
				if (l > r) break;
				if (al && Check(i + 2, l, r)) {
					ok = true;
					break;
				}
			}
			printf("%s\n", ok? "YES": "NO");
		}
	}
    return 0;
}