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
#include <cassert>
#include <stack>
#include <bitset>
#include <sstream>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, a[ 111111 ], up[ 111111 ], down[ 111111 ];

int main (int argc, const char * argv[])
{
	scanf("%d", &n);
	for ( int i = 1; i <= n; i++ ) scanf("%d", &a[i]);
	up[0] = 0;
	up[1] = 1;
	for ( int i = 2; i <= n; i++ )
	{
		if ( a[i - 1] < a[i] ) up[i] = up[i - 1] + 1; else up[i] = 1;
	}
	down[n + 1] = 0;
	down[n] = 1;
	for ( int i = n - 1; i > 0; i-- )
	{
		if ( a[i + 1] > a[i] ) down[i] = down[i + 1] + 1; else down[i] = 1;
	}
	a[0] = -2e9;
	a[n + 1] = 2e9;
	int answer = 0;
	for ( int i = 1; i <= n; i++ )
	{
		answer = max( answer, up[i - 1] + 1 );
		answer = max( answer, down[i + 1] + 1 );
		if ( a[i - 1] + 1 < a[i + 1] ) answer = max( answer, up[i - 1] + 1 + down[i + 1] ); 
	} 
	cout << answer << "\n";
    return 0;
}