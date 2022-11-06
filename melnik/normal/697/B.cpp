#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <ctime>
#include <iterator>
#include <cstdio>
#include <cstring>
#include <cstdlib>


using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 100500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

char t[maxn];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    char cur = ' ';
    int cnt = 0;
    while ( cur != 'e' ) {
    	cur = getchar();
    	if ( cur != 'e' )
    		t[cnt++] = cur;
    }
    while ( t[cnt - 1] == '0' )
    	t[--cnt] = '\0';
    int x;
    int pos;
    scanf ( "%d", &x );
    for ( int j = 0; j < cnt; j++ )
    	if ( t[j] == '.' )
    		pos = j;
    while ( x-- ) {
    	swap( t[pos], t[pos + 1] );
    	++pos;
    }
    if ( pos >= cnt - 1 )
    	cnt = pos;
   	for ( int j = 0; j < cnt; j++ )
   		if ( t[j] == '\0' )
   			putchar( '0' );
   		else
   			putchar( t[j] );
   	puts( "" );
    return 0;
}