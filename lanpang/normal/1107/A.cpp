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

int q , n;
char a[maxn];

int main()
{
	int i , j;
	cin >> q;
	for (i = 1 ; i <= q ; i++)
	{
		cin >> n;
		cin >> a+1;
		if (n == 2 && a[1] >= a[2]) cout << "NO\n";
		else
		{
			cout << "YES\n";
			cout << "2\n";
			cout << a[1] << " " << a+2 << "\n";
		}
	}
	return 0;
}