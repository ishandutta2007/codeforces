#include <cstdio>
using namespace std;

typedef long long ll;

const int Maxn = 1005;

int n, m;
ll BIT[2][2][Maxn][Maxn];

void Update(int x, int y, ll val)
{
	int i1 = x % 2, i2 = y % 2;
	x = (x + 1) / 2, y = (y + 1) / 2;
	for (int i = x; i <= n; i += i & -i)
		for (int j = y; j <= n; j += j & -j)
			BIT[i1][i2][i][j] ^= val;
}

void Update(int x0, int y0, int x1, int y1, ll val)
{
	Update(x0, y0, val); 
	Update(x0, y1 + 1, val);
	Update(x1 + 1, y0, val);
	Update(x1 + 1, y1 + 1, val);
}

ll Get(int x, int y)
{
	int i1 = x % 2, i2 = y % 2;
	x = (x + 1) / 2, y = (y + 1) / 2;
	ll res = 0;
	for (int i = x; i > 0; i -= i & -i)
		for (int j = y; j > 0; j -= j & -j)
			res ^= BIT[i1][i2][i][j];
	return res;
}

ll Get(int x0, int y0, int x1, int y1)
{
	return Get(x1, y1) ^ Get(x1, y0 - 1) ^ Get(x0 - 1, y1) ^ Get(x0 - 1, y0 - 1);
}

int main()
{
	scanf("%d %d", &n, &m); n = (n + 1) / 2;
	while (m--) {
		int t, x0, y0, x1, y1; ll val;
		scanf("%d %d %d %d %d", &t, &x0, &y0, &x1, &y1);
		if (t == 1) printf("%I64d\n", Get(x0, y0, x1, y1));
		else { scanf("%I64d", &val); Update(x0, y0, x1, y1, val); }
	}
	return 0;
}