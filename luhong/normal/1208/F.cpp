#include <cstdio>
#include <iostream>
#define MN 2100000

int f[MN], a[MN];

void add(int x, int i)
{
	if(f[x] == 2) return;
	if(i == 21) {f[x]++; return;} 
	add(x, i + 1);
	if((x >> i) & 1) add(x ^ (1 << i), i + 1);
}

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]); 
	int ans = 0;
	for(int i = n; i >= 1; i--)
	{
		int now = 0;
		for(int j = 20; j >= 0; j--)
			if(!((a[i] >> j) & 1))
				if(f[now + (1 << j)] == 2) now += (1 << j);
		if(i <= n - 2) ans = std::max(ans, now ^ a[i]);
		add(a[i], 0);
	}
	printf("%d\n", ans);
}