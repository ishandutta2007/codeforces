#include <bits/stdc++.h>
using namespace std;

const int Maxn = 200005;

int T;
int n, m;
char str[Maxn];
int lef[Maxn], rig[Maxn], cur[Maxn];
int mn[Maxn], mx[Maxn]; 

int main()
{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &n, &m);
		scanf("%s", str + 1);
		lef[0] = rig[0] = cur[0] = 0;
		for (int i = 1; i <= n; i++) {
			cur[i] = cur[i - 1] + (str[i] == '+'? 1: -1);
			lef[i] = min(lef[i - 1], cur[i]);
			rig[i] = max(rig[i - 1], cur[i]);
		}
		mn[n + 1] = mx[n + 1] = 0;
		for (int i = n; i >= 1; i--) {
			mn[i] = min(0, mn[i + 1]);
			mx[i] = max(0, mx[i + 1]);
			if (str[i] == '+') { mn[i]++; mx[i]++; }
			else { mn[i]--; mx[i]--; }
		}
		for (int i = 0; i < m; i++) {
			int l, r; scanf("%d %d", &l, &r);
			int L = min(lef[l - 1], cur[l - 1] + mn[r + 1]);
			int R = max(rig[l - 1], cur[l - 1] + mx[r + 1]);
			printf("%d\n", R - L + 1);
		}
	}
    return 0;
}