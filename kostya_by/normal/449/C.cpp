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

int n;
bool prime[ 100100 ], taken[ 100100 ];
vector< int > primes;
vector< pair< int, int > > answer; 

void process( int i )
{
    vector< int > numbers;
    for ( int j = i; j <= n; j += i ) 
        if ( !taken[ j ] )
            numbers.push_back( j );
    if ( numbers.size() % 2 == 0 )
    {
        for ( int i = 1; i < numbers.size(); i += 2 )
        {
            taken[ numbers[ i - 1 ] ] = taken[ numbers[ i ] ] = true;
            answer.push_back( make_pair( numbers[ i - 1 ], numbers[ i ] ) );
        }
    } else
    {
        if ( i != 2 )
        {
            taken[ numbers[ 0 ] ] = taken[ numbers[ 2 ] ] = true;
            answer.push_back( make_pair( numbers[ 0 ], numbers[ 2 ] ) );
            for ( int i = 4; i < numbers.size(); i += 2 )
            {
                taken[ numbers[ i - 1 ] ] = taken[ numbers[ i ] ] = true;
                answer.push_back( make_pair( numbers[ i - 1 ], numbers[ i ] ) );
            }
        } else
        {
            numbers.pop_back();
            for ( int i = 1; i < numbers.size(); i += 2 )
            {
                taken[ numbers[ i - 1 ] ] = taken[ numbers[ i ] ] = true;
                answer.push_back( make_pair( numbers[ i - 1 ], numbers[ i ] ) );
            }
        }
    }
}

int main (int argc, const char * argv[])
{
    scanf("%d", &n);

    for ( int i = 2; i <= n; i++ )
        for ( int j = i + i; j <= n; j += i ) 
            prime[ j ] = true;

    for ( int i = 3; i <= n / 2; i++ ) if ( !prime[i] ) process( i );

    if ( 2 <= n / 2 ) process( 2 );

    cout << answer.size() << "\n";
    for ( int i = 0; i < answer.size(); i++ ) printf("%d %d\n", answer[i].first, answer[i].second);

    return 0;
}