#include <iostream>
#include <cstdio>
#include <cstring>
#define MN 401000

int n, a[MN];
struct xxx{
	int x, id;
	xxx(){}
	xxx(int a, int b) {x = a; id = b;}
}b[MN], c[MN];

int main()
{
	scanf("%d", &n);
	int ans = 0;
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), b[i].id = i;
	for(int i = 0; i <= 26; i++)
	{
		int cnt1 = 0, cnt2 = 0;
		for(int j = 1; j <= n; j++) if(!((a[j] >> i) & 1)) cnt2++;
		for(int j = 1; j <= n; j++)
		{
			if(!((a[b[j].id] >> i) & 1))
				c[++cnt1] = xxx(b[j].x, b[j].id);
			else
				c[++cnt2] = xxx(b[j].x + (1 << i), b[j].id);
		}
		memcpy(b, c, sizeof(c));
		int L = n + 1, R = n;
		for(int j = 1; j <= n; j++)
		{
			while(L > 1 && c[j].x + c[L - 1].x >= (1 << i)) L--;
			while(R >= 1 && c[j].x + c[R].x >= (1 << i + 1)) R--;
			ans ^= ((std::max(R, j) - std::max(L, j + 1) + 1) & 1) << i;
		}
		L = n + 1, R = n;
		for(int j = 1; j <= n; j++)
		{
			while(L > 1 && c[j].x + c[L - 1].x >= (1 << i) + (1 << i + 1)) L--;
			while(R >= 1 && c[j].x + c[R].x >= (1 << i + 1) + (1 << i + 1)) R--;
			ans ^= ((std::max(R, j) - std::max(L, j + 1) + 1) & 1) << i;
		}
	}
	printf("%d\n", ans);
}