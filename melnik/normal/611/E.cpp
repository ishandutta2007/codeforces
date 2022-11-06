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

const int maxn = 200500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[3];
int t[maxn];
multiset < int > crim;
multiset < int >::iterator it, it1, it2, it3;

bool check ( int str, int z ) {
    if ( str < z ) return 0;
    return 1;
}

void calc1 ( int num ) {
    it = crim.upper_bound( a[num] );
    if ( it == crim.begin() )
        return;
    if ( crim.empty() )
        return;
    it--;
    crim.erase( it );
}

void calc2 ( int num1, int num2 ) {
    it1 = crim.upper_bound( a[num1] );
    it2 = crim.upper_bound( a[num2] );
    if ( it1 == crim.begin() ) {
        it3 = crim.upper_bound( a[num2] + a[num1] );
        if ( it3 == crim.begin() )
            return ;
        if ( crim.empty() )
            return;
        it3--;
        crim.erase( it3 );
        return;
    }
    if ( it2 == crim.begin() ) {
        it3 = crim.upper_bound( a[num2] + a[num1] );
        if ( it3 == crim.begin() )
            return ;
        if ( crim.empty() )
            return;
        it3--;
        crim.erase( it3 );
        return;
    }
    if ( crim.empty() )
        return;
    it1--;
    it2--;
    if ( it1 == it2 ) {
        if ( it1 == crim.begin() ) {
            crim.erase( it1 );
            return;
        }
        it1--;
    }
    crim.erase( it1 );
    crim.erase( it2 );
}


int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, j;
    scanf ( "%d", &n );
    scanf ( "%d%d%d", &a[0], &a[1], &a[2] );
    for ( j = 0; j < n; j++ ) {
        scanf ( "%d", &t[j] );
        crim.insert( t[j] );
    }
    sort( a, a + 3 );
    int ans = 0;
    while ( !crim.empty() ) {
        int x = *crim.rbegin();
        if ( x <= a[0] ) {
            it = crim.end();
            it--;
            crim.erase( it );
            if ( !crim.empty() ) {
                it = crim.end();
                it--;
                crim.erase( it );
            }
            if ( !crim.empty() ) {
                it = crim.end();
                it--;
                crim.erase( it );
            }
            ans++;
            continue;
        }
        if ( check( a[1], x ) ) {
            crim.erase( crim.find( x ) );
            calc2( 0, 2 );
            ans++;
            continue;
        }
        if ( check( a[2], x ) ) {
            crim.erase( crim.find( x ) );
            calc2( 0, 1 );
            ans++;
            continue;
        }
        if ( check( a[0] + a[1], x ) ) {
            crim.erase( crim.find( x ) );
            calc1( 2 );
            ans++;
            continue;
        }
        if ( check( a[0] + a[2], x ) ) {
            crim.erase( crim.find( x ) );
            calc1( 1 );
            ans++;
            continue;
        }
        if ( check( a[1] + a[2], x ) ) {
            crim.erase( crim.find( x ) );
            calc1( 0 );
            ans++;
            continue;
        }
        if ( check( a[0] + a[1] + a[2], x ) ) {
            crim.erase( crim.find( x ) );
            ans++;
            continue;
        }
        printf ( "-1\n" );
        return 0;
    }
    printf ( "%d", ans );
    return 0;
}