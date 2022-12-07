#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define PB push_back
#define P pair<int, int>
#define X first
#define Y second
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
int a[N];
int b[N], b_tot;
void lsh(int a[], int n)
{
	for(int i = 0; i < n; i ++) b[i] = a[i];
	sort(b, b + n);
	b_tot = unique(b, b + n) - b;
	for(int i = 0; i < n; ++i)
		a[i] = lower_bound(b, b + b_tot, a[i]) - b;
}
LL f[2][N];
int main()
{
	LL n, l, k;
	scanf("%I64d%I64d%I64d", &n, &l, &k);
	for(int i = 0; i < n; i ++)
		scanf("%d", &a[i]);
	lsh(a, n);
	LL seg_num = l / n;
	int leave = l % n;
	if(leave) ++ seg_num;
	else leave = n;
	LL ans = l % MOD;
	for(int i = 0; i < n; i ++)
		f[0][a[i]] ++;
	int now = 1, pre = 0;
	for(int i = 1; i < min(seg_num, k); i ++)
	{
		f[now][0] = 0;
		for(int j = 1; j < b_tot; ++j)
		{
			f[pre][j] = (f[pre][j] + f[pre][j - 1]) % MOD;
			f[now][j] = 0;
		}

		for(int j = 0; j < n; ++j)
		{
			f[now][a[j]] = (f[now][a[j]] + f[pre][a[j]]) % MOD;
			if(j < leave) ans = (ans + f[pre][a[j]] * ((seg_num - i) % MOD)) % MOD;
			else ans = (ans + f[pre][a[j]] * ((seg_num - i - 1) % MOD)) % MOD;
		}
		swap(pre, now);
	}
	if(ans < 0) ans += MOD;
	printf("%d",ans);
	return 0;
}