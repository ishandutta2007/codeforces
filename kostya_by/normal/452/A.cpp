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

string t;
string s[ 8 ] = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main (int argc, const char * argv[])
{
    int n; cin >> n;
    cin >> t;
    for ( int i = 0; i < 8; i++ )
    {
        if ( s[i].size() != n ) continue;
        bool ok = true;
        for ( int j = 0; j < n; j++ )
        {
            if ( t[j] == '.' ) continue;
            if ( t[j] != s[i][j] ) ok = false;
        }
        if ( ok ) cout << s[i] << "\n";
    }
    return 0;
}