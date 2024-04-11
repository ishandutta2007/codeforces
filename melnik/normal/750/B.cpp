#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>


using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 100500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int now = 0;
    for ( int j = 0; j < n; j++ ) {
        int x;
        string wh;
        cin >> x >> wh;
        // if ( wh == "East" )
        //     continue;
        // if ( wh == "West" )
        //     continue;
        for ( int j = 0; j < x; j++ ) {
            if ( now == 20000 && wh != "North" ) {
                puts( "NO" );
                return 0;
            }
            if ( now == 0 && wh != "South" ) {
                puts( "NO" );
                return 0;
            }
            if ( wh == "South" )
                ++now;
            if ( wh == "North" )
                --now;
        }
        // if ( abs( now ) % 40000 == 20000 && wh != "North" )   {
        //  puts( "NO" );
        //  return 0;
        // }
        // if ( abs( now ) % 40000 == 0 && wh != "South" ) {
        //  puts( "NO" );
        //  return 0;
        // }
        // if ( wh == "North" )
        //  now -= x;
        // if ( wh == "South" )
        //  now += x;
    }
    if ( now )
        puts( "NO" );
    else
        puts( "YES" );
    // if ( abs( now ) % 40000 != 0 )
    //  puts( "NO" );
    // else
    //  puts( "YES" );
    return 0;
}