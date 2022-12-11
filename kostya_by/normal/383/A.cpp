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

int n, a[ 200200 ];
long long ans1 = 0, ans2 = 0;
long long ones = 0, zeros = 0;

int main ( int argc, const char * argv[] )
{
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ ) 
    {
        scanf("%d", &a[i]);
    }
    for ( int i = n; i >= 1; i-- )
    {
        if ( a[i] == 0 ) zeros++; else ans1 += zeros;
    }
    for ( int i = 1; i <= n; i++ )
    {
        if ( a[i] == 1 ) ones++; else ans2 += ones;
    }
    cout << min( ans1, ans2 ) << "\n";
    return 0;
}