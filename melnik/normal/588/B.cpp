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

using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 1000100;
const int inf = 2e9;

ll z[maxn];

void prost ( ll n ) {
    ll q = sqrt( n );
    for ( int i = 2; i <= q; i++ ){
        z[i] = 0;
        while ( n % (ll)i == 0 ){
            z[i]++;
            n /= i;
        }
    }
    z[1] = n;
}

int main()
{
    ll n, ans = 1;
    scanf ( "%I64d", &n );
    prost ( n );
    ans = z[1];
    for ( int i = 2; i <= sqrt( n ); i++ )
        if ( z[i] != 0 ) ans = ans * i;
    printf ( "%I64d", ans );
    return 0;
}