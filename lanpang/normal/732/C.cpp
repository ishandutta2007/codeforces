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

LL a , b , c , d;

int main()
{
	cin >> a >> b >> c;
	d = max(a,max(b,c));
	if (a == d) a--;
	if (b == d) b--;
	if (c == d) c--;
	d--;
	cout << d-a+d-b+d-c << "\n";
	return 0;
}