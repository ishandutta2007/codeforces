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
const int maxn = 1e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

struct mmp{
    int x, y;
    mmp(int x = 0, int y = 0):x(x),y(y){}
    bool operator < (const mmp asd) const{
        if (1LL * x * y != 1LL * asd.x *asd.y) return 1LL * x * y < 1LL * asd.x *asd.y;
        else 
		{
            if (y != asd.y)return y <asd.y;
            else return x < asd.x;
        }
    }
}t , t1 , t2;

map <mmp,bool> mp;
priority_queue <mmp> p;
int n , m , r , k , fa[maxn] , fb[maxn] , a[maxn] , b[maxn];
LL ans;

int main ()
{
	int i , j;
	cin >> n >> m >> r >> k;
	for (i = 1 ; i <= n ; i++)
	{
		a[i] = a[i-1];
		if (i+r-1 <= n) a[i]++;
		if (i-r >= 1) a[i]--;
		fa[a[i]]++;
	}
	for (i = 1 ; i <= m ; i++)
	{
		b[i] = b[i-1];
		if (i+r-1 <= m) b[i]++;
		if (i-r >= 1) b[i]--;
		fb[b[i]]++;
	}
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	t.x = a[n];
	t.y = b[m];
	p.push(t);
	mp[t] = 1;
	while (k >= 1)
	{
		t = p.top();
		p.pop();
		ans += min((LL)k,(LL)fa[t.x]*fb[t.y])*(LL)t.x*(LL)t.y;
		k -= min((LL)k,(LL)fa[t.x]*fb[t.y]);
		t1 = t;
		t1.x--;
		t2 = t;
		t2.y--;
		if (t.x > 1 && mp[t1] == 0)
		{
			mp[t1] = 1;
			p.push(t1);
		}
		if (t.y > 1 && mp[t2] == 0)
		{
			mp[t2] = 1;
			p.push(t2);
		}
	}
	double ret = (double)ans/(double)((LL)(n-r+1)*(LL)(m-r+1));
	printf("%.10lf\n",ret);
	//system("PAUSE");
	return 0;
}