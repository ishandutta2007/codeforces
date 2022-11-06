#include <iostream>
#include <cstring>
#include <cstdio>
#define MN 1010000
#define mod 1000000007

int f[MN], s[MN];
char c[MN];
int a[MN], p[MN], nxt1[MN];
int st[MN], top = 0;
int nxt0[MN];

int main()
{
	scanf("%s", c + 1);
	bool ok = 0;
	int n = strlen(c + 1);
	int l = n, r = 1;
	for(int i = 1; i <= n; i++)
	{
		if(c[i] == '1')
		{
			ok = 1;
			l = std::min(l, i);
			r = std::max(r, i);
		}
	}
	if(!ok) return 0 * printf("%d\n", n);
	if(l == r) return 0 * printf("%lld\n", 1ll * l * (n - r + 1) % mod);
	
	int N = 0;
	for(int i = l; i <= r; i++)
	{
		if(c[i] == '0')
		{
			if(c[i] == c[i - 1]) a[N]++;
			else a[++N] = 1, p[N] = i;
		}
	}
	
	for(int i = n; i >= 1; i--)
	{
		nxt0[i] = nxt0[i + 1];
		nxt1[i] = nxt1[i + 1];
		if(c[i + 1] == '0') nxt0[i] = i + 1;
		else nxt1[i] = i + 1;
	}
	
/*	for(int i = 1; i <= N; i++)
	{
		for(int j = -1; j < a[i]; j++)
			nxt1[p[i] + j] = p[i] + a[i];
	}*/
	
	for(int i = 1; i <= N; i++)
	{
		while(top && a[i] > a[st[top]])
		{
			nxt0[p[st[top]] + a[st[top]] - 1] = p[i] + a[st[top]];
			top--;
		}
		st[++top] = i;
	}
	
	for(int i = 1; i <= top; i++)
		nxt0[p[st[i]] + a[st[i]] - 1] = 0;
	
	l++; r--;
	
	f[l - 1] = 1;
	for(int i = l - 1; i < r; i++)
	{
		if(nxt1[i]) f[nxt1[i]] = (f[nxt1[i]] + f[i]) % mod;
		if(nxt0[i]) f[nxt0[i]] = (f[nxt0[i]] + f[i]) % mod; 
	}
	
	int sum = 1;
	for(int i = l - 1; i <= r; i++) sum = (sum + f[i]) % mod;
	
	printf("%lld\n", 1ll * sum * (l - 1) % mod * (n - r) % mod);
}