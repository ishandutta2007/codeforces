#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
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
const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , a[maxn] , m , b[maxn] , tr[maxn*4] , f1[maxn] , f2[maxn];
LL ans;

void cleartr(int num , int l , int r)
{
	tr[num] = 0;
	if (l == r) return;
	cleartr(num*2,l,(l+r)/2);
	cleartr(num*2+1,(l+r)/2+1,r);
}

void putin(int num , int l , int r,  int x , int y)
{
	if (x > r || x < l) return;
	if (l == r) 
	{
		tr[num] += y;
		return;
	}
	putin(num*2,l,(l+r)/2,x,y);
	putin(num*2+1,(l+r)/2+1,r,x,y);
	tr[num] = tr[num*2]+tr[num*2+1];
}

int getout(int num , int l , int r , int x , int y)
{
	if (x > r || l > y) return 0;
	if (x <= l && r <= y) return tr[num];
	return getout(num*2,l,(l+r)/2,x,y)+getout(num*2+1,(l+r)/2+1,r,x,y);
}

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		b[i] = a[i];
	}
	sort(b+1,b+n+1);
	m = unique(b+1,b+n+1)-b-1;
	for (i = 1 ; i <= n ; i++)
	{
		a[i] = lower_bound(b+1,b+m+1,a[i])-b;
		f1[i] = getout(1,1,m,a[i],a[i])+1;
		putin(1,1,m,a[i],1);
	}
	for (i = n ; i >= 1 ; i--)
		f2[i] = getout(1,1,m,a[i],a[i])+1-f1[i];
	cleartr(1,1,n);
	for (i = 1 ; i <= n ; i++)
		putin(1,1,n,f2[i],1);
	for (i = 1 ; i <= n ; i++)
	{
		putin(1,1,n,f2[i],-1);
		ans += getout(1,1,n,1,f1[i]-1);
	}
	cout << ans << "\n";
	return 0;
}