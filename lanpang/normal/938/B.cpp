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
const int maxn = 1e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , a[maxn] , mi , i , x = 1e6;

int main()
{
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
	}
	mi = min(a[n]-1,x-a[1]);
	for (i = 1 ; i < n ; i++)
	{
		mi = min(mi,max(a[i]-1,x-a[i+1]));
	}
	cout << mi << "\n";
	return 0;
}