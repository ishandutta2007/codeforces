#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>

using namespace std;

int n , m , t;
int w[1001] , b[1001];
int f[1001];
int g[1001][1002][2] , l[1001];
int p[1001][1001];

int fa(int x)
{
	if (f[x] == x)
	    return x;
	else
	{
		f[x] = fa(f[x]);
		return f[x];
	}    
}

int main ()
{
    int i , j , k , x , y , fx , fy;
    scanf("%d%d%d",&n,&m,&t);
    for (i = 1 ; i <= n ; i++)
    {
         scanf("%d",&w[i]);
         f[i] = i;
         l[i] = 1;
    }
    for (i = 1 ; i <= n ; i++)
         scanf("%d",&b[i]);
    for (i = 1 ; i <= m ; i++)
	{
		scanf("%d%d",&x,&y);
		fx = fa(x);
		fy = fa(y);
		if (fx != fy)
		    f[fy] = fx;
	}     
	for (i = 1 ; i <= n ; i++)
	{
		fx = fa(i);
		l[fx]++;
		g[fx][l[fx]][0] = w[i];
		g[fx][l[fx]][1] = b[i];
		g[fx][1][0] += w[i];
		g[fx][1][1] += b[i];
	}
	for (i = 1 ; i <= n ; i++)
	{
		for (j = 1 ; j <= t ; j++)
		{
			p[i][j] = max(p[i-1][j],p[i][j-1]);
			for (k = 1 ; k <= l[i] ; k++)
				if ((j >= g[i][k][0]) && ((p[i-1][j-g[i][k][0]]+g[i][k][1]) > p[i][j]))
				    p[i][j] = (p[i-1][j-g[i][k][0]]+g[i][k][1]);
	    }
	}
	printf("%d\n",p[n][t]);
    //system("PAUSE");
	return 0;
}