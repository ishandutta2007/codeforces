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

int n , i , t , s; 

int main()
{
	cin >> n;
	i = 1;
	while (1)
	{
		t++;
		s += i;
		if (s >= n)
		{
			cout << t << "\n";
			return 0;
		}
		i *= 2;
	}
	return 0;
}