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

const int maxn = 2000000;
const int inf = 2e9;

ll z[maxn];

int main()
{
    int n, a, i, ans = 0;
    scanf ( "%I64d", &n );
    for ( i = 0; i < maxn; i++ )
        z[i] = 0;
    for ( i = 0; i < n; i++ ) {
        scanf ( "%d", &a );
        z[a]++;
    }
    for ( i = 0; i < maxn; i++ ) {
        z[i + 1] += z[i] / 2;
        z[i] %= 2;
    }
    for ( i = 0; i < maxn; i++ )
        ans += z[i];
    printf ( "%d", ans );
    return 0;
}