#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
int n , m , q , x , y , z , f[83][83][83][83];
vector < pair < int , int > > linker[83];

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}

inline void addedge(int x , int y , int z)
{
	linker[x].push_back(pair < int , int > (y , z));
}

inline void update(int & x , int y)
{
	if(x > y) x = y;
}

#define cur linker[j][v]

int main()
{
	n = read();
	m = read();
	q = read();
	if(m == 1) {cout << 0; return 0;}
	while(q --)
	{
		x = read();
		y = read();
		z = read();
		addedge(x , y , z);
	}
	memset(f , 0x3f , sizeof(f));
	for(int i = 1; i <= n; i ++)
	{
		if(i != 1) f[1][i][1][i - 1] = 0;
		if(i != n) f[1][i][i + 1][n] = 0;
	}
	int ans = 1000000000;
	for(int i = 1; i <= m - 1; i ++)
		for(int j = 1; j <= n; j ++)
			for(int a = 1; a <= n; a ++)
				for(int b = a; b <= n; b ++)
					if(f[i][j][a][b] < 1000000000)
					{
						int G = f[i][j][a][b];
						for(int v = 0; v < linker[j].size(); v ++)
							if(cur.X >= a && cur.X <= b)
							{
								if(i + 1 == m) update(ans , G + linker[j][v].Y);
								if(cur.X != a) update(f[i + 1][ cur.X ][a][ cur.X - 1 ] , G + cur.Y);
								if(cur.X != b) update(f[i + 1][ cur.X ][ cur.X + 1 ][b] , G + cur.Y);
							}
                        //for(int v = 0; v < linker[j].size(); v ++)
					}
	if(ans == 1000000000) cout << -1 << endl;
	else cout << ans << endl;
	return 0;
}