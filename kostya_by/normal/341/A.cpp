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

int n, a[ 100100 ];
long long sum, ff;

long long gcd( long long a, long long b )
{
	if ( a != 0 ) return gcd( b % a, a ); else return b;
}

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    scanf("%d", &n);
    for ( int i = 1; i <= n; i++ ) scanf("%d", &a[i]);
    sort( a + 1, a + n + 1 );
	for ( int i = 1; i <= n; i++ )
	{
		long long num = i - 1;
		ff += num * a[i] - sum;
		sum += a[i];
	}
	ff += ff;
	for ( int i = 1; i <= n; i++ ) ff += a[i];
	long long gg = n;
	long long dd = gcd( ff, gg );
	cout << ff / dd << " " << gg / dd << endl;
    return 0;
}