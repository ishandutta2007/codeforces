#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <queue>
#include <set>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;
typedef pair <int,int> II;
const int maxn = 100;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

struct mmp{
	int x , y;
}a[100];

int n , f[100];

bool cmp(mmp x , mmp y)
{
	return x.x < y.x;
}

int main ()
{
	int i;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i].x);
		a[i].y = i;
	}
	sort(a+1,a+n+1,cmp);
	for (i = 1 ; i <= n ; i++)
	{
		f[a[i].y] = i;
	}
	for (i = 1 ; i <= n ; i++)
	{
		if (f[i] == n) cout << a[1].x << " ";
		else cout << a[f[i]+1].x << " ";
	}
	cout << "\n";
	//system("PAUSE");
	return 0;
}