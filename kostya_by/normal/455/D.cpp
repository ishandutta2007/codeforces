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
const int block_sz = 420;

using namespace std;

struct block
{
    vector< int > values;
    int cnt[ 100100 ];
    block()
    {
        values.clear();
        memset( cnt, 0, sizeof( cnt ) );
    }
    int query( int l, int r, int k )
    {
        if ( l == 0 && r + 1 == values.size() ) return cnt[ k ];
        int result = 0;
        for ( int i = l; i <= r; i++ ) if ( values[i] == k ) result += 1;
        return result;
    }
    void add( int pos, int value )
    {
        cnt[ value ] += 1;
        values.insert( values.begin() + pos, value );
    }
    void del( int pos )
    {
        int value = values[ pos ];
        cnt[ value ] -= 1;
        values.erase( values.begin() + pos );
    } 
};

int n, a[ 100100 ], q1 = 0, answer = 0;
block b[ 400 ];

void rebuild()
{
    int h = 0;
    for ( int i = 0; i < 400; i++ )
    {
        for ( int j = 0; j < b[i].values.size(); j++ )
        {
            a[ h++ ] = b[i].values[j];
            b[i].cnt[ b[i].values[j] ]--;
        }
        b[i].values.clear();
    }
    int lst = 0, pos = 0;
    for ( int i = 0; i < n; i++ )
    {
        if ( b[lst].values.size() >= block_sz ) lst++, pos = 0;
        b[ lst ].add( pos++, a[i] );
    } 
}

void rotate( int l, int r )
{
    if ( l == r ) return;
    int tmp = 0;
    int insert_id, insert_pos;
    int delete_id, delete_pos;
    for ( int i = 0; i < 400; i++ )
    {
        if ( b[i].values.size() == 0 ) continue;
        int left = tmp;
        int right = tmp + b[i].values.size(); right -= 1;
        if ( left <= l && l <= right )
        {
            insert_id = i;
            insert_pos = l - tmp;
        } 
        if ( left <= r && r <= right )
        {
            delete_id = i;
            delete_pos = r - tmp;
        } 
        tmp += b[i].values.size();
    }
    int value = b[ delete_id ].values[ delete_pos ];
    b[ delete_id ].del( delete_pos );
    b[ insert_id ].add( insert_pos, value );
    q1 += 1;
}

int query( int l, int r, int k )
{
    int tmp = 0;
    int result = 0;
    for ( int i = 0; i < 400; i++ )
    {
        if ( b[i].values.size() == 0 ) continue;
        int left = tmp;
        int right = tmp + b[i].values.size(); right -= 1;
        left = max( left, l );
        right = min( right, r );
        if ( left <= right ) result += b[i].query( left - tmp, right - tmp, k );
        tmp += b[i].values.size();
    }
    return result;
} 

int main (int argc, const char * argv[])
{
    scanf("%d", &n);
    for ( int i = 0; i < n; i++ )
    {
        scanf("%d", &a[i]);
        b[ 0 ].add( i, a[i] );
    }
    rebuild();
    int q; scanf("%d", &q);
    for ( int i = 0; i < q; i++ )
    {
        int id; scanf("%d", &id);
        if ( id == 1 )
        {
            int l, r; scanf("%d%d", &l, &r);
            l = ( l + answer - 1 ) % n;
            r = ( r + answer - 1 ) % n;
            if ( l > r ) swap( l, r );
            rotate( l, r );
            if ( q1 >= 400 )
            {
                q1 = 0;
                rebuild();
            }
        } else
        {
            int l, r, k; scanf("%d%d%d", &l, &r, &k);
            l = ( l + answer - 1 ) % n;
            r = ( r + answer - 1 ) % n;
            k = ( k + answer - 1 ) % n + 1;
            if ( l > r ) swap( l, r );
            answer = query( l, r, k );
            printf("%d\n", answer);
        }
    }
    return 0;
}

/*
7
6 6 2 7 4 2 5
7
1 3 6
2 2 4 2
2 2 4 7
2 2 2 5
1 2 6
1 1 4
2 1 7 3
*/