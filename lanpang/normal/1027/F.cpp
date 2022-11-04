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
const int maxn = 2e6+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

struct mmp{
	int x , y;
}a[maxn];
int n , m , b[maxn] , f[maxn] , i , t , s[maxn] , ans;
vector <int> v[maxn];

int getf(int x)
{
	if (x != f[x]) f[x] = getf(f[x]);
	return f[x];
}

int main()
{
	cin >> n;
	ans = t = 0;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d%d",&a[i].x,&a[i].y);
		b[i*2-1] = a[i].x;
		b[i*2] = a[i].y;
	}
	sort(b+1,b+n*2+1);
	m = unique(b+1,b+n*2+1)-b-1;
	for (i = 1 ; i <= m ; i++) f[i] = i;
	for (i = 1 ; i <= n ; i++)
	{
		a[i].x = lower_bound(b+1,b+m+1,a[i].x)-b;
		a[i].y = lower_bound(b+1,b+m+1,a[i].y)-b;
		int fx = getf(a[i].x) , fy = getf(a[i].y);
		if (fx != fy) f[fx] = fy;
	}
	for (i = 1 ; i <= m ; i++)
	{
		f[i] = getf(f[i]);
		v[f[i]].push_back(i);
	}
	for (i = 1 ; i <= n ; i++)
		s[f[a[i].x]]++;
	for (i = 1 ; i <= m ; i++)
	{
		if (f[i] == i && s[i] > 0)
		{
			if (s[i] > v[i].size())
			{
				t = 1;
				break;
			}
			sort(v[i].begin(),v[i].end());
			if (s[i] == v[i].size()) ans = max(ans,v[i][v[i].size()-1]);
			if (s[i] < v[i].size()) ans = max(ans,v[i][v[i].size()-2]);
		}
	}
	if (t) cout << "-1\n";
	else cout << b[ans] << "\n";
	return 0;
}