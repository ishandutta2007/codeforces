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

char a[20];
int n , t , s , ans=10;

bool check(int x)
{
	if ((int)sqrt(x)*(int)sqrt(x) == x) return true;
	else return false;
}

int main()
{
	int i , j , k , p , g;
	cin >> a;
	n = strlen(a);
	t = pow(2,n);
	for (i = 1 ; i < t ; i++)
	{
		k = i;
		p = 0;
		s = 0;
		g = 0;
		for (j = 0 ; j < n ; j++)
		{
			if (k%2)
			{
				if (p == 0)
				{
					if (a[j] == '0') break;
					p = 1;
				}
				s *= 10;
				s += a[j]-'0';
				g++;
			}
			k /= 2;
		}
		if (p && check(s)) ans = min(ans,n-g);
	}
	if (ans == 10) cout << "-1\n";
	else cout << ans << "\n";
	return 0;
}