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
const int maxn = 1e5+5;

#define f first
#define s second
#define pb push_back

vector < int > rebra[maxn];
int i[maxn], cats[maxn], m, kol = 0;

void dfs ( int v, int pr ){
    int sz = rebra[v].size();
    if ( i[v] == 1 ) cats[v] = cats[pr]+1;
    if ( cats[v] > m ) cats[v] = 2e9;
    if ( cats[pr] == 2e9 ) cats[v] = 2e9;
    if ( sz == 1 && v != 1) {
        if ( cats[v] < 2e9 ) kol++;
        return ;
    }
    for ( int k = 0; k < sz; k++ )
        if ( rebra[v][k] != pr ) dfs ( rebra[v][k], v );
}

int main()
{
    int n, k, x, y;
    cin >> n >> m;
    cats[0] = 0;
    for ( k = 1; k <= n; k++ ){
        cin >> i[k];
        cats[k] = 0;
    }
    for ( k = 1; k < n; k++ ){
        cin >> x >> y;
        rebra[x].pb( y );
        rebra[y].pb( x );
    }
    dfs( 1, 0 );
    cout << kol;
    return 0;
}