#include <iostream>
#include <fstream>
#include <stdio.h>
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
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <ctime>
#include <iterator>
#include <cstdio>


using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 105;
const int inf = 2e9;
const double eps = 1e-8;

int i[maxn][30];
string s[maxn];

vector < int > z;

bool check( int j, int a, int b ) {
    int kol2 = 0;
    for ( int l = 0; l < 30; l++ )
        kol2 += i[j][l];
    if ( kol2 - i[j][a] - i[j][b] > 0 ) return 0;
    return 1;
}

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, j, l, ans = 0, kol;
    scanf ( "%d", &n );
    for ( j = 0; j < maxn; j++ )
        for ( l = 0; l < 30; l++ )
            i[j][l] = 0;
    for ( j = 0; j < n; j++ ) {
        cin >> s[j];
        int sz = s[j].size();
        for ( l = 0; l < sz; l++ )
            i[j][s[j][l] - 'a'] = 1;
//        int kol = 0;
//        for ( l = 0; l < 30; l++ )
//            kol += i[j][l];
//        if ( kol < 3 )
        z.pb( j );
    }
    for ( j = 0; j < 26; j++ )
        for ( l = j + 1; l < 26; l++ ) {
            kol = 0;
            for ( int y = 0; y < z.size(); y++ )
                if ( check( z[y], j, l ) ) kol += s[y].size();
            ans = max( ans, kol );
        }
    printf ( "%d", ans );
    return 0;
}