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
const int maxn = 1e6+10;
const int maxint = 0x3f3f3f3f;
const int mod = 1e9+7;

int n , m , top , p[maxn] , s , i;
char a[maxn] , b[maxn];

int main()
{
	cin >> n >> m;
	cin >> a+1;
	for (i = n ; i >= 1 ; i--)
	{
		p[i] = p[i+1];
		if (a[i] == ')') p[i]++;
	}
	for (i = 1 ; i <= n ; i++)
	{
		if (a[i] == '(' && s < m/2)
		{
			s++;
			b[++top] = '(';
		}
		if (a[i] == ')' && p[i] <= m/2)
		{
			b[++top] = ')';
		}
	}
	for (i = 1 ; i <= m ; i++)
	{
		printf("%c",b[i]);
	}
	cout << "\n";
	return 0;
}