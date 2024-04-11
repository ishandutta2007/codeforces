#include <stdio.h>

bool cpu[128][128][128];

bool linked(int x1, int y1, int z1, int x3, int y3, int z3)
{
	if (!cpu[x1][y1][z1] || !cpu[x3][y3][z3])
		return true;
	bool res = false;
	int x2 = x1 + 1, y2 = y1, z2 = z1;
	res |= (cpu[x2][y2][z2] && ((x3 >= x2) && (y3 >= y2) && (z3>=z2) && (x3 - x2 + y3 - y2 + z3 - z2 == 1)));
	x2 = x1, y2 = y1+1, z2 = z1;
	res |= (cpu[x2][y2][z2] && ((x3 >= x2) && (y3 >= y2) && (z3 >= z2) && (x3 - x2 + y3 - y2 + z3 - z2 == 1)));
	x2 = x1, y2 = y1, z2 = z1 + 1;
	res |= (cpu[x2][y2][z2] && ((x3 >= x2) && (y3 >= y2) && (z3 >= z2) && (x3 - x2 + y3 - y2 + z3 - z2 == 1)));
	return res;
}

int main()
{
	int n, m, k;
	scanf("%d%d%d\n", &n, &m, &k);
	for (int x = 1; x <= n; x++)
	{
		for (int y = 1; y <= m; y++)
		{
			for (int z = 1; z <= k; z++)
			{
				char c;
				scanf("%c", &c);
				cpu[x][y][z] = (c == '1');
			}
			if (x<n || y<m)
				scanf("\n");
		}
		if (x<n)
			scanf("\n");
	}

	int ans = 0;
	for (int x = 1; x <= n; x++)
	{
		for (int y = 1; y <= m; y++)
		{
			for (int z = 1; z <= k; z++)
			{
				if (cpu[x][y][z])
				{
					cpu[x][y][z] = false;
					bool crit;
					crit = (
						(!linked(x - 1, y, z, x + 1, y, z))
						|| (!linked(x - 1, y, z, x, y + 1, z))
						|| (!linked(x - 1, y, z, x, y, z + 1))
						|| (!linked(x, y - 1, z, x + 1, y, z))
						|| (!linked(x, y - 1, z, x, y + 1, z))
						|| (!linked(x, y - 1, z, x, y, z + 1))
						|| (!linked(x, y, z - 1, x + 1, y, z))
						|| (!linked(x, y, z - 1, x, y + 1, z))
						|| (!linked(x, y, z - 1, x, y, z + 1))
						);
					cpu[x][y][z] = true;
					if (crit)
						ans++;
				}
			}
		}
	}
	printf("%d", ans);

}