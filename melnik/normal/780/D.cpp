#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 1005;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

pair < pair < string, string >, int > a[maxn];
set < string > used;
string ans[maxn];

int main()
{
    srand( time( NULL ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio( false );
    int n;
    cin >> n;
    for ( int j = 0; j < n; j++ ) {
        cin >> a[j].f.f >> a[j].f.s;
        a[j].f.f = a[j].f.f.substr( 0, 3 );
        a[j].s = j;
    }
    sort( a, a + n );
//    for ( int j = 0; j < n; j++ ) {
//        cout << a[j].f.f << ' ' << a[j].f.s << ' ' << a[j].s << endl;
//    }
    int l, r;
    l = r = 0;
    while ( l < n ) {
        while ( r < n && a[l].f.f == a[r].f.f )
            ++r;
        if ( r - l == 1 ) {
            l = r;
            continue;
        }
        for ( int j = l; j < r; j++ ) {
            string newS = a[j].f.f.substr( 0, 2 ) + a[j].f.s.substr( 0, 1 );
            if ( used.find( newS ) != used.end() ) {
                puts( "NO" );
                return 0;
            }
            used.insert( newS );
            int pos = a[j].s;
            ans[pos] = newS;
        }
        l = r;
    }
    int cur = 1;
    while ( cur ) {
        cur = 0;
        l = r = 0;
        while ( l < n ) {
            while ( r < n && a[l].f.f == a[r].f.f )
                ++r;
            if ( r - l > 1 ) {
                l = r;
                continue;
            }
            int pos = a[l].s;
            if ( ans[pos] != "" ) {
                l = r;
                continue;
            }
            string newS = a[l].f.f;
            if ( used.find( newS ) != used.end() ) {
                newS = a[l].f.f.substr( 0, 2 ) + a[l].f.s.substr( 0, 1 );
                if ( used.find( newS ) != used.end() ) {
                    puts( "NO" );
                    return 0;
                }
                ans[pos] = newS;
                used.insert( newS );
                ++cur;
            }
            l = r;
        }
    }
    l = r = 0;
    while ( l < n ) {
        while ( r < n && a[l].f.f == a[r].f.f )
            ++r;
        if ( r - l > 1 ) {
            l = r;
            continue;
        }
        int pos = a[l].s;
        if ( ans[pos] != "" ) {
            l = r;
            continue;
        }
        string newS = a[l].f.f;
        if ( used.find( newS ) != used.end() ) {
            newS = a[l].f.f.substr( 0, 2 ) + a[l].f.s.substr( 0, 1 );
            if ( used.find( newS ) != used.end() ) {
                puts( "NO" );
                return 0;
            }
            ans[pos] = newS;
            used.insert( newS );
        } else {
            ans[pos] = newS;
            used.insert( newS );
        }
        l = r;
    }
    puts( "YES" );
    for ( int j = 0; j < n; j++ )
        cout << ans[j] << endl;
    return 0;
}