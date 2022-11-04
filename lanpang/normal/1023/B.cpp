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

LL n , k , c;

int main()
{
	cin >> n >> k;
	if (k <= 2)
	{
		cout << "0\n";
		return 0; 
	}
	c = (k-1)/2;
	if (n < k-1) c += n-k+1;
	if (c >= 0) cout << c << "\n";
	else cout << "0\n";
	return 0;
}