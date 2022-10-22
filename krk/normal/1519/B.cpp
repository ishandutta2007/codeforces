#include <bits/stdc++.h>
using namespace std;

int T;
int n, m, k;

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &n, &m, &k);
		int r = 1, c = 1;
		int res = 0;
		while (r < n) { res += c; r++; }
		while (c < m) { res += r; c++; }
		printf("%s\n", res == k? "YES": "NO");
	}
    return 0;
}