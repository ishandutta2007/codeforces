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

int x , y , z , a , b , c;

int main()
{
	cin >> x >> y >> z;
	cin >> a >> b >> c;
	if (a >= x && a+b >= x+y && a+b+c >= x+y+z) cout << "YES\n";
	else cout << "NO\n";
	return 0;
}