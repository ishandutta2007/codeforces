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
#include <cstdlib>
#include <ctime>
#include <stack>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

long long mx[1111111];
int n, m;
long long xx[555], yy[555], ans = 0;

long long abs1(long long val)
{
	if (val < 0) return -val; else return val;
}

int main (int argc, const char * argv[])
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) mx[i] = 1;
	for (int i = 0; i < m; i++) scanf("%I64d%I64d", &xx[i], &yy[i]);
	for (int i = 0; i < m; i++)
		for (int j = i + 1; j < m; j++)
		{
			int val = 0;
			long long a = yy[j] - yy[i];
			long long b = xx[i] - xx[j];
			long long c = a * xx[i] + b * yy[i];
			c = -c;
			if (a == 0) continue;
			if ( abs1(c) % abs1(a) != 0 ) continue;
			long long pp = -c / a;
			//cout << pp << endl;
			if (pp < 1 || pp > n) continue;
			for (int k = 0; k < m; k++) if ( a * xx[k] + b * yy[k] + c == 0 ) ++val;
			mx[ int(pp) ] = max( mx[ int(pp) ], 1ll * val );
		}
	for (int i = 1; i <= n; i++) ans += mx[i];
	cout << ans;
    return 0;
}