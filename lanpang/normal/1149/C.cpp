#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int n , q , s[maxn];
char a[maxn];
struct mmp{
	int ma , mi , ml , mr , bf , ans;
	mmp(int x = 0)
	{
		ma = x;
		mi = x;
		ml = -x;
		mr = -x;
		bf = 0;
		ans = 0;
	}
	void buff(int x)
	{
		ma += x;
		mi += x;
		ml -= x;
		mr -= x;
		bf += x;
	}
}tr[maxn];

mmp merge(mmp x , mmp y)
{
	mmp z(0);
	z.mi = min(x.mi,y.mi);
	z.ma = max(x.ma,y.ma);
	z.ml = max(max(x.ml,y.ml),y.ma-x.mi*2);
	z.mr = max(max(y.mr,x.mr),x.ma-y.mi*2);
	z.ans = max(max(x.ans,y.ans),max(x.ma+y.ml,y.ma+x.mr));
	return z;
}

void build(int num , int l , int r)
{
	if (l == r) tr[num] = mmp(s[l]);
	else
	{
		build(num*2,l,(l+r)/2);
		build(num*2+1,(l+r)/2+1,r);
		tr[num] = merge(tr[num*2],tr[num*2+1]);
	}
}

void putin(int num , int l , int r , int x , int y , int z)
{
	if (x <= l && r <= y) tr[num].buff(z);
	else
	{
		tr[num*2].buff(tr[num].bf);
		tr[num*2+1].buff(tr[num].bf);
		tr[num].buff(-tr[num].bf);
		if (y <= (l+r)/2) putin(num*2,l,(l+r)/2,x,y,z);
		else
		{
			if (x >= (l+r)/2+1) putin(num*2+1,(l+r)/2+1,r,x,y,z);
			else
			{
				putin(num*2,l,(l+r)/2,x,y,z);
				putin(num*2+1,(l+r)/2+1,r,x,y,z);
			}
		}
		tr[num] = merge(tr[num*2],tr[num*2+1]);
	}
}

int main()
{
	int i , j , x , y;
	cin >> n >> q;
	scanf("%s",a+1);
	n = (n-1)*2;
	for (i = 1 ; i <= n ; i++)
	{
		s[i] = s[i-1];
		if (a[i] == '(') s[i]++;
		else s[i]--;
	}
	build(1,1,n);
	cout << tr[1].ans << "\n";
	for (i = 1 ; i <= q ; i++)
	{
		cin >> x >> y;
		if (x != y)
		{
			if (x > y) swap(x,y);
			swap(a[x],a[y]);
			putin(1,1,n,x,y-1,(a[x]-a[y])*-2);
		}
		printf("%d\n",tr[1].ans);
	}
	return 0;
}