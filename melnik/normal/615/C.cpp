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

const int maxn = 3050;
const int inf = 2e9;
const double eps = 1e-8;
const ll base = 489133282872437279LL;

string s1, s2, s3;

vector < pair < int, int > > ans;

void reverse ( string &s5 ) {
    int r = s5.size() - 1, l = 0;
    while ( l < r ) {
        swap( s5[l], s5[r] );
        l++;
        r--;
    }
}

int pref_f[4 * maxn];

void calc( string s5, int sz1, int sz2 ) {
    int n = s5.size();
    int j, i;
    pref_f[0] = 0;
    for ( j = 1; j < n; j++ ) {
        i = pref_f[j - 1];
        while ( i > 0 && s5[j] != s5[i] )
            i = pref_f[i - 1];
        if ( s5[j] == s5[i] ) i++;
        pref_f[j] = i;
    }
    int ma = 0;
    int l = 0;
    for ( j = sz1; j < n; j++ )
        if ( ma < pref_f[j] ) {
            ma = pref_f[j];
            l = j;
        }
    if ( ma == 0 ) {
        printf ( "-1" );
        exit( 0 );
    }
    if ( l < sz1 + sz2 + 2 ) {
        l -= sz1;
        int r = l - ma + 1;
        ans.pb( mp( r - 1, l - 1 ) );
        return;
    }
    l -= sz1 + sz2 + 1;
    l = sz2 - l;
    int r = l + ma - 1;
    ans.pb( mp( r, l ) );
}


int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
    ios_base::sync_with_stdio(false);
    cin >> s1 >> s2;
    int sz2 = s1.size();
    s3 = s1;
    reverse ( s3 );
    int n = s2.size();
    int l, r;
    l = 0, r = 0;
    while ( l < n ) {
        calc( s2.substr( l, n - l ) + "#" + s1 + "$" + s3, n - l, sz2 );
        l += abs ( ( ans.back() ).s - ( ans.back() ).f ) + 1;
    }
    n = ans.size();
    printf ( "%d\n", n );
    for ( int j = 0; j < n; j++ )
        printf ( "%d %d\n", ans[j].f + 1, ans[j].s + 1 );
    return 0;
}