#include <iostream>
#include <cstdio>

int ans = 0, n, m, k;
int h[201000], nxt[401000], to[401000], K = 1;
int U[201000], V[201000], Ans[201000], q[201000], d[201000];
int H, T;
bool used[201000];

void ins(int u, int v) {nxt[++K] = h[u]; h[u] = K; to[K] = v;}

void del(int x, int y)
{
	if(d[x] >= k && d[y] >= k)
	{
		d[x]--; d[y]--;
		H = 0, T = 0;
		if(d[x] < k) q[T++] = x;
		if(d[y] < k) q[T++] = y;
		while(H < T)
		{
			int u = q[H++]; ans--;
			for(int i = h[u]; i; i = nxt[i])
			{
				if(used[i >> 1]) continue;
				if(--d[to[i]] == k - 1) q[T++] = to[i];
			}
		}
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 1; i <= m; i++)
	{
		scanf("%d%d", &U[i], &V[i]);
		ins(U[i], V[i]); ins(V[i], U[i]);
		d[U[i]]++; d[V[i]]++;
	}
	ans = n;
	H = 0, T = 0;
	for(int i = 1; i <= n; i++) if(d[i] < k) q[T++] = i;
	while(H < T)
	{
		int u = q[H++]; ans--;
		for(int i = h[u]; i; i = nxt[i])
		{
			if(--d[to[i]] == k - 1) q[T++] = to[i];
		}
	}
	for(int i = m; i >= 1; i--)
	{
		Ans[i] = ans; used[i] = 1;
		del(U[i], V[i]);
	}
	for(int i = 1; i <= m; i++) printf("%d\n", Ans[i]);
	return 0;
}