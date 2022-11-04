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

int b , k , a[maxn] , ans , t;

int main()
{
	int i , j;
	cin >> b >> k;
	for (i = 1 ; i <= k ; i++)
		scanf("%d",&a[i]);
	t = 1;
	for (i = k ; i >= 1 ; i--)
	{
		ans = (ans+a[i]*t)%2;
		t = (t*(b%2))%2;
	}
	if (ans == 0) cout << "even\n";
	else cout << "odd\n";
	return 0;
}