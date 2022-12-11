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

struct block
{
    int balance, unclosed, answer;
    block() : balance( 0 ), unclosed( 0 ), answer( 0 ) {};
    block( int a, int b, int c ) : balance( a ), unclosed( b ), answer( c ) {};
};

block operator+( block b1, block b2 )
{
    int _balance = b1.balance + b2.balance;
    int _unclosed = b1.unclosed + b2.unclosed;
    int _answer = b1.answer + b2.answer;
    int _new = min( b1.balance, b2.unclosed );
    _balance -= _new;
    _unclosed -= _new;
    _answer += 2 * _new;
    return block( _balance, _unclosed, _answer );
} 

int n, m;
block tree[ 4000004 ];
char st[ 1000005 ];

void init( int v, int l, int r )
{
    if ( l == r )
    {
        if ( st[l - 1] == '(' )
        {
            tree[v].balance = 1;
            tree[v].unclosed = 0;
            tree[v].answer = 0;
        }
        if ( st[l - 1] == ')' )
        {
            tree[v].balance = 0;
            tree[v].unclosed = 1;
            tree[v].answer = 0;
        }
        return;
    }
    int x = (l + r) / 2;
    init( v + v, l, x );
    init( v + v + 1, x + 1, r );
    tree[v] = tree[v + v] + tree[v + v + 1];
}

block query( int v, int l, int r, int ll, int rr )
{
    if ( l == ll && rr == r ) return tree[v];
    int xx = (ll + rr) / 2;
    block left, right;
    if ( l <= xx ) 
        left = query( v + v, l, min( r, xx ), ll, xx );
    if ( xx + 1 <= r )
        right = query( v + v + 1, max( xx + 1, l ), r, xx + 1, rr );
    return left + right;
}

int main (int argc, const char * argv[])
{
    gets( st ); n = strlen( st );
    init( 1, 1, n );
    scanf("%d", &m);
    while ( m-- )
    {
        int l, r; scanf("%d%d", &l, &r);
        //printf("%d %d: %d\n", l, r, query( 1, l, r, 1, n ).answer );
        printf("%d\n", query( 1, l, r, 1, n ).answer );
    }
    return 0;
}