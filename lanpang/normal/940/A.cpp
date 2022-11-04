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
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , m , a[110] , mi , ans;

int jisuan(int x , int y)
{
	int i , ret=0;
	for (i = 1 ; i <= n ; i++)
	{
		if (a[i] < x || a[i] > y) ret++;
	}
	return ret;
}

int main()
{
	int i;
	cin >> n >> m;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> a[i];
	}
	mi = n;
	for (i = 1 ; i <= 100 ; i++)
	{
		ans = jisuan(i,i+m);
		mi = min(mi,ans);
	}
	cout << mi << "\n";
	return 0;
}