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

int main()
{
	int a , b , c , d , n;
	cin >> a >> b >> c >> n;
	if (c > a || c > b) cout << "-1\n";
	else
	{
		d = a+b-c;
		d = n-d;
		if (1 <= d && d <= n) cout << d << "\n";
		else cout << "-1\n";
	}
	return 0;
}