#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cassert>
#include <stack>
#include <bitset>
#include <sstream>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, m, cost[ 1111 ];
vector< int > graph[ 1111 ];
bool used[ 1111 ];

int main (int argc, const char * argv[])
{
    cin >> n >> m;
    for ( int i = 1; i <= n; i++ ) cin >> cost[i];
    for ( int i = 1; i <= m; i++ )
    {
        int x, y; cin >> x >> y;
        graph[x].pb(y);
        graph[y].pb(x);
    }
    long long answer = 0;
    for ( int it = 1; it <= n; it++ )
    {
        int pos = -1;
        for ( int i = 1; i <= n; i++ )
        {
            if ( used[i] ) continue;
            if ( pos == -1 ) pos = i;
            if ( cost[i] > cost[pos] ) pos = i;
        }
        for ( int i = 0; i < graph[pos].size(); i++ )
            if ( !used[ graph[pos][i] ] )
                answer += cost[ graph[pos][i] ];
        used[pos] = true;
    }
    cout << answer << "\n";
    return 0;
}