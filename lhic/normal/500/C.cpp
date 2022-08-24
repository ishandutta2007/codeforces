#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <bitset>


using namespace std;

typedef long long ll;
typedef long double ld;


const int MAXN = 1200;
int w[MAXN];
int was[MAXN];
int a[MAXN];

int ans;
int n, m;

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> w[i];
	for (int i = 0; i < m; ++i)
	{
		cin >> a[i];
		memset(was, 0, sizeof(was[0]) * (n + 1));
		for (int j = i - 1; j >= 0; --j)
		{
			if (a[j] == a[i])
				break;
			if (!was[a[j]])
			{
				was[a[j]] = 1;
				ans += w[a[j]];
			}
		}
	}
	cout << ans;
	return 0;
}