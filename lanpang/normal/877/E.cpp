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

int n , b[maxn][2] , cnt , m;
int tr[maxn*4] , la[maxn*4];
vector<int> a[maxn];
char c;

void dfs(int x)
{
	cnt++;
	b[x][0] = cnt;
	for (int i = 0 ; i < a[x].size() ; i++)
	{
		dfs(a[x][i]);
	}
	b[x][1] = cnt;
}

void pushdown(int num , int l , int r)
{
	la[num] = 0;
	la[num*2] ^= 1;
	la[num*2+1] ^= 1;
	tr[num*2] = (l+r)/2-l+1-tr[num*2];
	tr[num*2+1] = r-(l+r)/2-tr[num*2+1];
}

void putin(int num , int l , int r , int x , int y)
{
	if (x < l || x > r) return;
	if (l == r) tr[num] = y;
	else
	{
		putin(num*2,l,(l+r)/2,x,y);
		putin(num*2+1,(l+r)/2+1,r,x,y);
		tr[num] = tr[num*2]+tr[num*2+1];
	}
}

void pushin(int num , int l , int r , int x , int y)
{
	if (l > y || x > r) return;
	if (la[num] && r > l) pushdown(num,l,r);
	if (x <= l && r <= y)
	{
		la[num] ^= 1;
		tr[num] = (r-l+1) - tr[num];
	}	
	else
	{
		pushin(num*2,l,(l+r)/2,x,y);
		pushin(num*2+1,(l+r)/2+1,r,x,y);
		tr[num] = tr[num*2]+tr[num*2+1];
	}
}

int getout(int num , int l , int r , int x , int y)
{
	if (l > y || x > r) return 0;
	if (la[num] && r > l) pushdown(num,l,r);
	if (x <= l && r <= y) return tr[num];
	else return getout(num*2,l,(l+r)/2,x,y)+getout(num*2+1,(l+r)/2+1,r,x,y);
}

int main ()
{
	int i , j , x , y;
	cin >> n;
	for (i = 2 ; i <= n ; i++)
	{
		scanf("%d",&x);
		a[x].push_back(i);
	}
	dfs(1);
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&x);
		putin(1,1,n,b[i][0],x);
	}
	cin >> m;
	for (i = 1 ; i <= m ; i++)
	{
		for (j = 1 ; j <= 4 ; j++)
		{
			c = getchar();
		}
		scanf("%d",&x);
		if (c == 'w') pushin(1,1,n,b[x][0],b[x][1]);
		else printf("%d\n",getout(1,1,n,b[x][0],b[x][1]));
	}
	//system("PAUSE");
	return 0;
}