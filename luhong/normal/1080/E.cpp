#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <vector>
#include <cstring>
#include <set> 
#define MN 255
#define mod 998244853

char c[MN][MN];
int n, m;
bool ok[MN][MN][MN];
int cnt[30];
int k[MN][MN][MN], s[MN * 2], R[30], base[30];
int p[2 * MN];
int up[MN * 2], down[MN * 2];

void manacher()
{
    int mx = 1, id = 1;
    s[0] = -1; s[2 * n] = -1;
    for(int i = 2 * n - 1; i >= 1; i--)
    {
    	if(i & 1) s[i] = s[i / 2 + 1];
    	else s[i] = -1;
	}
    int len = 2 * n - 1;
    for(int i = 1; i <= len; i++)
    {
        if(i <= mx)
        {
            int j = id - (i - id);
            if(i + p[j] < mx) {p[i] = p[j]; continue;}
        }
        int l = mx - i + 1;
        while(i + l <= 2 * n - 1 && i - l > 0 && s[i + l] == s[i - l]) l++;
        p[i] = l - 1; mx = i + l - 1; id = i;
    }
}

void init()
{
	for(int i = 1; i <= n; i++)
		for(int l = 1; l <= m; l++)
		{
			memset(cnt, 0, sizeof(cnt));
			for(int r = l; r <= m; r++)
			{
				int d = c[i][r] - 'a' + 1;
				int z = cnt[d]; 
				k[i][l][r] = (k[i][l][r - 1] + 1ll * (3 * z * z + 3 * z + 1) * d * d + 1ll * (2 * z + 1) * R[d] + base[d]) % mod;
				//hashcnt[i]^3 * i^2 + cnt[i]^2 * R[i] + cnt[i] * base[i]
				cnt[d]++;
			}
		}
}

int solve(int l, int r)
{
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		s[i] = k[i][l][r];
	}
	manacher();
	up[0] = 0; down[2 * n] = 2 * n;
	for(int i = 1; i <= 2 * n - 1; i++)
	{
		if(i % 2 == 0 || ok[i / 2 + 1][l][r]) up[i] = up[i - 1];
		else up[i] = i + 1;
	}
	for(int i = 2 * n - 1; i >= 1; i--)
	{
		if(i % 2 == 0 || ok[i / 2 + 1][l][r]) down[i] = down[i + 1];
		else down[i] = i - 1;
	}
	for(int i = 1; i <= 2 * n - 1; i++)
	{
		if(up[i] > i) continue; 
		int len = std::min(i - up[i], down[i] - i);
		if(i & 1) ans += std::min(len, p[i]) / 2 + 1;
		else ans += std::min(len, p[i]) + 1 >> 1; 
	}
	return ans;
}

int main()
{
	srand(19260817);
	for(int i = 0; i < 26; i++) R[i] = rand() * (i + 1);
	base[0] = 1; for(int i = 1; i < 26; i++) base[i] = 1ll * base[i - 1] * 83 % mod;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
	{
		scanf("%s", c[i] + 1);
	}
	init();
	for(int i = 1; i <= n; i++)
	{
		for(int l = 1; l <= m; l++)
		{
			memset(cnt, 0, sizeof(cnt));
			int s = 0;
			for(int r = l; r <= m; r++)
			{
				cnt[c[i][r] - 'a'] ^= 1;
				if(cnt[c[i][r] - 'a'] == 0) s--;
				else s++;
				if(s <= 1) ok[i][l][r] = 1;
				else ok[i][l][r] = 0;
			}
		}
	}
	int ans = 0;
	for(int l = 1; l <= m; l++)
		for(int r = l; r <= m; r++) ans += solve(l, r);
	printf("%d\n", ans);	
	return 0;
}