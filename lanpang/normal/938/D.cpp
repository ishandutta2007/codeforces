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
	LL x , y;
	mmp(LL x=0 , LL y=0):x(x),y(y){}
	bool operator > (const mmp op) const{
		return y > op.y;
	}
}p;

LL n , m , ans[maxn] , f[maxn];
vector <LL> a[maxn] , b[maxn];
priority_queue < mmp,vector<mmp>,greater<mmp> > q;

int main()
{
	LL i , x , y , z;
	cin >> n >> m;
	for (i = 1 ; i <= m ; i++)
	{
		scanf("%I64d%I64d%I64d",&x,&y,&z);
		a[x].push_back(y);
		b[x].push_back(z*2);
		a[y].push_back(x);
		b[y].push_back(z*2);
	}
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%I64d",&ans[i]);
		p.x = i;
		p.y = ans[i];
		q.push(p);
	}
	while (!q.empty())
	{
		p = q.top();
		q.pop();
		x = p.x;
		y = p.y;
		if (f[x]) continue;
		f[x] = 1;
		ans[x] = y;
		for (i = 0 ; i < a[x].size() ; i++)
		{
			p.x = a[x][i];
			p.y = y+b[x][i];
			q.push(p);
		}
	}
	for (i = 1 ; i <= n ; i++)
	{
		printf("%I64d ",ans[i]);
	}
	cout << "\n";
	return 0;
}