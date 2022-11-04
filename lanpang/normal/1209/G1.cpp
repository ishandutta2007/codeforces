#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , m , a[maxn] , ma , r , s , ans;
struct mmp{
	int x , y , s;
	bool operator < (const mmp &op) const{
		return x < op.x;
	}
}f[maxn];

int main()
{
	int i , j;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		if (!f[a[i]].x) f[a[i]].x = i;
		f[a[i]].y = i;
		f[a[i]].s++;
	}
	sort(f+1,f+200000+1);
	for (i = 1 ; i <= 200000 ; i++)
	{
		if (!f[i].x) continue;
		if (r && f[i].x <= r)
		{
			r = max(r,f[i].y);
			s += f[i].s;
			ma = max(ma,f[i].s);
		}
		else if (r && f[i].x > r)
		{
			ans += s-ma;
			r = f[i].y;
			s = f[i].s;
			ma = f[i].s;
		}
		else if (!r)
		{
			r = f[i].y;
			s = f[i].s;
			ma = f[i].s;
		}
	}
	if (r) ans += s-ma;
	cout << ans << "\n";
	return 0;
}