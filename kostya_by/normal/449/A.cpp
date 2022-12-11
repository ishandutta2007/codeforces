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

int n, m, k;

long long fun( int t )
{
	int xx = t + 1;
	int yy = k - t + 1;
	long long dx = n / xx;
	long long dy = m / yy;
	return dx * dy;
}

int main (int argc, const char * argv[])
{
	cin >> n >> m >> k;
	int left_bound = max( 0, k - m + 1 );
	int right_bound = min( n - 1, k );
	long long answer = -1;
	for ( int t = left_bound;  t <= min( right_bound, left_bound +1 ); t++ ) answer = max( answer, fun( t ) );
	for ( int t = max( left_bound, right_bound - 1 ); t <= right_bound; t++ ) answer = max( answer, fun( t ) );
	cout << answer << "\n";
    return 0;
}