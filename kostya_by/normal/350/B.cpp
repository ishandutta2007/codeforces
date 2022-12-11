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
#include <stack>
#include <bitset>
#include <fstream>

typedef unsigned long long ull;
#define mp make_pair
#define pb push_back

const long double eps = 1e-9;
const double pi = acos(-1.0);
const long long inf = 1e18;

using namespace std;

int n, tp[ 100100 ], dist[ 100100 ], p[ 100100 ];
vector< int > graf[ 100100 ], inv[ 100100 ];
queue< int > q;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ ) 
    {
    	scanf("%d", &tp[i]);
    	dist[i] = -1;
    	if ( tp[i] == 1 ) q.push( i ), dist[i] = 0;
    }
    for ( int i = 1; i <= n; i++ )
    {
    	int v1 = i, v2; scanf("%d", &v2);
    	if ( v2 == 0 ) continue;
    	graf[v1].pb( v2 );
    	inv[v2].pb( v1 );
    }
    while ( q.size() )
    {
    	int v = q.front(); q.pop();
    	for ( int i = 0; i < graf[v].size(); i++ )
    	{
    		int next = graf[v][i];
    		if ( inv[next].size() > 1 ) continue;
    		dist[next] = dist[v] + 1;
    		p[next] = v;
    		q.push( next ); 
    	}
    }
    int mx = -1, v = -1;
    for ( int i = 1; i <= n; i++ ) if ( dist[i] > mx ) mx = dist[i], v = i;
    vector< int > ans;
    while ( tp[v] != 1 )
    {
    	ans.pb( v );
    	v = p[v];
    }
    ans.pb( v );
    cout << ans.size() << endl;
    for ( int i = 0; i < ans.size(); i++ ) printf("%d ", ans[i]);
    return 0;
}