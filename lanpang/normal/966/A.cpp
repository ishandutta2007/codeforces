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
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , m , la , a[maxn] , lb , b[maxn] , v;

int main()
{
	int i , j , q , x , y , xx , yy , aa , bb , aaa , bbb , t , tt , ans1 , ans2 , ans3 , ans4 , ans5;
	cin >> n >> m >> la >> lb >> v;
	for (i = 1 ; i <= la ; i++)
	{
		scanf("%d",&a[i]); 
	}
	for (i = 1 ; i <= lb ; i++)
	{
		scanf("%d",&b[i]); 
	}
	cin >> q;
	for (i = 1 ; i <= q ; i++)
	{
		scanf("%d%d%d%d",&x,&y,&xx,&yy);
		//
		t = lower_bound(a+1,a+la+1,y)-a-1;
		if (1 <= t && t <= la) t = a[t];
		else t = mod;
		tt = lower_bound(a+1,a+la+1,y)-a;
		if (1 <= tt && tt <= la) tt = a[tt];
		else tt = mod;
		if (fabs(tt-y)+fabs(tt-yy)>fabs(t-y)+fabs(t-yy)) aa = t;
		else aa = tt;
		//
		t = lower_bound(a+1,a+la+1,yy)-a-1;
		if (1 <= t && t <= la) t = a[t];
		else t = mod;
		tt = lower_bound(a+1,a+la+1,yy)-a;
		if (1 <= tt && tt <= la) tt = a[tt];
		else tt = mod;
		if (fabs(tt-y)+fabs(tt-yy)>fabs(t-y)+fabs(t-yy)) aaa = t;
		else aaa = tt;
		//
		t = lower_bound(b+1,b+lb+1,y)-b-1;
		if (1 <= t && t <= lb) t = b[t];
		else t = mod;
		tt = lower_bound(b+1,b+lb+1,y)-b;
		if (1 <= tt && tt <= lb) tt = b[tt];
		else tt = mod;
		if (fabs(tt-y)+fabs(tt-yy)>fabs(t-y)+fabs(t-yy)) bb = t;
		else bb = tt;
		//
		t = lower_bound(b+1,b+lb+1,yy)-b-1;
		if (1 <= t && t <= lb) t = b[t];
		else t = mod;
		tt = lower_bound(b+1,b+lb+1,yy)-b;
		if (1 <= tt && tt <= lb) tt = b[tt];
		else tt = mod;
		if (fabs(tt-y)+fabs(tt-yy)>fabs(t-y)+fabs(t-yy)) bbb = t;
		else bbb = tt;
		//
		//cout << aa << " " << aaa << " " << bb << " " << bbb << "\n";
		ans1 = fabs(x-xx)+fabs(aa-y)+fabs(aa-yy);
		ans2 = fabs(x-xx)+fabs(aaa-y)+fabs(aaa-yy);
		ans3 = (fabs(x-xx)+v-1)/v+fabs(bb-y)+fabs(bb-yy);
		ans4 = (fabs(x-xx)+v-1)/v+fabs(bbb-y)+fabs(bbb-yy);
		if (x == xx) ans5 = fabs(y-yy);
		else ans5 = mod;
		//cout << ans1 << " " << ans2 << " " << ans3 << " " << ans4 << " " << ans5 << "\n";
		printf("%d\n",min(ans1,min(ans2,min(ans3,min(ans4,ans5)))));
	}
	return 0;
}
/*
5 6 1 1 3
2
5
4
5 6 1 1
5 4 1 3
5 3 3 3
1 6 1 1
*/