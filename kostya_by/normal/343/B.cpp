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

char st[ 100100 ];
int n;
vector< char > s;

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    gets( st ); n = strlen( st );
    for ( int i = 0; i < n; i++ )
    {
    	if ( s.size() > 0 && s.back() == st[i] )
    	{
    		s.pop_back();
    		continue;
    	}
    	s.push_back( st[i] ); 
    }
    if ( s.size() == 0 ) puts("Yes"); else puts("No");
    return 0;
}