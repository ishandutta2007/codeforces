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

int m , n , k;

int main()
{
	cin >> n >> m;
	k = 1;
	while (k <= m && n--) k*=2;
	cout << m%k << "\n";
	return 0;
}