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

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    long long a, b, ans = 0; cin >> a >> b;
    while ( true )
    {
    	if ( a > b )
    	{
    		swap( a, b );
    		continue;
    	}
    	if ( a == 0 ) break;
    	ans += b / a;
    	b %= a;
    } 
    cout << ans << endl;
    return 0;
}