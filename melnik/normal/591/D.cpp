#include <iostream>
#include <fstream>
#include <stdio.h>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <ext\hash_set>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <ctime>
#include <iterator>
#include <cstdio>


using namespace std;

typedef long long ll;
typedef long double ld;


#define double ld


#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 1e5;
const int inf = 2e9;
const double eps = 1e-10;

int x1, y11, x2, y2, v, t, xv, yv, xw, yw;

bool can ( double f ) {
    if ( t - f > -eps ) {
        double new_x2 = x2 - xv * f;
        double new_y2 = y2 - yv * f;
        double new_s = sqrt ( new_x2 * new_x2 + new_y2 * new_y2 );
        if ( new_s / v + eps < f ) return 1;
        return 0;
    }
    double new_x2 = x2 - xv * ( double ) t - xw * ( f - ( double ) t );
    double new_y2 = y2 - yv * ( double ) t - yw * ( f - ( double ) t );
    double new_s = sqrt ( new_x2 * new_x2 + new_y2 * new_y2 );
    if ( new_s / v + eps < f ) return 1;
    return 0;
}

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
    scanf ( "%d%d%d%d", &x1, &y11, &x2, &y2 );
    scanf ( "%d%d", &v, &t );
    scanf ( "%d%d%d%d", &xv, &yv, &xw, &yw );
    x2 -= x1;
    y2 -= y11;
    if ( x2 < 0 ) {
        x2 = -x2;
        xv = -xv;
        xw = -xw;
    }
    if ( y2 < 0 ) {
        y2 = -y2;
        yv = -yv;
        yw = -yw;
    }
    double r = 1e14, l = 0;
    while ( fabs ( r - l ) > eps ) {
        double mid = ( l + r ) / 2.0;
        if ( can( mid ) )
            r = mid; else l = mid;
    }
#undef double ld
    double ans = ( l + r ) / 2.0;
    printf ( "%.35lf", ans );
    return 0;
}