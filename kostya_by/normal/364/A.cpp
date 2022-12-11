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
#include <bitset>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int a, n, b[ 4040 ];
long long num[ 40000 ];
char st[ 4040 ];

int main (int argc, const char * argv[])
{
	scanf("%d\n", &a);
	gets( st ); n = strlen( st );
	for ( int i = 1; i <= n; i++ ) b[i] = (st[i - 1] - '0');
	for ( int i = 1; i <= n; i++ )
	{
		int sum = 0;
		for ( int j = i; j <= n; j++ )
		{
			sum += b[j];
			num[ sum ]++;
		}
	}
	if ( a == 0 )
	{
		long long s0 = 0, s1 = 0;
		for ( int i = 1; i < 40000; i++ ) s1 += num[i];
		s0 = s1 + num[0];
		long long ans = s0 * s0 - s1 * s1;
		cout << ans << "\n";
		return 0;
	}
	long long ans = 0;
	for ( int i = 1; i < 40000; i++ )
	{
		if ( a % i != 0 ) continue;
		if ( a / i >= 40000 ) continue;
		ans += num[i] * num[a / i];
	}
	cout << ans << "\n";
    return 0;
}