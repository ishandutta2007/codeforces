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
    int tp, c, pref, x;
    long long l, r;
    block()
    {
        tp = c = pref = 0;
        l = r = 0;
    }
};

int n, m;
long long len = 0;
vector< block > a;
vector< int > pref;

int main (int argc, const char * argv[])
{
    pref.pb( -1 );
    scanf("%d", &m);
    for ( int it = 0; it < m; it++ )
    {
        int tp; scanf("%d", &tp);
        if ( tp == 1 )
        {
            int x; scanf("%d", &x);
            block cur;
            cur.tp = 1;
            cur.x = x;
            cur.l = len + 1;
            cur.r = len + 1;
            len++;
            a.pb( cur ); 
            if ( pref.size() < 200000 ) pref.pb( x );
        }
        if ( tp == 2 )
        {
            int l, c; scanf("%d%d", &l, &c);
            block cur;
            cur.tp = 2;
            cur.pref = l;
            cur.c = c;
            cur.l = len + 1;
            cur.r = len + c * l;
            len += c * l;
            a.pb( cur );
            for ( int i = 0; i < c; i++ )
            {
                if ( pref.size() >= 200000 ) break;
                for ( int j = 1; j <= l; j++ )
                {
                    if ( pref.size() >= 200000 ) break;
                    pref.pb( pref[j] );
                }
            }
        }
    }
    scanf("%d", &n);
    //for ( int i = 0; i < pref.size(); i++ ) cout << pref[i] << " "; cout << "\n"; 
    for ( int it = 0; it < n; it++ )
    {
        long long pos; scanf("%I64d", &pos);
        int l = 0, r = a.size() - 1, res = 0;
        while ( l <= r )
        {
            int x = (l + r) / 2;
            if ( a[x].l <= pos )
            {
                res = max( res, x );
                l = x + 1;
            } else r = x - 1;
        }
        int x = res;
        //cout << x << " " << a[x].tp << "\n";
        if ( a[x].tp == 1 )
        {
            printf("%d ", a[x].x);
            continue;
        }
        long long pos_in_block = pos - a[x].l + 1;
        pos_in_block %= a[x].pref;
        if ( pos_in_block == 0 ) pos_in_block = a[x].pref;
        //cout << pos_in_block << "\n";
        printf("%d ", pref[ (int)pos_in_block ]);
    }
    return 0;
}

/*
6
1 1
1 2
2 2 1
1 3
2 5 2
1 4
16
1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
*/