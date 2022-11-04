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

int n , ans , i , u , r;
char a[maxn]; 

int main()
{
	cin >> n;
	scanf("%s",a);
	for (i = 0 ; i < n ; i++)
	{
		if (a[i] == 'U') u++;
		else r++;
		if (i < n-1 && u == r && a[i] == a[i+1]) ans++;
	}
	cout << ans << "\n";
	return 0;
}