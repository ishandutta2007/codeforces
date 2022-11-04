#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 2e5+10;
const LL mod = 1e9+7;

int n , m = 1000000000 , tp , rt;
struct gkd{
	int ls , rs , s;
}tr[maxn*30];
struct mmp{
	int x , y;
	bool operator < (const mmp &op) const{
		if (y == op.y) return x < op.x;
		else return y > op.y;
	}
}a[maxn];
LL ans;

void putin(int &num , int l , int r , int x)
{
	if (!num) num = ++tp;
	if (l == r)
	{
		tr[num].s = 1;
		return;
	}
	int mid = (l+r)/2;
	if (x <= mid) putin(tr[num].ls,l,mid,x);
	else putin(tr[num].rs,mid+1,r,x);
	tr[num].s = tr[tr[num].ls].s+tr[tr[num].rs].s;
}

LL getout(int num , int l , int r , int x , int y)
{
	if (!num || x > y || x > r || l > y) return 0;
	if (x <= l && r <= y) return tr[num].s;
	int mid = (l+r)/2;
	if (y <= mid) return getout(tr[num].ls,l,mid,x,y);
	else if (x >= mid+1) return getout(tr[num].rs,mid+1,r,x,y);
	else return getout(tr[num].ls,l,mid,x,y)+getout(tr[num].rs,mid+1,r,x,y);	
}

void jisuan(int x , int y)
{
	for (int i = x ; i <= y ; i++)
		putin(rt,1,m,a[i].x);
	LL t = getout(rt,1,m,1,m);
	ans += t*(t+1)/2;
	t = getout(rt,1,m,1,a[x].x-1);
	ans -= t*(t+1)/2;
	for (int i = x+1 ; i <= y ; i++)
	{
		t = getout(rt,1,m,a[i-1].x+1,a[i].x-1);
		ans -= t*(t+1)/2;
	}
	t = getout(rt,1,m,a[y].x+1,m);
	ans -= t*(t+1)/2;
}

int main()
{
	int i , j , la;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
		scanf("%d%d",&a[i].x,&a[i].y);
	sort(a+1,a+n+1);
	la = 1;
	for (i = 2 ; i <= n+1 ; i++)
	{
		if (i == n+1 || a[i].y != a[la].y)
		{
			jisuan(la,i-1);
			la = i;
		}
	}
	cout << ans << "\n";
	return 0;
}