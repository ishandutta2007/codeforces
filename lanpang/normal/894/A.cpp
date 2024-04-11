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

char a[1000];
int s , i , j , k , n;

int main ()
{
	cin >> a;
	n = strlen(a);
	for (i = 1 ; i <= n-2 ; i++)
	{
		for (j = i+1 ; j <= n-1 ; j++)
		{
			for (k = j+1 ; k <= n ; k++)
			{
				if (a[i-1] == 'Q' && a[j-1] == 'A' && a[k-1] == 'Q') s++;
			}
		}
	}
	cout << s << "\n";
	//system("PAUSE");
	return 0;
}