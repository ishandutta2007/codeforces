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
#include <cstdio>

using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 300;
const int inf = 2e9;

string s, f = "abcdefghijklmnopqrstuvwxyz";
string e = f;
int i[maxn];

int main()
{
    srand( time( 0 ) );
//    freopen( "repair.in", "r", stdin );
//    freopen( "repair.out", "w", stdout );
    int n, m, z, j;
    scanf ( "%d%d", &n, &m );
    cin >> s;
    char we;
    scanf ( "%c", &we );
    int q = f.size();
    while ( m-- ) {
        char t, y, a, b;
        scanf ( "%c%c%c%c", &t, &a, &y, &b );
        for ( j = 0; j < q; j++ ) {
            if ( f[j] == t ) {
                f[j] = y;
                continue;
            }
            if ( f[j] == y ) {
                f[j] = t;
                continue;
            }

        }
    }
    for ( j = 0; j < n; j++ ) {
        char t = s[j];
        int l = 0;
        while ( e[l] != t ) l++;
        s[j] = f[l];
    }
    cout << s;
    return 0;
}