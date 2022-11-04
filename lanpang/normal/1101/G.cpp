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
const LL mod = 1e9+7;

int n , a[maxn] , b[30] , cnt;

void push(int x)
{
	for (int i = 29 ; i >= 0 ; i--)
	{
		if ((x>>i)&1)
		{
			if (b[i] == 0)
			{
				cnt++;
				b[i] = x;
				return;
			}
			x ^= b[i];
		}
	}
}

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		a[i] ^= a[i-1];
		push(a[i]);
	}
	if (a[n] == 0) cout << "-1\n";
	else cout << cnt << "\n";
	return 0;
}