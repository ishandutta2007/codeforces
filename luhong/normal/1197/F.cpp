#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define mod 998244353
#define MN 1010

struct xxx{
	int a[64][64];
}t[33];

struct yyy{
	int a[64];
};

typedef std::pair<int, int> P;

int a[MN];
int ok[4][4];
bool used[4];
std::vector<P> v[MN];
int f[MN][4];
int cnt[4];

xxx operator * (xxx a, xxx b)
{
	xxx c; memset(c.a, 0, sizeof(c.a));
	for(int i = 0; i < 64; i++)
		for(int k = 0; k < 64; k++)
			if(a.a[i][k])
			for(int j = 0; j < 64; j++)
				c.a[i][j] = (c.a[i][j] + 1ll * a.a[i][k] * b.a[k][j]) % mod;
	return c;
}

yyy operator * (yyy a, xxx b)
{
	yyy c; memset(c.a, 0, sizeof(c.a));
	for(int k = 0; k < 64; k++)
		if(a.a[k])
		for(int j = 0; j < 64; j++)
			c.a[j] = (c.a[j] + 1ll * a.a[k] * b.a[k][j]) % mod;
	return c;
}

yyy operator ^ (yyy a, int p)
{
	for(int i = 0; i <= 30; i++)
		if((p >> i) & 1)
			a = a * t[i];
	return a;
}

int main()
{
	int n; scanf("%d", &n);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	int m; scanf("%d", &m);
	for(int i = 1; i <= m; i++)
	{
		int x, y, c; scanf("%d%d%d", &x, &y, &c);
		v[x].push_back(P(y, c));
	}
	
	for(int i = 1; i <= n; i++) std::sort(v[i].begin(), v[i].end());
	
	for(int i = 1; i <= 3; i++)
		for(int j = 1; j <= 3; j++)
			scanf("%d", &ok[i][j]);
	
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			for(int k = 0; k < 4; k++)
				for(int c = 1; c <= 3; c++)
				{
					memset(used, 0, sizeof(used));
					if(ok[c][1]) used[k] = 1;
					if(ok[c][2]) used[j] = 1;
					if(ok[c][3]) used[i] = 1;
					int l;
					for(l = 0; l < 4; l++) if(!used[l]) break;
					int A = i * 16 + j * 4 + k;
					int B = j * 16 + k * 4 + l;
					t[0].a[A][B]++;
				}
				
	for(int i = 1; i <= 30; i++) t[i] = t[i - 1] * t[i - 1]; 
	
	f[0][0] = 1;
	for(int i = 1; i <= n; i++)
	{
		yyy now; memset(now.a, 0, sizeof(now.a)); now.a[63] = 1; 
		int lst = 0;
		
		for(int j = 0; j < v[i].size(); j++)
		{
			now = now ^ (v[i][j].first - lst - 1);
			
			yyy g; memset(g.a, 0, sizeof(g.a));
			for(int x = 0; x < 4; x++)
				for(int y = 0; y < 4; y++)
					for(int z = 0; z < 4; z++)
					{
						memset(used, 0, sizeof(used));
						if(ok[v[i][j].second][1]) used[z] = 1;
						if(ok[v[i][j].second][2]) used[y] = 1;
						if(ok[v[i][j].second][3]) used[x] = 1;
						int k;
						for(k = 0; k < 4; k++) if(!used[k]) break;
						int A = x * 16 + y * 4 + z;
						int B = y * 16 + z * 4 + k;
						g.a[B] = (g.a[B] + now.a[A]) % mod;
					}
					
			now = g;
			lst = v[i][j].first;
		}
		
		now = now ^ (a[i] - lst); 
		memset(cnt, 0, sizeof(cnt));
		for(int j = 0; j < 64; j++) cnt[j % 4] = (cnt[j % 4] + now.a[j]) % mod;
		for(int j = 0; j < 4; j++)
			for(int k = 0; k < 4; k++)
				f[i][j ^ k] = (f[i][j ^ k] + 1ll * f[i - 1][j] * cnt[k]) % mod;
	}
	printf("%d\n", f[n][0]);
}