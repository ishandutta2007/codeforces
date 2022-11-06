#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 1000000007
#define MN 65536

int inc(int a, int b) {return (a += b) >= mod ? a - mod : a;}
int dec(int a, int b) {return (a -= b) < 0 ? a + mod : a;}

int A[MN], B[MN], ok[16], tot = 0;
char s[510];
int f[510][MN], id[510][510]; 

void FWT1()
{
	for(int i = 0; i < (1 << 4); i++)
		for(int j = 0; j < (1 << 16); j++)
			if(!((j >> i) & 1)) A[j] = inc(A[j], A[j ^ (1 << i)]);
			
	for(int i = 0; i < (1 << 4); i++)
		for(int j = 0; j < (1 << 16); j++)
			if(!((j >> i) & 1)) B[j] = inc(B[j], B[j ^ (1 << i)]);
	
	for(int j = 0; j < (1 << 16); j++) A[j] = 1ll * A[j] * B[j] % mod;
	
	for(int i = 0; i < (1 << 4); i++)
		for(int j = 0; j < (1 << 16); j++)
			if(!((j >> i) & 1)) A[j] = dec(A[j], A[j ^ (1 << i)]);
}

void FWT2()
{
	for(int i = 0; i < (1 << 4); i++)
		for(int j = 0; j < (1 << 16); j++)
			if((j >> i) & 1) A[j] = inc(A[j], A[j ^ (1 << i)]);
			
	for(int i = 0; i < (1 << 4); i++)
		for(int j = 0; j < (1 << 16); j++)
			if((j >> i) & 1) B[j] = inc(B[j], B[j ^ (1 << i)]);
	
	for(int j = 0; j < (1 << 16); j++) A[j] = 1ll * A[j] * B[j] % mod;
	
	for(int i = 0; i < (1 << 4); i++)
		for(int j = 0; j < (1 << 16); j++)
			if((j >> i) & 1) A[j] = dec(A[j], A[j ^ (1 << i)]);
}

void solve(int l, int r)
{
	if(id[l][r]) return;
	id[l][r] = ++tot;
	if(l == r)
	{
		for(int x = 0; x < 8; x++)
		{
			if(s[l] == '?' || s[l] == 'A' && x == 0 || s[l] == 'a' && x == 1 || s[l] == 'B' && x == 2 || s[l] == 'b' && x == 3 || s[l] == 'C' && x == 4 || s[l] == 'c' && x == 5 || s[l] == 'D' && x == 6 || s[l] == 'd' && x == 7)
			{
				int T = 0;
				for(int S = 0; S < (1 << 4); S++)
				{
					for(int j = 0; j < 4; j++)
					{
						if(x / 2 == j) T += (((S >> j) & 1) ^ (x & 1)) << S;
					}
				}
				f[id[l][r]][T]++;
			}
		}
		return;
	}
	
	int sum = 0, mid;
	for(int i = l; i <= r; i++)
	{
		if(s[i] == '(') sum++;
		if(s[i] == ')') sum--;
		if(sum == 0 && s[i] != ')') {mid = i; break;}
	}
	
	solve(l + 1, mid - 2); solve(mid + 2, r - 1);
	
	if(s[mid] == '?' || s[mid] == '&')
	{
		memcpy(A, f[id[l + 1][mid - 2]], sizeof(A));
		memcpy(B, f[id[mid + 2][r - 1]], sizeof(B));
		FWT1(); memcpy(f[id[l][r]], A, sizeof(A)); 
	}
	if(s[mid] == '?' || s[mid] == '|')
	{
		memcpy(A, f[id[l + 1][mid - 2]], sizeof(A));
		memcpy(B, f[id[mid + 2][r - 1]], sizeof(B));
		FWT2(); 
		for(int S = 0; S < (1 << 16); S++) f[id[l][r]][S] = inc(f[id[l][r]][S], A[S]);
	}
}

int main()
{
	scanf("%s", s + 1);
	int len = strlen(s + 1);
	solve(1, len);
	int n; scanf("%d", &n);
	memset(ok, -1, sizeof(ok));
	for(int i = 1; i <= n; i++)
	{
		int a, b, c, d, e; scanf("%d%d%d%d%d", &a, &b, &c, &d, &e);
		ok[a + (b << 1) + (c << 2) + (d << 3)] = e;
	}
	int ans = 0;
	for(int S = 0; S < (1 << 16); S++)
	{
		bool okk = 0;
		for(int j = 0; j < 16; j++)
			if(ok[j] != -1 && ok[j] != ((S >> j) & 1)) {okk = 1; break;}
		if(!okk) ans = inc(ans, f[id[1][len]][S]);
	}
	printf("%d\n", ans);
}