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
const int inf = 1e9 + 5;
const double eps = 1e-8;
const int base = 1073676287;

struct line {
    int x1, y1, x2, y2;
    line ( int _x1, int _y1, int _x2, int _y2 ) {
        x1 = min( _x1, _x2 );
        y1 = max( _y1, _y2 );
        x2 = max( _x1, _x2 );
        y2 = min( _y1, _y2 );
    }
    bool operator < ( const line &a ) const {
        if ( a.y1 == a.y2 ) {
            if ( this -> y1 != a.y1 )
                return this -> y1 < a.y1;
            return this -> x1 < a.x1;
        } else {
            if ( this -> x1 != a.x1 ) return this -> x1 < a.x1;
            return this -> y1 > a.y1;
        }
    }
};

vector < line > horNC;
vector < line > verNC;
vector < line > hor;
vector < line > ver;
vector < int > allY;
vector < int > allX;

void initVer() {
    ver.pb( line( -1, -1, -1, -1 ) );
    int n = verNC.size();
    sort( verNC.begin(), verNC.end() );
    int l, r;
    l = r = 0;
    while ( l < n ) {
        int DownY = verNC[l].y2;
        while ( r < n &&
               verNC[r].x1 == verNC[l].x1 &&
               verNC[r].y1 >= DownY ) {
            DownY = min( DownY, verNC[r].y2 );
            r++;
        }
        --r;
        ver.pb( line( verNC[l].x1, verNC[l].y1, verNC[l].x1, DownY ) );
        l = ++r;
    }
}

void initHor() {
    hor.pb( line( -1, -1, -1, -1 ) );
    int n = horNC.size();
    sort( horNC.begin(), horNC.end() );
    int l, r;
    l = r = 0;
    while ( l < n ) {
        int RightX = horNC[l].x2;
        while ( r < n &&
               horNC[r].y1 == horNC[l].y1 &&
               horNC[r].x1 <= RightX ) {
            RightX = max( RightX, horNC[r].x2 );
            r++;
        }
        --r;
        hor.pb( line( horNC[l].x1, horNC[l].y1, RightX, horNC[l].y1 ) );
        l = ++r;
    }
}

void initCompr() {
    list < int > all;
    allY.pb( -1 );
    int n = ver.size();
    int j;
    for ( j = 1; j < n; j++ ) {
        all.pb( ver[j].y1 );
        all.pb( ver[j].y2 - 1 );
    }
    all.sort();
    all.unique();
    n = all.size();
    for ( j = 0; j < n; j++ ) {
        allY.pb( all.front() );
        all.pop_front();
    }
}

int findPos( int sz, int cnt ) {
    int l = 1, r = sz;
    while ( r - l > 1 ) {
        int mid = ( l + r ) >> 1;
        if ( allY[mid] < cnt )
            l = mid + 1;
        else
            r = mid;
    }
    if ( allY[r] == cnt )
        l = r;
    return l;
}

int findX( int sz, int cnt ) {
    int l = 0, r = sz - 1;
    while ( r - l > 1 ) {
        int mid = ( l + r ) >> 1;
        if ( allX[mid] >= cnt )
            r = mid - 1;
        else
            l = mid;
    }
    if ( allX[r] < cnt )
        l = r;
    return l;
}

int findTr( int sz, int cnt ) {
    int l = 0, r = sz;
    while ( r - l > 1 ) {
        int mid = ( l + r ) >> 1;
        if ( allY[mid] <= cnt )
            l = mid;
        else
            r = mid - 1;
    }
    if ( allY[r] <= cnt )
        l = r;
    return l;
}

ll calc() {
    int n = hor.size();
    ll ans = 0LL;
    for ( int j = 1; j < n; j++ )
        ans += 1LL * ( hor[j].x2 - hor[j].x1 + 1 );
    n = ver.size();
    for ( int j = 1; j < n; j++ )
        ans += 1LL * ( ver[j].y1 - ver[j].y2 + 1 );
    return ans;
}

struct node {
    node *l, *r;
    int sum;
    node( node * L, node * R, int _sum ) {
        l = L;
        r = R;
        sum = _sum;
    }
    node ( node * L, node * R ) {
        l = L;
        r = R;
        sum = 0;
        sum += L ? L -> sum : 0;
        sum += R ? R -> sum : 0;
    }
};

typedef node * pnode;

pnode build ( int tl, int tr ) {
    if ( tl == tr )
        return new node( NULL, NULL, 0 );
    int mid = ( tl + tr ) >> 1;
    return new node( build( tl, mid ), build( mid + 1, tr ), 0 );
}

pnode update ( pnode T, int tl, int tr, int pos, int cnt ) {
    if ( tl == tr )
        return new node ( NULL, NULL, T -> sum + cnt );
    int mid = ( tl + tr ) >> 1;
    if ( pos <= mid ) {
        return new node ( update( T -> l, tl, mid, pos, cnt ), T -> r );
    }
    return new node ( T -> l, update( T -> r, mid + 1, tr, pos, cnt ) );
}

int getSum ( pnode T, int tl, int tr, int ll, int rr ) {
    if ( tl == ll && tr == rr )
        return T -> sum;
    if ( ll > rr )
        return 0;
    int mid = ( tl + tr ) >> 1;
    return getSum( T -> l, tl, mid, ll, min( rr, mid ) ) +
           getSum( T -> r, mid + 1, tr, max( mid + 1, ll ), rr );
}

pnode roots[2 * maxn];

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, j;
    scanf ( "%d", &n );
    for ( j = 0; j < n; j++ ) {
        int q, w, e, r;
        scanf ( "%d%d%d%d", &q, &w, &e, &r );
//        q += inf;
//        w += inf;
//        e += inf;
//        r += inf;
        if ( w == r ) {
            horNC.pb( line( q, w, e, r ) );
        } else {
            verNC.pb( line( q, w, e, r ) );
        }
    }
    initHor();
    initVer();
    initCompr();
    ll ans = calc();
    int pdoSize = (int)allY.size() - 1;
    if ( ver.size() - 1 )
        roots[0] = build( 1, pdoSize );
    else {
        printf ( "%I64d", ans );
        return 0;
    }
    n = ver.size();
    allX.pb( - 1 );

    for ( j = 1; j < n; j++ ) {
        roots[j * 2 - 1] = update( roots[j * 2 - 2], 1,
                            pdoSize, findPos( pdoSize, ver[j].y1 ), 1 );
        roots[j * 2] = update( roots[j * 2 - 1], 1,
                            pdoSize, findPos( pdoSize, ver[j].y2 - 1 ), -1 );
        allX.pb( ver[j].x1 );
    }
    int XSize = allX.size();
    n = hor.size();
    for ( j = 1; j < n; j++ ) {
//        cout << ans << endl;
        int pos1 = 2 * findX( XSize, hor[j].x1 );
        int pos2 = 2 * findX( XSize, hor[j].x2 + 1 );
        int tr = findTr( pdoSize, hor[j].y1 - 1 );
//        cout << pos1 << ' ' << pos2 << ' ' << tr << ' ' << hor[j].y1 << endl;
        ans += 1LL * getSum( roots[pos2], 1, pdoSize, 1, tr );
        ans -= 1LL * getSum( roots[pos1], 1, pdoSize, 1, tr );
    }
//    printf ( "%I64d", ans );
    cout << ans;
    return 0;
}