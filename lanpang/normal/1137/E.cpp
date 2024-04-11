#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

struct mmp{
	LL i , h;
}st[maxn];
int tp , m , t;
LL n , k , b , nn , kk , bb;

bool cmp(mmp x , mmp y , mmp z)
{
	return (long double)(x.h-y.h)/(x.i-y.i) <= (long double)(x.h-z.h)/(x.i-z.i);
}

LL chk(mmp x)
{
	return k*x.i+x.h+b;
}

int main()
{
	cin >> n >> m;
	st[++tp] = {0,0};
	while (m--)
	{
		scanf("%d",&t);
		if (t == 1)
		{
			scanf("%I64d",&nn);
			tp = k = b = 0;
			st[++tp] = {0,0};
			n += nn;
		}
		else if (t == 2)
		{
			scanf("%I64d",&nn);
			st[++tp] = {n,-k*n-b};
			n += nn;
			while (tp >= 3 && cmp(st[tp],st[tp-1],st[tp-2]))
			{
				swap(st[tp],st[tp-1]);
				tp--;
			}
		}
		else
		{
			scanf("%I64d%I64d",&bb,&kk);
			k += kk;
			b += bb;
		}
		while (tp >= 2 && chk(st[tp]) >= chk(st[tp-1])) tp--;
		printf("%I64d %I64d\n",st[tp].i+1,chk(st[tp]));
	}
	return 0;
}