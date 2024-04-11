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

int n, a[ 333 ];
string ans = "";

int main (int argc, const char * argv[])
{
    cin >> n;
    for ( int i = 1; i <= n; i++ ) cin >> a[i];
    for ( int i = 1; i < n; i++ )
    {
        while ( a[i] > 0 )
        { 
            ans += 'R';
            ans += 'L';
            ans += 'P';
            a[i]--;
        }
        ans += 'R';
    }
    while ( a[n] > 0 )
    {
        ans += 'L';
        ans += 'R';
        ans += 'P';
        a[n]--;
    }
    cout << ans << "\n";
    return 0;
}