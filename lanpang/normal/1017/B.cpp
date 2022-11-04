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

int n , i;
LL a , b , c , d;
char x[maxn] , y[maxn];

int main()
{
	cin >> n;
	cin >> x+1;
	cin >> y+1;
	for (i = 1 ; i <= n ; i++)
	{
		if (x[i] == '0')
		{
			if (y[i] == '0') a++;
			else c++;
		}
		else
		{
			if (y[i] == '0') b++;
			else d++;
		}
	}
	cout << a*b+a*d+b*c << "\n";
	return 0;
}