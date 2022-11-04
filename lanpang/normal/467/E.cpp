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
const int maxn = 5e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , a[maxn] , m , b[maxn] , i;
int tr[maxn*4] , ne[maxn] , c[maxn] , la[maxn] , ma[maxn] , ans;
vector <int> v , p[maxn];

void putin(int num , int l , int r , int x , int y)
{
	if (l > x || r < x) return;
	if (l == r)
	{
		tr[num] = y;
		return;
	}
	putin(num*2,l,(l+r)/2,x,y);
	putin(num*2+1,(l+r)/2+1,r,x,y);
	tr[num] = max(tr[num*2],tr[num*2+1]);
}

int getout(int num , int l , int r , int x , int y)
{
	if (x > r || l > y) return 0;
	if (x <= l && r <= y) return tr[num];
	return max(getout(num*2,l,(l+r)/2,x,y),getout(num*2+1,(l+r)/2+1,r,x,y));
}

int main()
{
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		b[i] = a[i];
		c[i] = n+1;
	}
	sort(b+1,b+n+1);
	m = unique(b+1,b+n+1)-b-1;
	for (i = 1 ; i <= n ; i++)
		a[i] = lower_bound(b+1,b+m+1,a[i])-b;
	for (i = n ; i >= 1 ; i--)
	{
		ne[i] = c[a[i]];
		c[a[i]] = i;
	}
	for (i = 1 ; i <= n ; i++)
	{
		p[a[i]].push_back(i);
		if (p[a[i]].size() >= 4) 
			la[i] = max(la[i],p[a[i]][p[a[i]].size()-4]);
		if (ne[i] <= n) 
		{
			la[ne[i]] = max(la[ne[i]],getout(1,1,n,i+1,ne[i]-1));
			putin(1,1,n,ne[i],i);
		}
	}
	for (i = 1 ; i <= n ; i++)
	{
		ma[i] = ma[i-1];
		if (la[i]) 
		{
			ma[i] = max(ma[i],ma[la[i]-1]+1);
			if (ans < ma[i])
			{
				ans = ma[i];
				v.push_back(a[la[i]]);
				v.push_back(a[i]);
				v.push_back(a[la[i]]);
				v.push_back(a[i]);
			}
		}
	}
	cout << ans*4 << "\n";
	for (i = 0 ; i < v.size() ; i++)
		printf("%d ",b[v[i]]);
	cout << "\n";
	return 0;
}