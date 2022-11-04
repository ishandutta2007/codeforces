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
const int maxn = 4e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

LL n , m , f[maxn] , x[maxn] , y[maxn] , a[maxn] , b[maxn] , len , ans , tr[maxn*4];
map <LL,LL> mp;

void putin(LL num , LL l , LL r , LL x , LL y)
{
	if (x > r || x < l) return;
	if (l == r)
	{
		tr[num] = y;
		return;
	}
	putin(num*2,l,(l+r)/2,x,y);
	putin(num*2+1,(l+r)/2+1,r,x,y);
	tr[num] = tr[num*2]+tr[num*2+1];
}

LL getout(LL num , LL l , LL r , LL x , LL y)
{
	if (x > r || l > y) return 0;
	if (x <= l && r <= y) return tr[num];
	return getout(num*2,l,(l+r)/2,x,y)+getout(num*2+1,(l+r)/2+1,r,x,y);
}

int main()
{
	LL i , j , k;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%I64d%I64d",&x[i],&y[i]);
		f[i*2-1] = x[i];
		f[i*2] = y[i];
	}
	sort(f+1,f+n*2+1);
	m = unique(f+1,f+2*n+1)-f-1;
	j = 0;
	for (i = 1 ; i <= m ; i++)
	{
		if (i > 1 && f[i] > k+1) 
		{
			j++;
			a[j] = f[i]-k-1;
			b[j] = j;
		}
		k = f[i];
		j++;
		a[j] = 1;
		b[j] = j;
		mp[f[i]] = j;
	}
	len = j;
	for (i = 1 ; i <= n ; i++)
	{
		swap(b[mp[x[i]]],b[mp[y[i]]]);
	}
	for (i = 1 ; i <= len ; i++)
	{
		ans += getout(1,1,len,b[i]+1,len)*a[i];
		putin(1,1,len,b[i],a[i]);
	}
	cout << ans << "\n";
	return 0;
}