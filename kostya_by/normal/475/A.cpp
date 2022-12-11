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

string s[ 6 ];

void add()
{
    for ( int j = 0; j < 100; j++ )
        for ( int i = 0; i < 6; i++ )
        {
            //if ( s[i].size() >= j ) continue;
            if ( s[i].size() > j && s[i][j] == '#' )
            {
                s[i][j] = 'O';
                return;
            }
        }
}

void solve()
{
    s[0] = "+------------------------+";
    s[1] = "|#.#.#.#.#.#.#.#.#.#.#.|D|)";
    s[2] = "|#.#.#.#.#.#.#.#.#.#.#.|.|";
    s[3] = "|#.......................|";
    s[4] = "|#.#.#.#.#.#.#.#.#.#.#.|.|)";
    s[5] = "+------------------------+";
    int k; cin >> k;
    for ( int i = 0; i < k; i++ ) add();
    for ( int i = 0; i < 6; i++ ) 
    {
        cout << s[i];// << "\n";
        if ( i != 5 ) cout << "\n";
    }
}

int main (int argc, const char * argv[])
{
    time_t start = clock();
    int t = 1;
    for ( int i = 0; i < t; i++ ) solve();
    //cerr << fixed << setprecision( 6 ) << "Time: " << 1.0 * ( clock() - start ) / CLOCKS_PER_SEC << "\n";
    return 0;
}