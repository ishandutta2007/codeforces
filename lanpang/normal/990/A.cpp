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

LL n , m , k , l , a , b;

int main()
{
	cin >> n >> m >> a >> b;
	k = n%m;
	l = m-k;
	cout << min(l*a,k*b) << "\n";
	return 0;
}