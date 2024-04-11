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

int isPrime[maxn];

void eratosthene() {
	for ( int j = 0; j < maxn; j++ )
		isPrime[j] = true;
	for ( int j = 2; j < maxn; j++ ) 
		if ( isPrime[j] )
			for ( int i = j; 1LL * i * j < maxn; i++ )
				isPrime[i * j] = false;
}

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    eratosthene();
    int n;
    scanf ( "%d", &n );
    if ( n < 3 )
    	printf ( "1\n" );
    else
    	printf ( "2\n" );
    for ( int j = 2; j <= n + 1; j++ )
    	printf ( "%d ", isPrime[j] ? 1 : 2 );
    return 0;
}