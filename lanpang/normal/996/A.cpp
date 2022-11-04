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

int n , ans;

int main()
{
	cin >> n;
	ans += n/100;
	n %= 100;
	ans += n/20;
	n %= 20;
	ans += n/10;
	n %= 10;
	ans += n/5;
	n %= 5;
	ans += n;
	cout << ans << "\n";
	return 0;
}