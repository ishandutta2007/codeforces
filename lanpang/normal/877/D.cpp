#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 1e3+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , m , k , xx , yy , xxx , yyy , f[maxn][maxn] , l;
char c[maxn][maxn] , cc;

struct mmp{
	int x , y;
}q[maxn*maxn];

int main ()
{
	int i , j , head , tail , t;
	cin >> n >> m >> k;
	for (i = 1 ; i <= n ; i++)
	{
		cc = getchar();
		for (j = 1 ; j <= m ; j++)
		{
			c[i][j] = getchar();
			f[i][j] = -1;
		}
	}
	cin >> xx >> yy >> xxx >> yyy;
	if (xx != xxx || yy != yyy)
	{
		f[xx][yy] = 0;
		q[1].x = xx;
		q[1].y = yy;
		head = 1;
		tail = 1;
		while (head <= tail)
		{
			t = 0; 
			for (i = q[head].x-1 ; i >= 1 ; i--)
			{
				t++;
				if (t > k) break;
				if (f[i][q[head].y] == f[q[head].x][q[head].y]+1) continue;
				if (c[i][q[head].y] == '#' || f[i][q[head].y] >= 0) break;
				tail++;
				q[tail].x = i;
				q[tail].y = q[head].y;
				f[q[tail].x][q[tail].y] = f[q[head].x][q[head].y]+1;
				if (q[tail].x == xxx && q[tail].y == yyy) goto GG;
			}
			t = 0; 
			for (i = q[head].x+1 ; i <= n ; i++)
			{
				t++;
				if (t > k) break;
				if (f[i][q[head].y] == f[q[head].x][q[head].y]+1) continue;
				if (c[i][q[head].y] == '#' || f[i][q[head].y] >= 0) break;
				tail++;
				q[tail].x = i;
				q[tail].y = q[head].y;
				f[q[tail].x][q[tail].y] = f[q[head].x][q[head].y]+1;
				if (q[tail].x == xxx && q[tail].y == yyy) goto GG;
			}
			t = 0; 
			for (i = q[head].y-1 ; i >= 1 ; i--)
			{
				t++;
				if (t > k) break;
				if (f[q[head].x][i] == f[q[head].x][q[head].y]+1) continue;
				if (c[q[head].x][i] == '#' || f[q[head].x][i] >= 0) break;
				tail++;
				q[tail].x = q[head].x;
				q[tail].y = i;
				f[q[tail].x][q[tail].y] = f[q[head].x][q[head].y]+1;
				if (q[tail].x == xxx && q[tail].y == yyy) goto GG;
			}
			t = 0; 
			for (i = q[head].y+1 ; i <= m ; i++)
			{
				t++;
				if (t > k) break;
				if (f[q[head].x][i] == f[q[head].x][q[head].y]+1) continue;
				if (c[q[head].x][i] == '#' || f[q[head].x][i] >= 0) break;
				tail++;
				q[tail].x = q[head].x;
				q[tail].y = i;
				f[q[tail].x][q[tail].y] = f[q[head].x][q[head].y]+1;
				if (q[tail].x == xxx && q[tail].y == yyy) goto GG;
			}
			head++;
		}
		GG:cout << f[xxx][yyy] << "\n";
	}
	else cout << "0\n";
	//system("PAUSE");
	return 0;
}