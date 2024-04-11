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

int n;
LL ans , a[maxn];

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
		cin >> a[i];
	sort(a+1,a+n+1);
	for (i = 1 ; i <= n/2 ; i++)
		ans += (a[i]+a[n-i+1])*(a[i]+a[n-i+1]);
	cout << ans << "\n";
	return 0;
}