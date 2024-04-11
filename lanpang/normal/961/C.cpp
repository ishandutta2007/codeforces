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

int n , b[5][2] , mi , ans;
char a;

int main()
{
	int i , j , k;
	cin >> n;
	for (k = 1 ; k <= 4 ; k++)
	{
		if (k > 1) a = getchar();
		for (i = 1 ; i <= n ; i++)
		{
			a = getchar();
			for (j = 1 ; j <= n ; j++)
			{
				a = getchar();
				if ((i+j)%2 == 0) b[k][(a-'0')^1]++;
				else b[k][(a-'0')]++;
			}
		}
	}
	mi = n*n*4;
	for (i = 1 ; i <= 3 ; i++)
	{
		for (j = i+1 ; j <= 4 ; j++)
		{
			ans = b[i][0]+b[j][0];
			for (k = 1 ; k <= 4 ; k++)
			{
				if (k!=i && k!=j) ans += b[k][1];
			}
			mi = min(mi,ans);
		}
	}
	cout << mi << "\n";
	return 0;
}