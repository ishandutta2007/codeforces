#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 2e4+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

struct mmp{
	int p , x , y;
}st[maxn];

int n , m , a[10][110] , top , sp , tr[110];

void move(int j)
{
	if (j <= n)
	{
		if (j == 1)
		{
			if (a[2][1])
			{
				top++;
				st[top].p = a[2][1];
				st[top].x = 3;
				st[top].y = 1;
			}
			a[3][1] = a[2][1];
			a[2][1] = 0;
		}
		else
		{
			if (a[2][j])
			{
				top++;
				st[top].p = a[2][j];
				st[top].x = 2;
				st[top].y = j-1;
			}
			a[2][j-1] = a[2][j];
			a[2][j] = 0;
		}
	}
	else
	{
		if (j == n+1)
		{
			if (a[3][n])
			{
				top++;
				st[top].p = a[3][n];
				st[top].x = 2;
				st[top].y = n;
			}
			a[2][n] = a[3][n];
			a[3][n] = 0;
		}
		else
		{
			if (a[3][n+n-j+1])
			{
				top++;
				st[top].p = a[3][n+n-j+1];
				st[top].x = 3;
				st[top].y = n+n-j+2;
			}
			a[3][n+n-j+2] = a[3][n+n-j+1];
			a[3][n+n-j+1] = 0;
		}
	}
}

void check(int j)
{
	if (tr[j])
	{
		if (tr[j] <= n)
		{
			if (j == a[2][tr[j]])
			{
				top++;
				st[top].p = a[2][tr[j]];
				st[top].x = 1;
				st[top].y = tr[j];
				a[2][tr[j]] = 0;
			}
		}
		else
		{	
			if (j == a[3][n+n-tr[j]+1])
			{
				top++;
				st[top].p = a[3][n+n-tr[j]+1];
				st[top].x = 4;
				st[top].y = n+n-tr[j]+1;
				a[3][n+n-tr[j]+1] = 0;
			}
		}
	}
}

int main()
{
	int i , j;
	cin >> n >> m;
	for (i = 1 ; i <= 4 ; i++)
	{
		for (j = 1 ; j <= n ; j++)
		{
			cin >> a[i][j];
			if (a[i][j] && (i == 1 || i == 4))
			{
				if (i == 1) tr[a[i][j]] = j;
				else tr[a[i][j]] = n+n-j+1;
			}
		}
	}
	for (i = 1 ; i <= m ; i++) check(i);
	for (i = 1 ; i <= 4 ; i++)
	{
		for (j = 1 ; j <= n ; j++)
		{
			if (!a[i][j] && (i == 2 || i == 3))
			{
				if (i == 2) sp = j;
				else sp = n+n-j+1;
			}
		}
	}
	if (!sp)
	{
		cout << "-1\n";
		return 0;
	}
	else
	{
		for (i = 1 ; i <= n*2 ; i++)
		{
			for (j = sp+1 ; j <= n*2 ; j++) move(j);
			for (j = 1 ; j <= sp-1 ; j++) move(j);
			sp--;
			if (!sp) sp = n*2;
			for (j = 1 ; j <= m ; j++) check(j);
		}
		
	}
	cout << top << "\n";
	for (i = 1 ; i <= top ; i++)
	{
		printf("%d %d %d\n",st[i].p,st[i].x,st[i].y);
	}
	return 0;
}