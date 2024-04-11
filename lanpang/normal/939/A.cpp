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

int n , a[5010] , t;

int main()
{
	int i , j , k , x;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&x);
		a[i] = x;
	}
	for (i = 1 ; i <= n ; i++)
	{
		j = a[i];
		k = a[j];
		if (a[k] == i && i != j && j != k && i != k)
		{
			t = 1;
			break;
		}
	}
	if (t) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}