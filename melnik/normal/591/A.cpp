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

const int maxn = 100500;
const int inf = 2e9;

int main()
{
    srand( time( 0 ) );
//    freopen( "repair.in", "r", stdin );
//    freopen( "repair.out", "w", stdout );
    int l, p, q;
    scanf ( "%d%d%d", &l, &p, &q );
    cout << setprecision(30) << (ld) l / (ld)( p + q ) * (ld)p;
//    double z;
//    scanf ( "%G", &z );
//    printf ( "%", z );
    return 0;
}