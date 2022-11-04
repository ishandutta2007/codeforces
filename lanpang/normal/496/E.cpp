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
const int maxn = 1e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

struct mmp{
	int id , ty , x , y;
	bool operator < (const mmp op) const{
		return y < op.y;
	}
}a[maxn*2];
int n , m , b[maxn] , f[maxn];
multiset <mmp> q;
multiset <mmp>::iterator iter; 

bool cmp(mmp x , mmp y)
{
	if (x.x == y.x) return x.ty > y.ty;
	else return x.x <= y.x;
}

int main()
{
	int i , j=0;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		a[i].ty = 1;
		a[i].id = i;
	}
	cin >> m;
	for (i = n+1 ; i <= n+m ; i++)
	{
		scanf("%d%d%d",&a[i].x,&a[i].y,&b[i-n]);
		a[i].ty = 2;
		a[i].id = i-n;
	}
	sort(a+1,a+n+m+1,cmp);
	for (i = 1 ; i <= n+m ; i++)
	{
		if (a[i].ty == 1)
		{
			iter = q.lower_bound(a[i]);
			if (iter == q.end())
			{
				j = 1;
				break;
			}
			f[a[i].id] = (*iter).id;
			b[(*iter).id]--;
			if (b[(*iter).id] == 0) q.erase(iter);
		}
		else q.insert(a[i]);
	}
	if (j) cout << "NO\n";
	else
	{
		cout << "YES\n";
		for (i = 1 ; i < n ; i++) printf("%d ",f[i]);
		cout << f[n] << "\n";
	}
	return 0;
}