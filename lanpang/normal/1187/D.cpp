#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 1e6+10;
const LL mod = 1e9+7;

int T , n , a[maxn] , b[maxn] , tr[maxn*4];
set<int> s[maxn];

void init(int num , int l , int r)
{
	tr[num] = 0;
	if (l == r) return;
	init(num*2,l,(l+r)/2);
	init(num*2+1,(l+r)/2+1,r);
}

void putin(int num , int l , int r , int x , int y)
{
	if (l == r)
	{
		tr[num] = y;
		return;
	}
	if (x <= (l+r)/2) putin(num*2,l,(l+r)/2,x,y);
	else putin(num*2+1,(l+r)/2+1,r,x,y);
	tr[num] = max(tr[num*2],tr[num*2+1]);
}

int getout(int num , int l , int r , int x)
{
	if (x < l) return 0;
	if (x >= r) return tr[num];
	if (x <= (l+r)/2) return getout(num*2,l,(l+r)/2,x);
	else return max(tr[num*2],getout(num*2+1,(l+r)/2+1,r,x));
}

int main()
{
	int i , j , t;
	cin >> T;
	while (T--)
	{
		scanf("%d",&n);
		init(1,1,n);
		for (i = 1 ; i <= n ; i++)
		{
			scanf("%d",&a[i]);
			s[i].clear();
		}
		for (i = 1 ; i <= n ; i++)
		{
			scanf("%d",&b[i]);
			s[b[i]].insert(i);
		}
		t = 0;
		for (i = 1 ; i <= n ; i++)
		{
			if (s[a[i]].empty())
			{
				t = 1;
				break;
			}
			j = *s[a[i]].begin();
			s[a[i]].erase(s[a[i]].begin());
			if (getout(1,1,n,a[i]-1) > j)
			{
				t = 1;
				break;
			}
			putin(1,1,n,a[i],j);
		}
		if (t) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}