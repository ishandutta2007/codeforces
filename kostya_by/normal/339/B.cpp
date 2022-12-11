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

int n, q, cur = 1;
long long ans = 0;

int fun( int a, int b )
{
	if ( a > b ) return n - a + 1 + fun( 1, b );
	return b - a;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d%d", &n, &q); 
    while ( q-- )
    {
    	int next; scanf("%d", &next);
    	ans += fun( cur, next );
    	cur = next;
    } 
    cout << ans << endl;
    return 0;
}