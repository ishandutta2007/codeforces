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

int min( int a, int b, int c, int d, int e )
{
    return min( a, min( b, min( c, min( d, e ) ) ) );
}

int main (int argc, const char * argv[])
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;
    cout << min( a, b, c / 2, d / 7, e / 4 ) << "\n";
    return 0;
}