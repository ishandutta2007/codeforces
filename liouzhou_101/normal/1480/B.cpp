#include <bits/stdc++.h>
 
using namespace std;
 
const int MAXN = 100010;
 
int A, B, n;
int a[MAXN], b[MAXN];
 
void solve()
{
	scanf("%d%d%d", &A, &B, &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; ++i)
		scanf("%d", &b[i]);
	int64_t damage = 0;
	for (int i = 1; i <= n; ++i)
		damage += int64_t(b[i] + A - 1) / A * a[i];
	for (int i = 1; i <= n; ++i)
		if (B - (damage - a[i]) > 0)
		{
			puts("YES");
			return;
		}
	puts("NO");
}
 
int main()
{
	int tests;
	scanf("%d", &tests);
	while (tests--) solve();
	return 0;
}