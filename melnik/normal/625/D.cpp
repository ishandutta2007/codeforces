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

char t[maxn];
int a[maxn], a1[maxn];
int ans[maxn];

void put( int n ) {
    int j;
    int it = n / 2;
//    if ( n % 2 ) it--;
//    cout << it << endl;
    for ( j = 0; j < it; j++ ) {
        if ( a[j] != a[n - j - 1] ) {
            if ( n - j - 1 - j <= 2 ) {
                a[j]--;
                a[j + 1] += 10;
            } else {
                a[j + 1] += 10;
                a[j]--;
                if ( a[n - j - 2] != 9 ) {
                    a[n - j - 2] += 10;
                    a[n - j - 3]--;
                }
                int l = n - j - 3;
                while ( l > 0 && a[l] == -1 ) {
                    a[l - 1]--;
                    a[l] += 10;
                    l--;
                }
            }
        }
//        for ( int i = 0; i < 10; i++ )
//            cout << a[i] << ' ';
//        cout << endl;
        if ( a[j] != a[n - j - 1] )
            return;
        ans[j] = a[j] / 2 + a[j] % 2;
        ans[n - j - 1] = a[j] - ans[j];
    }
    if ( n % 2 ) {
        if ( a[n / 2] % 2 ) return;
        ans[n / 2] = a[n / 2] / 2;
    }
    if ( ans[0] ) {
    for ( j = 0; j < n; j++ )
        printf ( "%d", ans[j] );
    } else return;
    exit( 0 );
}

void put1( int n ) {
    int j;
    int it = n / 2;
    for ( j = 1; j <= it; j++ ) {
        if ( a[j] != a[n - j + 1] ) {
            if ( n - j + 1 - j <= 2 ) {
                a[j]--;
                a[j + 1] += 10;
            } else {
                a[j + 1] += 10;
                a[j]--;
                if ( a[n - j] != 9 ) {
                    a[n - j] += 10;
                    a[n - j - 1]--;
                }
                int l = n - j - 1;
                while ( l > 0 && a[l] == -1 ) {
                    a[l - 1]--;
                    a[l] += 10;
                    l--;
                }
            }
        }
//        for ( int i = 0; i < 10; i++ )
//            cout << a[i] << ' ';
//        cout << endl;
        if ( a[j] != a[n - j + 1] )
            return;
        ans[j] = a[j] / 2 + a[j] % 2;
        ans[n - j + 1] = a[j] - ans[j];
    }
    if ( n % 2 ) {
        if ( a[n / 2 + 1] % 2 ) return;
        ans[n / 2 + 1] = a[n / 2 + 1] / 2;
    }
    if ( ans[1] ) {
    for ( j = 1; j <= n; j++ )
        printf ( "%d", ans[j] );
    } else return;
    exit( 0 );
}

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    gets( t );
    int n = strlen( t ), j;
    for ( int j = 0; j < n; j++ )
        a[j] = t[j] - '0';
    for ( j = 0; j < n; j++ )
        a1[j] = a[j];
    put( n );
    for ( j = 0; j < n; j++ )
        a[j] = a1[j];
////    cout << a[0] << endl;
    if ( a[0] == 1 ) {
        a[1] += 10;
        a[n - 1] += 10;
//        if ( a[n - 2] ) a[n - 2]--;
//            else {
//                printf ( "0" );
//                return 0;
//            }
        int r = n - 2;
        while ( !a[r] )
            r--;
        a[r]--;
        for ( ++r; r < n - 1; r++ )
            a[r] = 9;
//        for ( int i = 0; i < 10; i++ )
//            cout << a[i] << ' ';
//        cout << endl;
        put1( n - 1 );
    }
    printf ( "0" );
    return 0;
}