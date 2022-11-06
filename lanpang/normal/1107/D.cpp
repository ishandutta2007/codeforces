#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
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
const int maxn = 1e6+10;
const int inf = 0x3f3f3f3f;
const LL mod = 1e9+7;

int n , x , gcd , p;
bool b[5210][5210];
char a[1310];

int main()
{
	int i , j;
	cin >> n;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%s",a+1);
		for (j = 1 ; j <= n/4 ; j++)
		{
			if ('0' <= a[j] && a[j] <= '9') x = a[j]-'0';
			else x = a[j]-'A'+10;
			b[i][(j-1)*4+1] = (x&8);
			b[i][(j-1)*4+2] = (x&4);
			b[i][(j-1)*4+3] = (x&2);
			b[i][(j-1)*4+4] = (x&1);
		}
	}
	gcd = -1;
	for (i = 1 ; i <= n ; i++)
	{
		p = 1;
		for (j = 2 ; j <= n ; j++)
		{
			if (b[i][j] != b[i][j-1])
			{
				if (gcd == -1) gcd = p;
				else gcd = __gcd(gcd,p);
				p = 0;
			}
			p++;
		}
		if (gcd == -1) gcd = p;
		else gcd = __gcd(gcd,p);
		p = 1;
		for (j = 2 ; j <= n ; j++)
		{
			if (b[j][i] != b[j-1][i])
			{
				if (gcd == -1) gcd = p;
				else gcd = __gcd(gcd,p);
				p = 0;
			}
			p++;
		}
		if (gcd == -1) gcd = p;
		else gcd = __gcd(gcd,p);
	}
	cout << gcd << "\n";
	return 0;
}