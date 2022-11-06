#include <iostream>
#include <fstream>
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

char t1[maxn], t[maxn];
vector < int > ans;

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    gets( t1 );
    t[0] = '+';
    t[1] = ' ';
    int n = strlen( t1 );
    for ( int j = 0; j < n; j++ )
        t[j + 2] = t1[j];
    n = strlen( t );
    int r = n - 1;
    int cnt = 0;
    int cur = 1;
    while ( t[r] != ' ' ) {
        cnt += ( t[r] - '0' ) * cur;
        cur *= 10;
        --r;
    }
    int cnt1 = 0;
    int cnt2 = 0;
    for ( int j = 0; j < n; j++ ) {
//        printf ( "%c", t[j] );
        if ( t[j] == '+' ) {
            ++cnt1;
            ans.pb( 1 );
        }
        if ( t[j] == '-' ) {
            ++cnt2;
            ans.pb( -1 );
        }
    }
//    cout << endl;
    n = ans.size();
    int curSum = 0;
    for ( int j = 0; j < n; j++ )
        curSum += ans[j];
    while ( curSum != cnt ) {
        if ( curSum < cnt ) {
            int l = 0;
            while ( l < n && ( ans[l] == cnt || ans[l] < 0 ) )
                ++l;
            if ( l == n ) {
                puts( "Impossible" );
                return 0;
            }
            ans[l] = min( cnt, cnt - curSum + ans[l] );
            curSum = 0;
            for ( int j = 0; j < n; j++ )
                curSum += ans[j];
        } else {
            int l = 0;
            while ( l < n && ( ans[l] == -cnt || ans[l] > 0 ) )
                ++l;
            if ( l == n ) {
                puts( "Impossible" );
                return 0;
            }
            ans[l] = max( -cnt, cnt - curSum + ans[l] );
            curSum = 0;
            for ( int j = 0; j < n; j++ )
                curSum += ans[j];
        }
    }
    puts( "Possible" );
    for ( int j = 0; j < n; j++ ) {
        if ( j == 0 ) {
            printf ( "%d ", ans[j] );
            continue;
        }
        if ( ans[j] < 0 )
            printf ( "- " );
        else
            printf ( "+ " );
        printf ( "%d ", abs( ans[j] ) );
    }
    printf ( "= %d\n", cnt );
    return 0;
}