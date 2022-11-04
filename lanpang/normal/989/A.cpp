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

int n , a[10] , i , j;
char s[110];

int main()
{
	cin >> s;
	n = strlen(s);
	for (i = 2 ; i < n ; i++)
	{
		a[0] = a[1] = a[2] = 0;
		for (j = i-2 ; j <= i ; j++)
		{
			if ('A' <= s[j] && s[j] <= 'C')
			{
				a[s[j]-'A'] = 1;
			}
		}
		if (a[0]*a[1]*a[2])
		{
			cout << "Yes\n";
			return 0;
		}
	}
	cout << "No\n";
	return 0;
}