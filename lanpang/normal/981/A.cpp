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

int n , ma , t , i , j , k;
char a[100];

int main()
{
	cin >> a;
	n = strlen(a);
	for (i = 0 ; i < n ; i++)
	{
		for (j = i ; j < n ; j++)
		{
			t = 0;
			for (k = i ; k <= j ; k++)
			{
				if (a[k] != a[j-k+i])
				{
					t = 1;
					break;
				}
			}
			if (t) ma = max(ma,j-i+1);
		}
	}
	cout << ma << "\n"; 
	return 0;
}