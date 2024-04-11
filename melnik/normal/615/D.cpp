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
const int base = 1e9 + 7;

int prime[maxn] = {0};

int bin ( int ch, int st ) {
    if ( st == 0 ) return 1;
    if ( st == 1 ) return ch;
    int k = bin( ch, st / 2 );
    if ( st % 2 ) {
        return ( ( 1LL * ( 1LL * k * k ) % base ) * 1LL * ch ) % base;
    }
    return ( 1LL * k * k ) % base;
}

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int m, j, x, ans = 1;
    int ch = 1;
    scanf ( "%d", &m );
    for ( j = 0; j < m; j++ ) {
        scanf ( "%d", &x );
        ch = ( 1LL * ch * x ) % base;
        prime[x]++;
    }
    bool cor = 0;
    for ( j = 0; j < maxn; j++ ) {
        if ( prime[j] % 2 ) cor = 1;
    }
    if ( cor ) {
        int ans = 1;
        for ( j = 0; j < maxn; j++ )
            if ( prime[j] % 2 ) {
                ans *= ( prime[j] + 1 ) / 2;
                prime[j] = 0;
                break;
            }
        for ( j = 0; j < maxn; j++ ) {
            ans = ( 1LL * ans * ( prime[j] + 1 ) ) % ( base - 1 );
        }
        printf ( "%d", bin( ch, ans ) );
        return 0;
    }
    for ( j = 0; j < maxn; j++ )
        ans = ( 1LL * ans * ( prime[j] + 1 ) ) % ( base - 1 );
    int for_a = 1;
    for ( j = 0; j < maxn; j++ ) {
        while ( prime[j] ) {
            for_a = ( 1LL * for_a * j ) % base;
            prime[j] -= 2;
        }
    }
    printf ( "%d", bin( for_a, ans ) );
    return 0;
}