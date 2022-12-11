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

int n, m, k, ii, jj;
char st[ 505 ][ 505 ];
bool used[ 505 ][ 505 ];
int dx[4] = {1, -1, 0, 0 };
int dy[4] = {0,  0,-1, 1 };

void dfs( int ii, int jj )
{
    used[ii][jj] = true;
    for ( int k = 0; k < 4; k++ )
    {
        int i = ii + dx[k];
        int j = jj + dy[k];
        if ( i < 0 || i >= n ) continue;
        if ( j < 0 || j >= m ) continue;
        if ( st[i][j] == '#' ) continue;
        if ( used[i][j] == true ) continue;
        dfs( i, j );
    }
    if ( k > 0 ) st[ii][jj] = 'X', k--;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d%d\n", &n, &m, &k);
    for ( int i = 0; i < n; i++ )
    {
        gets( st[i] );
        for ( int j = 0; j < m; j++ )
        {
            if ( st[i][j] == '.' ) ii = i, jj = j;
        }   
    }
    dfs( ii, jj );
    for ( int i = 0; i < n; i++ ) puts( st[i] );
    return 0;
}