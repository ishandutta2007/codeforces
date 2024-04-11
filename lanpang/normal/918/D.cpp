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
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

vector <int> a[110] , b[110];
int n , m , p[110][110][30] , pp[110][110][30];

int dfs(int x , int y , int la)
{
	if (pp[x][y][la] == 0) 
	{
		int ret = 0;
		if (x != y)
		{
			for (int i = 0 ; i < a[x].size() ; i++)
			{
				if (b[x][i] >= la)
				{
					ret |= (1-dfs(y,a[x][i],b[x][i]));
				}
			}
		}
		pp[x][y][la] = 1;
		p[x][y][la] = ret;
	}
	return p[x][y][la];
}

int main ()
{
	int x , y , i , j;
	char c;
	cin >> n >> m;
	for (i = 1 ; i <= m ; i++)
	{
		scanf("%d %d %c",&x,&y,&c);
		j = c-'a';
		a[x].push_back(y);
		b[x].push_back(j);
	}
	for (i = 1 ; i <= n ; i++)
	{
		for (j = 1 ; j <= n ; j++)
		{
			if (dfs(i,j,0)) cout << "A";
			else cout << "B";
		}
		cout << "\n";
	}
	//system("PAUSE");
	return 0;
}