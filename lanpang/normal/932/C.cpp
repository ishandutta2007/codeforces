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

int n , a , b , x , y;

int main()
{
	int i , j , t=0;
	cin >> n >> a >> b;
	for (i = 0 ; i <= n/a ; i++)
	{
		j = n-i*a;
		if (j%b == 0)
		{
			for (x = 1 ; x <= i*a ; x += a)
			{
				for (y = 0 ; y < a ; y++)
				{
					if (y == 0) printf("%d ",x+a-1);
					else printf("%d ",x+y-1);
				}
			}
			for (x = i*a+1 ; x <= i*a+j ; x += b)
			{
				for (y = 0 ; y < b ; y++)
				{
					if (y == 0) printf("%d ",x+b-1);
					else printf("%d ",x+y-1);
				}
			}
			cout << "\n";
			t = 1;
			break;
		}
	}
	if (t==0) cout << "-1\n";
	return 0;
}