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

int n , a[100] , b[100]={31,28,31,30,31,30,31,31,30,31,30,31} , c;

int main ()
{
	int i , j;
	cin >> n;
	for (i = 0 ; i < n ; i++)
	{
		scanf("%d",&a[i]);
	}
	for (i = 12 ; i < 60 ; i++)
	{
		b[i] = b[i%12];
	}
	b[25] = 29;
	for (i = 0 ; i < 60-n+1 ; i++)
	{
		c = 0;
		for (j = 0 ; j < n ; j++)
		{
			if (a[j] != b[i+j])
			{
				c = 1;
				break;
			}
		}
		if (!c) break;
	}
	if (!c) cout << "Yes\n";
	else cout << "No\n";
	//system("PAUSE");
	return 0;
}