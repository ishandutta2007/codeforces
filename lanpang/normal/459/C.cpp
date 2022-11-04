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
const int mod = 1e9+7;

int n , k , d , kk , dd , a[1010];

int main()
{
	int i , j;
	cin >> n >> k >> d;
	kk = 1;
	dd = d;
	while (kk < n && dd--)
		kk *= k;
	if (kk < n)
	{
		cout << "-1\n";
		return 0;
	}
	for (i = 1 ; i <= n ; i++)
		a[i] = i;
	for (i = 1 ; i <= d ; i++)
	{
		for (j = 1 ; j <= n ; j++)
		{
			printf("%d ",a[j]%k+1);
			a[j] /= k;
		}
		printf("\n");
	}
	return 0;
}