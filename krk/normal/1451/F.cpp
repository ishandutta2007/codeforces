#include <bits/stdc++.h>
using namespace std;
 
const int Maxn = 205;
 
int T;
int n, m;
int was[Maxn], xr[Maxn];
 
int main()
{
	scanf("%d", &T);
	while (T--) {
		fill(was, was + Maxn, 0);
		fill(xr, xr + Maxn, 0);
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				int a; scanf("%d", &a);
				if (a > 0) {
					was[i + j]++;
					xr[i + j] ^= a;
				}
			}
		int p = 0;
		while (p < Maxn && !xr[p]) p++;
		printf("%s\n", p >= Maxn? "Jeel": "Ashish");
	}
    return 0;
}