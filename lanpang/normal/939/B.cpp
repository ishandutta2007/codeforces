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

LL k , n , x , ans , ma , p , g , i;

int main()
{
	cin >> k >> n;
	ma = -1;
	for (i = 1 ; i <= n ; i++)
	{
		scanf("%I64d",&x);
		ans = k-k%x;
		if (ans > ma)
		{
			ma = ans;
			p = i;
			g = k/x;
		}
	}
	cout << p << " " << g << "\n";
	return 0;
}