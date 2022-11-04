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

int n , i;
LL s , a , b[maxn];

int main ()
{
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a);
		s += a;
	}
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&b[i]);
	}
	sort(b+1,b+n+1);
	if (b[n]+b[n-1] >= s) cout << "YES\n";
	else cout << "NO\n";
	//system("PAUSE");
	return 0;
}