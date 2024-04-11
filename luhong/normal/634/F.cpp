#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define MN 3010

std::vector<int> v[MN];
int cnt[MN], lst[MN], nxt[MN];

void del(int x)
{
	nxt[lst[x]] = nxt[x];
	lst[nxt[x]] = lst[x];
}

int main()
{
	int r, c, n, K; scanf("%d%d%d%d", &r, &c, &n, &K); K--;
	for(int i = 1; i <= n; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		v[x].push_back(y);
	}
	lst[0] = 0; nxt[c + 1] = c + 1;
	long long ans = 0;
	for(int i = 1; i <= r; i++)
	{
		for(int j = i; j <= r; j++)
		{
			for(int k = 0; k < v[j].size(); k++)
				cnt[v[j][k]]++;
		}
		for(int j = 1; j <= c + 1; j++)
		{
			if(!cnt[j - 1]) lst[j] = lst[j - 1];
			else lst[j] = j - 1;
		}
		for(int j = c; j >= 0; j--)
		{
			if(!cnt[j + 1]) nxt[j] = nxt[j + 1];
			else nxt[j] = j + 1;
		}
		int now = 0;
		for(int j = 1; j <= c; j++)
		{
			int R, sum = 0;
			for(R = j; R != c + 1 && sum + cnt[R] <= K; R = nxt[R]) sum += cnt[R]; R = lst[R];
			now += nxt[R] - j; 
		}
		ans += now;
		for(int j = r; j > i; j--)
		{
			for(int k = 0; k < v[j].size(); k++)
			{
				int R, sum = 0;
				for(R = v[j][k]; R != c + 1 && sum + cnt[R] <= K; R = nxt[R]) sum += cnt[R]; R = lst[R];
				int L = v[j][k];
				while(L && (sum + cnt[nxt[R]] - 1 <= K ? nxt[R] : R) >= v[j][k])
				{
					if(sum + cnt[nxt[R]] - 1 <= K) now += 1ll * (nxt[nxt[R]] - nxt[R]) * (L - lst[L]);
					L = lst[L];
					sum += cnt[L];
					while(sum > K) sum -= cnt[R], R = lst[R]; 
				}
				if(--cnt[v[j][k]] == 0) del(v[j][k]);
			}
			ans += now;
		}
		memset(cnt, 0, sizeof(cnt));
	}
	printf("%lld\n", 1ll * r * (r + 1) / 2 * c * (c + 1) / 2 - ans);
}