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

int n , m , a[maxn] , len , b[maxn];
map <int,int> c[maxn];
set <int> q;
vector <int> p;

void solve(int y)
{
	q.erase(y);
	p.push_back(y);
	len++;
	b[len]++;
	int x = 0;
	while (x < p.size())
	{
		for (int i = *q.lower_bound(1) ; i <= n ; i = *q.lower_bound(i+1))
		{
			if (c[p[x]][i] == 0) 
			{
				q.erase(i);
				p.push_back(i);
				b[len]++;
			}
		}
		x++;
	}
	p.clear();
	return;
}

int main ()
{
	int i , j , x , y;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++) q.insert(i);
	q.insert(n+1);
	for (i = 1 ; i <= m ; i++)
	{
		scanf("%d%d",&x,&y);
		c[x][y] = 1;
		c[y][x] = 1;
	}
	for (int i = *q.lower_bound(1) ; i <= n ; i = *q.lower_bound(i+1))
	{
		solve(i);
	}
	sort(b+1,b+len+1);
	printf("%d\n",len);
	for (i = 1 ; i < len ; i++)
	{
		printf("%d ",b[i]);
	}
	printf("%d\n",b[len]);
	//system("PAUSE");
	return 0;
}