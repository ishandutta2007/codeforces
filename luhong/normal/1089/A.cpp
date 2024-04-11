#include <cstdio>
#include <iostream>

bool f[210][210][4][4];
int pre[210][210][4][4][4];

bool F(int a, int b, int c, int d)
{
	if(a < 0 || b < 0 || c < 0 || d < 0 || c == 3 || d == 3) return 0;
	return f[a][b][c][d];
}

int main()
{
	f[0][0][0][0] = 1;
	for(int i = 0; i <= 200; i++)
		for(int j = 0; j <= 200; j++)
			for(int x = 0; x <= 3; x++)
				for(int y = 0; y <= 3; y++)
				{
					int MaxT;
					if(x == 3 && y == 2 || x == 2 && y == 3) MaxT = 15;
					else MaxT = 25;
					for(int a = 0; a <= MaxT - 2; a++)
					{
						if(F(i - a, j - MaxT, x, y - 1))
						{
							f[i][j][x][y] = 1;
							pre[i][j][x][y][0] = i - a;
							pre[i][j][x][y][1] = j - MaxT;
							pre[i][j][x][y][2] = x;
							pre[i][j][x][y][3] = y - 1;
						}
						if(F(i - MaxT, j - a, x - 1, y))
						{
							f[i][j][x][y] = 1;
							pre[i][j][x][y][0] = i - MaxT;
							pre[i][j][x][y][1] = j - a;
							pre[i][j][x][y][2] = x - 1;
							pre[i][j][x][y][3] = y;
						}
					}
					for(int a = MaxT - 1; a <= 198; a++)
					{
						int b = a + 2;
						if(F(i - a, j - b, x, y - 1))
						{
							f[i][j][x][y] = 1;
							pre[i][j][x][y][0] = i - a;
							pre[i][j][x][y][1] = j - b;
							pre[i][j][x][y][2] = x;
							pre[i][j][x][y][3] = y - 1;
						}
					}
					for(int a = MaxT + 1; a <= 200; a++)
					{
						int b = a - 2;
						if(F(i - a, j - b, x - 1, y))
						{
							f[i][j][x][y] = 1;
							pre[i][j][x][y][0] = i - a;
							pre[i][j][x][y][1] = j - b;
							pre[i][j][x][y][2] = x - 1;
							pre[i][j][x][y][3] = y;
						}
					}
				}
	int m; scanf("%d", &m);
	for(int i = 1; i <= m; i++)
	{
		int a, b; scanf("%d%d", &a, &b);
//		if(a == 0 && b == 0) {puts("Impossible"); continue;}
		int X = -1e9, Y = 0;
		for(int y = 0; y <= 3; y++)
		{
			if(f[a][b][3][y] == 1)
			{
				if(3 - y > X - Y) X = 3, Y = y;
			}
			if(f[a][b][y][3] == 1)
			{
				if(y - 3 > X - Y) X = y, Y = 3;
			}
		}
		if(X == -1e9) puts("Impossible");
		else
		{
			printf("%d:%d\n", X, Y);
			int A = a, B = b;
			int e[6], f[6], t = 0;
			while(1)
			{
				if(A == 0 && B == 0 && X == 0 && Y == 0) break;
				++t; 
				int aa = pre[A][B][X][Y][0], bb = pre[A][B][X][Y][1], xx = pre[A][B][X][Y][2], yy = pre[A][B][X][Y][3];
				e[t] = A - aa; f[t] = B - bb;
				A = aa, B = bb, X = xx, Y = yy; 
			}
			for(int i = t; i >= 1; i--) printf("%d:%d ", e[i], f[i]); puts("");
		}
	}
	return 0;
}