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

int n , a[26] , sum , i , ma , j;
char c;

int main()
{
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		cin >> c;
		if (c >= 'a' && c <= 'z') a[c-'a']++;
		else
		{
			sum = 0;
			for (j = 0 ; j < 26 ; j++) if (a[j] > 0) sum++;
			ma = max(ma,sum);
			for (j = 0 ; j < 26 ; j++) a[j] = 0;
		}
	}
	sum = 0;
	for (j = 0 ; j < 26 ; j++) if (a[j] > 0) sum++;
	ma = max(ma,sum);
	cout << ma << "\n";
	//system("PAUSE");
	return 0;
}