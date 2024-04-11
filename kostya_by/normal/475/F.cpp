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

int n, x[ 100100 ], y[ 100100 ];

class cmp_x
{
public:
    bool operator()( int a, int b )
    {
        return make_pair( x[a], a ) < make_pair( x[b], b ); 
    }
};

class cmp_y
{
public:
    bool operator()( int a, int b )
    {
        return make_pair( y[a], a ) < make_pair( y[b], b ); 
    }
};

struct data
{
    set< int, cmp_x > xx;
    set< int, cmp_y > yy;
};

data q[ 100100 ];
int head = 1, tail = 1;
vector< int > current;

void solve()
{
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ )
    {
        scanf("%d%d", &x[i], &y[i] );
        q[1].xx.insert( i );
        q[1].yy.insert( i );
    }
    while ( head <= tail )
    {
        set< int, cmp_x >::iterator x_left  = q[ head ].xx.begin();
        set< int, cmp_x >::iterator x_right = q[ head ].xx.end(); x_right--;
        set< int, cmp_x >::iterator tmp_x;

        set< int, cmp_y >::iterator y_left  = q[ head ].yy.begin();
        set< int, cmp_y >::iterator y_right = q[ head ].yy.end(); y_right--;
        set< int, cmp_y >::iterator tmp_y;

        bool is_splitted = false;
        bool move = true;

        while ( move )
        {
            move = false;
            // BLOCK 1
            if ( x_left != q[ head ].xx.end() )
            {
                tmp_x = x_left; tmp_x++;
                if ( tmp_x != q[ head ].xx.end() )
                {
                    int x1 = x[ *x_left ];
                    int x2 = x[ *tmp_x ];
                    if ( x1 + 1 < x2 )
                    {
                        is_splitted = true;
                        tail++;
                        current.clear();
                        for ( set< int, cmp_x >::iterator it = q[ head ].xx.begin(); it != tmp_x; it++ ) current.push_back( *it );
                        for ( int i = 0; i < current.size(); i++ )
                        {
                            q[ head ].xx.erase ( current[i] );
                            q[ head ].yy.erase ( current[i] );
                            q[ tail ].xx.insert( current[i] );
                            q[ tail ].yy.insert( current[i] );
                        }
                    }
                }
                move = true;
                x_left++;
            }
            if ( is_splitted ) break;
            // BLOCK 2
            if ( x_right != q[ head ].xx.begin() )
            {
                tmp_x = x_right; tmp_x--;
                int x1 = x[ *tmp_x ];
                int x2 = x[ *x_right ];
                if ( x1 + 1 < x2 )
                {
                    is_splitted = true;
                    tail++;
                    current.clear();
                    for ( set< int, cmp_x >::iterator it = --q[ head ].xx.end(); it != tmp_x; it-- ) current.push_back( *it );
                    for ( int i = 0; i < current.size(); i++ )
                    {
                        q[ head ].xx.erase ( current[i] );
                        q[ head ].yy.erase ( current[i] );
                        q[ tail ].xx.insert( current[i] );
                        q[ tail ].yy.insert( current[i] );
                    }   
                }
                x_right--;
                move = true;
            }
            if ( is_splitted ) break;
            // BLOCK 3
            if ( y_left != q[ head ].yy.end() )
            {
                tmp_y = y_left; tmp_y++;
                if ( tmp_y != q[ head ].yy.end() )
                {
                    int y1 = y[ *y_left ];
                    int y2 = y[ *tmp_y ];
                    if ( y1 + 1 < y2 )
                    {
                        is_splitted = true;
                        tail++;
                        current.clear();
                        for ( set< int, cmp_y >::iterator it = q[ head ].yy.begin(); it != tmp_y; it++ ) current.push_back( *it );
                        for ( int i = 0; i < current.size(); i++ )
                        {
                            q[ head ].xx.erase ( current[i] );
                            q[ head ].yy.erase ( current[i] );
                            q[ tail ].xx.insert( current[i] );
                            q[ tail ].yy.insert( current[i] );
                        }
                    }
                }
                y_left++;
                move = true;
            }
            if ( is_splitted ) break;
            // BLOCK 4
            if ( y_right != q[ head ].yy.begin() )
            {
                tmp_y = y_right; tmp_y--;
                int y1 = y[ *tmp_y ];
                int y2 = y[ *y_right ];
                if ( y1 + 1 < y2 )
                {
                    is_splitted = true;
                    tail++;
                    current.clear();
                    for ( set< int, cmp_y >::iterator it = --q[ head ].yy.end(); it != tmp_y; it-- ) current.push_back( *it );
                    for ( int i = 0; i < current.size(); i++ )
                    {
                        q[ head ].xx.erase ( current[i] );
                        q[ head ].yy.erase ( current[i] );
                        q[ tail ].xx.insert( current[i] );
                        q[ tail ].yy.insert( current[i] );
                    }   
                }
                y_right--;
                move = true;
            }
            if ( is_splitted ) break;
        }
        if ( !is_splitted ) head++;
    }
    cout << tail << "\n";
}

int main (int argc, const char * argv[])
{
    time_t start = clock();
    int t = 1;
    for ( int i = 0; i < t; i++ ) solve();
    cerr << fixed << setprecision( 6 ) << "Time: " << 1.0 * ( clock() - start ) / CLOCKS_PER_SEC << "\n";
    return 0;
}