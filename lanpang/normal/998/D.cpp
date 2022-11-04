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

LL n , i , j , k , l , s , cnt , ans[30];
map <LL,LL> p; 

int main()
{
	for (n = 1 ; n <= 20 ; n++)
	{
		p.clear();
		cnt = 0;
		for (i = 0 ; i <= n ; i++)
		{
			for (j = 0 ; i+j <= n ; j++)
			{
				for (k = 0 ; i+j+k <= n ; k++)
				{
					l = n-i-j-k;
					p[i+j*5+k*10+l*50] = 1;
				}
			}
		}
		for (auto it = p.begin() ; it != p.end() ; it++)
		{
			cnt++;
		}
		ans[n] = cnt;
	}
	cin >> n;
	if (n <= 20) cout << ans[n] << "\n";
	else cout << (LL)(n-20)*49+ans[20] << "\n";
	return 0;
}