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
const long long mod = 1000000009;

using namespace std;

struct node
{
    long long a, b, sum;
    node( long long a = 0, long long b = 0, long long sum = 0 ) : a( a ), b( b ), sum( sum ) {}; 
};

node tree[ 4 * 300300 ];
// ----------------------------------------------------------
int n, q;
long long pref[ 300300 ], pref_a[ 300300 ], pref_b[ 300300 ];
long long aa[ 300300 ], bb[ 300300 ];
int br[ 300300 ];

long long calculate( int len, long long a, long long b )
{
    long long result_a = pref_a[ len ] * a;
    long long result_b = pref_b[ len ] * b;
    return ( result_a + result_b ) % mod;
}

void modify( int v, int l, int r, int ll, int rr, long long a, long long b )
{
    if ( l == ll && rr == r )
    {
        ( tree[v].a += a ) %= mod;
        ( tree[v].b += b ) %= mod;
        ( tree[v].sum += calculate( r - l + 1, a, b ) ) %= mod;
        return;
    }
    int x = (l + r) / 2;
    if ( ll <= x ) modify( v + v, l, x, ll, min( x, rr ), a, b );
    if ( x + 1 <= rr )
    {
        if ( ll < x + 1 )
        {
            long long _a = ( aa[ x - ll + 2 ] * a + bb[ x - ll + 2 ] * b ) % mod;
            long long _b = ( aa[ x - ll + 3 ] * a + bb[ x - ll + 3 ] * b ) % mod;
            modify( v + v + 1, x + 1, r, x + 1, rr, _a, _b );
        } else
        {
            modify( v + v + 1, x + 1, r, ll, rr, a, b );
        }
    }
    ( tree[v].sum += calculate( rr - ll + 1, a, b ) ) %= mod;
}

long long query( int v, int l, int r, int ll, int rr, long long a, long long b )
{
    if ( l == ll && rr == r ) 
    {
        return ( tree[v].sum + calculate( r - l + 1, a, b ) ) % mod;
    }
    int x = ( l + r ) / 2;
    long long _a = ( a + aa[ ll - l + 1 ] * tree[v].a + bb[ ll - l + 1 ] * tree[v].b ) % mod;
    long long _b = ( b + aa[ ll - l + 2 ] * tree[v].a + bb[ ll - l + 2 ] * tree[v].b ) % mod;
    long long result = 0;
    if ( ll <= x ) 
        ( result += query( v + v, l, x, ll, min( x, rr ), _a, _b ) ) %= mod;
    if ( x + 1 <= rr )
    {
        if ( ll < x + 1 )
        {
            long long __a = ( aa[ x - ll + 2 ] * _a + bb[ x - ll + 2 ] * _b ) % mod;
            long long __b = ( aa[ x - ll + 3 ] * _a + bb[ x - ll + 3 ] * _b ) % mod;
            ( result += query( v + v + 1, x + 1, r, max( x + 1, ll ), rr, __a, __b ) ) %= mod;
        } else
        {
            ( result += query( v + v + 1, x + 1, r, max( x + 1, ll ), rr, _a, _b ) ) %= mod;
        }
    }
    return result;
}

void gen()
{
    freopen("in.txt", "w", stdout);
    srand( time( NULL ) ); 
    n = 1000;
    q = 1000;
    cout << n << " " << q << "\n";
    for ( int i = 1; i <= n; i++ )
    {
        int a = rand() % 1000000000 + 1;
        cout << a << " ";
    }
    cout << "\n";
    for ( int i = 1; i <= q; i++ )
    {
        int id = rand() % 2 + 1;
        int l = rand() % n + 1;
        int r = rand() % n + 1;
        if ( l > r ) swap( l, r );
        cout << id << " " << l << " " << r << "\n";
    }
    exit( 0 );
}

int main (int argc, const char * argv[])
{
    //gen();
    aa[1] = 1; bb[2] = 1;
    for ( int i = 3; i < 300300; i++ )
    {
        aa[i] = ( aa[i - 1] + aa[i - 2] ) % mod;
        bb[i] = ( bb[i - 1] + bb[i - 2] ) % mod;
    }
    for ( int i = 1; i < 300300; i++ )
    {
        pref_a[i] = ( pref_a[i - 1] + aa[i] ) % mod;
        pref_b[i] = ( pref_b[i - 1] + bb[i] ) % mod;
    }
    //----------------------------------
    scanf("%d%d", &n, &q);
    for ( int i = 1; i <= n; i++ )
    {
        int a; scanf("%d", &a);
        br[i] = a;
        pref[i] = pref[i - 1] + a;
    }
    for ( int it = 0; it < q; it++ )
    {
        int id, l, r; scanf("%d%d%d", &id, &l, &r);
        if ( id == 1 ) 
        {
            modify( 1, 1, n, l, r, 1, 1 );
            //----------------------------
            /*int id = 1;
            int fi = 1, se = 1;
            for ( int i = l; i <= r; i++ )
            {
                ( br[i] += ( aa[id] + bb[id] ) % mod ) %= mod;
                id++;
                int th = ( fi + se ) % mod;
                fi = se;
                se = th;
            }*/
        }
        if ( id == 2 )
        {
            //int br_answer = 0;
            //for ( int i = l; i <= r; i++ ) ( br_answer += br[i] ) %= mod;
            //--------------------
            long long answer = query( 1, 1, n, l, r, 0, 0 ) + pref[r] - pref[l - 1];
            answer %= mod;
            printf("%d\n", (int)answer); 
        }
        //cout << it << " done!" << endl;
    }
    return 0;
}