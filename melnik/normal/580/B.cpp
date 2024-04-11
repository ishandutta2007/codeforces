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
const int maxn = 1e5;
#define f first
#define s second

ll n, d, k, r = 0, pref[maxn], kol=-2e9;
pair < ll, ll > i[maxn];

int main()
{
    cin >> n >> d;
    for ( k = 0; k < n; k++ )
        cin >> i[k].f >> i[k].s;
    sort ( i, i + n );
    pref[0] = i[0].s;
    for ( k = 1; k < n; k++ )
        pref[k] = pref[k - 1] + i[k].s;
    for ( k = 0; k < n; k++ ){
        while ( r < n && i[k].f + d > i[r].f )
            r++;
        kol = max ( kol, pref[r - 1] - pref[k] + i[k].s);
    }
    cout << kol;
    return 0;
}