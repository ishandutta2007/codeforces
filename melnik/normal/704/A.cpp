#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
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

const int maxn = 300500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

int lastInter[maxn];
// int curLast = inf;
// int curFirst = inf;
int curAns = 0;
int curC = 0;
int leftType[maxn];
// int right1[maxn];
// int left1[maxn];
int a[maxn];
int maxT = 0;



void init() {
    for ( int j = 0; j < maxn; j++ )
        lastInter[j] = leftType[j] = inf;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    init();
    int n, q;
    scanf ( "%d%d", &n, &q );
    while ( q-- ) {
        int type;
        scanf ( "%d", &type );
        if ( type == 1 ) {
            int x;
            scanf ( "%d", &x );
            ++curAns;
            a[curC] = x;
            leftType[curC] = lastInter[x];
            lastInter[x] = curC;
            ++curC;
            printf ( "%d\n", curAns );
        }
        if ( type == 2 ) {
            int x;
            scanf ( "%d", &x );
            while ( lastInter[x] != inf && lastInter[x] >= maxT ) {
                int pos = lastInter[x];
                lastInter[x] = leftType[pos];
                a[pos] = inf;
                --curAns;
            }
            printf ( "%d\n", curAns );
        }
        if ( type == 3 ) {
            int x;
            scanf ( "%d", &x );
            for ( int j = maxT; j < x; j++ )
                if ( a[j] != inf ) {
                    if ( lastInter[a[j]] == j )
                        lastInter[a[j]] = inf;
                    --curAns;
                    a[j] = inf;
                }
            maxT = max( maxT, x );
            printf ( "%d\n", curAns );
        }
    }
    return 0;
}