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

int n , a[maxn] , m , b[maxn] , l , mm;

int main ()
{
	int i;
	cin >> n;
	m = mod;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		m = min(m,a[i]);
	}	
	mm = n;
	for (i = 1 ; i <= n ; i++)
	{
		if (a[i] == m)
		{
			l++;
			b[l] = i;
			if (l >= 2)
			{
				mm = min(mm,b[l]-b[l-1]);
			}
		}
	}
	cout << mm << "\n";
	//system("PAUSE");
	return 0;
}