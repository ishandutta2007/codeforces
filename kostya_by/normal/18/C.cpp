#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <stack>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int a, sum = 0, f[111111], n, res = 0;

int main (int argc, const char * argv[])
{
   // freopen("input.txt","r",stdin);
   // freopen("output.txt","w",stdout);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a);
		sum += a;
		f[i] = f[i - 1] + a;
	}
	for (int i = 1; i < n; i++)
	{
		int ss = f[i];
		if (sum == 2 * ss) ++res;
	}
	cout << res;
    return 0;
}