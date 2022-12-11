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

int main (int argc, const char * argv[])
{
    string a, b;
    cin >> a >> b;
    int cnt1 = 0, cnt2 = 0;
    for ( int i = 0; i < a.size(); i += 2 )
    {
        if ( a[i] == b[i] ) continue;
        if ( a[i] == '8' && b[i] == '(' ) cnt2++;
        if ( a[i] == '8' && b[i] == '[' ) cnt1++;
        if ( a[i] == '(' && b[i] == '[' ) cnt2++;
        if ( a[i] == '(' && b[i] == '8' ) cnt1++;
        if ( a[i] == '[' && b[i] == '(' ) cnt1++;
        if ( a[i] == '[' && b[i] == '8' ) cnt2++;
    }
    if ( cnt1 > cnt2 ) puts("TEAM 1 WINS");
    if ( cnt1 < cnt2 ) puts("TEAM 2 WINS");
    if ( cnt1 == cnt2 ) puts("TIE");
    return 0;
}