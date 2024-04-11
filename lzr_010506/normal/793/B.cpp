#include <bits/stdc++.h>
int xx[4] = {-1, 0, 1, 0};
int yy[4] = {0, -1, 0, 1};
using namespace std;

char ch[1024][1024];
int a[1024][1024] , stx , sty , tx , ty , n , m , vich[1024][1024][4] , Dis[1024][1024][4];
queue < int > qx , qy , qz;

inline void add(int x , int y , int z)
{
	qx.push(x);
	qy.push(y);
	qz.push(z);
	vich[x][y][z] = 1;
}

void bfs(int stx, int sty)
{
	add(stx, sty, 0);
	add(stx, sty, 1);
	add(stx, sty, 2);
	add(stx, sty, 3);
	memset(Dis , 0x3f , sizeof(Dis));
	Dis[stx][sty][0] = Dis[stx][sty][1] = Dis[stx][sty][2] = Dis[stx][sty][3] = 0;
	while(!qx.empty())
	{
		int x = qx.front();
		int y = qy.front();
		int z = qz.front();
		qx.pop();
		qy.pop();
		qz.pop();
		vich[x][y][z] = 0;
		for(int k = 0; k < 4; k ++)
			if(a[x + xx[k]][y + yy[k]] && Dis[x + xx[k]][y + yy[k]][k] > Dis[x][y][z] + (z != k))
			{
				Dis[x + xx[k]][y + yy[k]][k] = Dis[x][y][z] + (z != k);
				if(!vich[x + xx[k]][y + yy[k]][k])
					add(x + xx[k] , y + yy[k] , k);
			}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) 
		scanf("%s", ch[i] + 1);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			if(ch[i][j] == 'S') stx = i , sty = j;
			else if(ch[i][j] == 'T') tx = i , ty = j;
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			if(ch[i][j] != '*')
				a[i][j] = 1;
	bfs(stx , sty);
	int ans = 3;
	for(int i = 0; i < 4; i ++)
		ans = min(ans, Dis[tx][ty][i]);
	if(ans <= 2) puts("YES");
	else puts("NO");
	return 0;
}