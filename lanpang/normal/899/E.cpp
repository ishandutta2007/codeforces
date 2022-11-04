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

struct mmp{
	int x , n , l , r;
}a[maxn];

priority_queue<II> q;
int n , len , g[maxn] , s , ans;

int main()  
{  
	int i , j , x , y;
	II tt;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&x);
		if (i == 1 || a[len].x != x)
		{
			len++;
			a[len].x = x;
			a[len].n = 1;
			a[len].l = len-1;
			a[len].r = len+1;
		}
		else a[len].n++;
	}
	for (i = 1 ; i <= len ; i++)
	{
		tt.first = a[i].n;
		tt.second = len-i+1;
		q.push(tt);
	}
	while (s < n)
	{
		while (1)
		{
			tt = q.top();
			x = len-tt.second+1;
			if (g[x] == 0) 
			{
				g[x] = 1;
				break;
			}
			q.pop();
		}
		ans++;
		s += tt.first;
		if (a[x].l >= 1 && a[x].r <= len && a[a[x].l].x == a[a[x].r].x)
		{
			a[a[x].l].r = a[a[x].r].r;
			a[a[a[x].r].r].l = a[x].l;
			a[a[x].l].n += a[a[x].r].n;
			g[a[x].r] = 1;
			tt.first = a[a[x].l].n;
			tt.second = len-a[x].l+1;
			q.push(tt);
		}
		else
		{
			a[a[x].l].r = a[x].r;
			a[a[x].r].l = a[x].l;
		}
	} 
	cout << ans << "\n";
	//system("PAUSE");
	return 0;
}