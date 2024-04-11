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
const long long mod = 1000000007;

using namespace std;

int n, a[ 2020 ], cnt1 = 0, cnt2 = 0;
long long f[ 2020 ], ans = 1, g[ 2020 ][ 2020 ];
bool used[ 2020 ];

int main (int argc, const char * argv[])
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    cin >> n;
    for ( int i = 1; i <= n; i++ ) 
    {
    	cin >> a[i];
    	if ( a[i] != -1 ) used[ a[i] ] = true;
    }
	for ( int i = 1; i <= n; i++ )
	{
		if ( used[i] == false && a[i] == -1 ) cnt1++;
		if ( used[i] == false && a[i] != -1 ) cnt2++;
	}
	long long ans1 = 0;
	f[0] = 1;
	f[1] = 0;
	f[2] = 1;
	f[3] = 2;
	for ( int i = 4; i <= n; i++ ) 
	{
		long long a = i;
		f[i] = ( (i - 1) * ( f[i - 1] + f[i - 2] ) ) % mod;
	}
	for ( int i = 0; i <= cnt1; i++ ) g[i][0] = f[i];
	for ( int i = 1; i <= cnt2; i++ ) g[0][i] = ( g[0][i - 1] * i ) % mod;
	for ( int i = 1; i <= cnt1; i++ )
		for ( int j = 1; j <= cnt2; j++ )
		{
			g[i][j] += g[i][j - 1] * j + g[i - 1][j] * i;
			g[i][j] %= mod;
		}
	cout << g[cnt1][cnt2] << endl;
    return 0;
}