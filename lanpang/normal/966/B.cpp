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
const int maxn = 3e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

struct mmp{
	int id , x;
}a[maxn];
int n , x , y;

bool cmp(mmp x , mmp y)
{
	return x.x < y.x;
}

int jisuan()
{
	int i , j , k , ii;
	for (i = 1 ; i <= n ; i++)
	{
		j = i+(x+a[i].x-1)/a[i].x;
		if (j > n) continue;
		k = j+(y+a[j].x-1)/a[j].x;
		if (k > n+1) continue;
		cout << "Yes\n" << j-i << " " << k-j << "\n";
		for (ii = i ; ii < j ; ii++)
		{
			printf("%d ",a[ii].id);
		}
		cout << "\n";
		for (ii = j ; ii < k ; ii++)
		{
			printf("%d ",a[ii].id);
		}
		cout << "\n";
		return 1;
	}
	swap(x,y);
	for (i = 1 ; i <= n ; i++)
	{
		j = i+(x+a[i].x-1)/a[i].x;
		if (j > n) continue;
		k = j+(y+a[j].x-1)/a[j].x;
		if (k > n+1) continue;
		cout << "Yes\n" << k-j << " " << j-i << "\n";
		for (ii = j ; ii < k ; ii++)
		{
			printf("%d ",a[ii].id);
		}
		cout << "\n";
		for (ii = i ; ii < j ; ii++)
		{
			printf("%d ",a[ii].id);
		}
		cout << "\n";
		return 1;
	}
	return -1;
}

int main()
{
	int i , aa;
	cin >> n >> x >> y;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i].x);
		a[i].id = i; 
	}
	sort(a+1,a+n+1,cmp);
	aa = jisuan();
	if (aa == -1) cout << "No\n";
	return 0;
}