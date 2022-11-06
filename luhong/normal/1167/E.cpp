#include <cstdio>
#include <cstring>
#include <iostream>
#define MN 1010000

int a[MN];
int l[MN], r[MN];
int w[MN];

int main()
{
	memset(l, 0x3f, sizeof(l));
	int n, x; scanf("%d%d", &n, &x);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]), l[a[i]] = std::min(l[a[i]], i), r[a[i]] = std::max(r[a[i]], i); 
	w[x + 1] = n + 1; 
	int R = 0, j;
	for(int i = x; i >= 1; i--)
	{
		if(r[i] == 0) w[i] = w[i + 1];
		else if(r[i] < w[i + 1]) w[i] = l[i];
		else {R = w[i + 1]; j = i + 1; break;}
	}
	if(R == 0) return 0 * printf("%lld\n", 1ll * x * (x + 1) / 2);
	long long ans = 0; int L = 0;
	for(int i = 1; i <= x; i++)
	{
		while(j <= x && w[j] < L) j++;
		ans += (x - j + 2); 
		if(!r[i]) continue;
		if(l[i] < L) break;
		L = r[i]; 
	} 
	printf("%lld\n", ans);
}