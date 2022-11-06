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

const int maxn = 1000500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int a[maxn];
bool used[maxn] = { false };

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n;
    scanf ( "%d", &n );
    int l = 0, r = n - 1;
    int cnt = 1;
    for ( int j = 0; j < maxn; j++ )
        a[j] = -1;
    while ( l < r ) {
        a[l] = a[r] = cnt;
        used[cnt] = true;
        cnt += 2;
        l++;
        r--;
    }
    cnt = 2;
    l = n, r = 2 * n - 2;
    while ( l < r ) {
        a[l] = a[r] = cnt;
        used[cnt] = true;
        cnt += 2;
        l++;
        r--;
    }
    int j = 1;
    while ( j < 2 * n && used[j] ) j++;
    if ( j != 2 * n ) {
        for ( int y = 0; y < 2 * n; y++ )
            if ( a[y] == -1 ) a[y] = j;
    }
    for ( j = 0; j < 2 * n; j++ )
        printf ( "%d ", a[j] );
    return 0;
}