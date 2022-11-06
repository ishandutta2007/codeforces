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
#include <cassert>
 
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
 
int a[maxn][5];
int c[5];
int curSolutions[maxn];
 
inline int getCost( int x, int y ) {
    if ( 2 * x > y )
        return 1;
    if ( 4 * x > y )
        return 2;
    if ( 8 * x > y )
        return 3;
    if ( 16 * x > y )
        return 4;
    if ( 32 * x > y )
        return 5;
    return 6;
}
 
inline int leftCost(int cost) {
    return (1 << cost);
}
 
inline int rightCost(int cost) {
    return 1 << (cost - 1);
}
 
int ans = inf;
int bots;
 
void calc( int n ) {
    int curAns = 0;
    int sum = 0;
    int maxAns = inf;
    for ( int task = 0; task < 5; task++ ) {
        int cost = c[task];
        if ( cost == getCost( curSolutions[task], n ) )
            continue;
        if ( cost < getCost( curSolutions[task], n ) && a[0][task] == -1 )
            return;
        if ( cost < getCost( curSolutions[task], n ) ) {
            int e = leftCost( cost );
            int l = n / e - curSolutions[task];
            ++l;
            assert( l >= 0 );
            // int l = 0;
            // int r = 1 + bots;
            // while ( r - l ) {
            //  int mid = ( l + r ) >> 1;
            //  if ( getCost( curSolutions[task] + mid, n ) > cost )
            //      l = mid + 1;
            //  else
            //      r = mid;
            // }
            if ( l > bots )
                return;
            curAns = max( curAns, l );
            // if ( cost == 1 )
            //     l = maxn;
            // else {
            //     int e = rightCost( cost );
            //     int l = n / e - curSolutions[task];
            //     assert( l >= 0 );
            // }
            // // l = 0;
            // // r = 2 + bots;
            // // while ( r - l ) {
            // //  int mid = ( l + r ) >> 1;
            // //  if ( getCost( curSolutions[task] + mid, n ) >= cost )
            // //      l = mid + 1;
            // //  else
            // //      r = mid;
            // // }
            // // --l;
            // maxAns += l;
        }
        if ( cost > getCost( curSolutions[task], n ) ) {
            int e = rightCost( cost );
            int l = curSolutions[task] * e - ( n - bots );
            assert( l >= 0 );
            // int l = 0;
            // int r = 1 + bots;
            // while ( r - l ) {
            //  int mid = ( l + r ) >> 1;
            //  if ( getCost( curSolutions[task], n ) < cost )
            //      l = mid + 1;
            //  else
            //      r = mid;
            // }
            if ( l > bots )
                return;
            curAns = max( curAns, l );
 
            // if ( cost == 6 )
            //     l = maxn;
            // else {
            //     int e = leftCost( cost );
            //     int l = curSolutions[task] * e - ( n - bots ) - 1;
            //     assert( l >= 0 );
            // }
            // // l = 0;
            // // r = 2 + bots;
            // // while ( r - l ) {
            // //  int mid = ( l + r ) >> 1;
            // //  if ( getCost( curSolutions[task], n ) <= cost )
            // //      l = mid + 1;
            // //  else
            // //      r = mid;
            // // }
            // // --l;
            // maxAns += l;
        }
    }
    if ( bots < curAns || bots > maxAns )
        return;
    for ( int j = 0; j < 5; j++ ) {
        int task = j;
        int cost = c[task];
        sum += ( a[0][task] != -1 ) ? ( cost * 500 - cost * 2 * a[0][task] ) : 0;
        sum -= ( a[1][task] != -1 ) ? ( cost * 500 - cost * 2 * a[1][task] ) : 0;
    }
    if ( sum > 0 ) {
//         if (bots == 1) {
//          for (int i = 0; i < 5; i++)
//              cout << c[i] << ' ';
//          exit(0);
//         }
        ans = min( ans, bots );
    }
}
 
int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "out2.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    for ( int j = 0; j < n; j++ )
        for ( int i = 0; i < 5; i++ ) {
            scanf ( "%d", &a[j][i] );
            if ( a[j][i] != -1 )
                ++curSolutions[i];
        }
    // c = {1, 3, 1, 2, 6};
    // calc( n );
//    c[0] = 2;
//    c[1] = 2;
//    c[2] = 1;
//    c[3] = 1;
//    c[4] = 1;
//    bots = 1;
//    calc( n + 1 );
    for ( int j = 0; j < 4000; j++ ) {
        bots = j;
        for (c[0] = 1; c[0] <= 6 && ans != j; c[0]++)
            for (c[1] = 1; c[1] <= 6 && ans != j; c[1]++)
                for (c[2] = 1; c[2] <= 6 && ans != j; c[2]++)
                    for (c[3] = 1; c[3] <= 6 && ans != j; c[3]++)
                        for (c[4] = 1; c[4] <= 6 && ans != j; c[4]++) {
                            calc( n + j );
                            if (ans == j)
                                break;
                        }
        if (ans == j)
            break;
        // solve( 0, n + j );
    }
    if ( ans == inf )
        puts( "-1" );
    else
        printf ( "%d\n", ans );
    return 0;
}