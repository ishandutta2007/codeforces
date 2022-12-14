#include <bits/stdc++.h>
using namespace std;
int test, n, a, b, c, a0;
int len0[111111], len1[111111], cnt0, cnt1, pre, pos, all0, all1, tms, ps[111111];
char s[111111];
long long ans;
int main()
{
	scanf("%d", &test);
	while(test--)
	{
		scanf("%d%d%d%d", &n, &a, &b, &c);
		scanf("%s", s);
		cnt0 = cnt1 = a0 = 0;
		all0 = all1 = 0;
		ans = 0;
		pos = 0;
		while(pos < n)
		{
			pre = pos;
			while(pos < n && s[pos] == s[pre]) pos++;
			if (s[pre] == '0' && pre != 0 && pos != n) len0[++cnt0] = pos - pre;
			else if (s[pre] == '0') a0++;
			else len1[++cnt1] = pos - pre; 
		}
		a0 += cnt0;
		sort(len0 + 1, len0 + cnt0 + 1);
		for (int i = 1; i <= cnt0; i++) ps[i] = ps[i - 1] + len0[i];
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '0') all0 ++;
			else all1 ++;
		}
		for (int i = 0; i <= n; i++)
		{
			for (int j = max(0, i - 1); j <= i + 1; j++)
			{
				if (i > all0 || (j > all1 || (j > all1 - 1 && all1))) continue;
				if (j > all1 - cnt1 && j - (all1 - cnt1) > cnt0) continue;
				if (j > all1 - cnt1 && i < j + 1 && ps[j - (all1 - cnt1)] > i) continue;
				if (j > all1 - cnt1 && i == j + 1 && ps[j - (all1 - cnt1)] >= i) continue;
				tms = max(i - (all0 - a0), j - (all1 - cnt1)); tms = max(tms, 0);
				ans = max(ans, 1ll * (i - tms) * a + 1ll * j * b - 1ll * tms * c);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}