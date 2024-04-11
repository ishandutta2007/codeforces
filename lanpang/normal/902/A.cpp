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

int n , m , a , b , l , i;

int main ()
{
	cin >> n >> m;
	l = 0;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> a >> b;
		if (a <= l) 
		{
			l = max(l,b);
		}
	}
	if (l >= m) cout << "YES\n";
	else cout << "NO\n";
	//system("PAUSE");
	return 0;
}