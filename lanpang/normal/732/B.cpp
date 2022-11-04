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
const int maxn = 2e5+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int main()
{
	int n , k , a[510] , ans=0 , i;
	cin >> n >> k;
	for (i = 1 ; i <= n ; i++) cin >> a[i];
	for (i = 2 ; i <= n ; i++)
		if (a[i]+a[i-1] < k)
		{
			ans += k-a[i]-a[i-1];
			a[i] = k-a[i-1];
		}
	cout << ans << "\n";
	for (i = 1 ; i <= n ; i++) cout << a[i] << " ";
	cout << "\n";
	return 0;
}