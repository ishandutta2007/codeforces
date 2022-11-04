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
	int a , b , i;
	cin >> a >> b;
	for (i = 1 ; i <= 10 ; i++)
		if ((a*i)%10 == b || (a*i)%10 == 0)
		{
			cout << i << "\n";
			return 0;
		}
	return 0;
}