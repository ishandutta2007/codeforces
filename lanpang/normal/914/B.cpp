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

int n , a[maxn] , b , i , c;

int main ()
{
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&b);
		a[b]++;
	}
	for (i = 1 ; i <= 100000 ; i++)
	{
		if (a[i]%2)
		{
			c = 1;
			break;
		}
	}
	if (c) cout << "Conan\n";
	else cout << "Agasa\n";
	//system("PAUSE");
	return 0;
}