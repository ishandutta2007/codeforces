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

std::vector< int > a;

bool prime ( int x ) {
	for ( int j = 2; j < x; j++ )
		if ( x % j == 0 )
			return 0;
	return 1;
}

int used[maxn];

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    for ( int j = 2; j <= 100; j++ )
    	if ( prime( j ) )
    		a.pb( j );
    int sz = a.size();
    int cnt = 0;
    string t;
    int cur;
    for ( int j = 0; j < sz && a[j] <= 50; j++ ) {
    	cout << a[j] << endl;
    	cin >> t;
    	if ( t == "yes" ) {
    		++cnt;
    		cur = a[j];
    	}
    	if ( cnt >= 2 ) {
    		cout << "composite" << endl;
    		return 0;
    	}
    }
    if ( cnt == 1 ) {
    	if ( cur * cur <= 100 ) {
    		cout << cur * cur << endl;
    		cin >> t;
    		if ( t == "yes" ) {
    			cout << "composite" << endl;
    			return 0;
    		}
    	}
    }
    cout << "prime" << endl;

    // for ( int j = 0; j < sz && a[j] <= 50; j++ ) {
    // 	cout << a[j] << endl;
    // 	cin >> t;
    // 	if ( t == "yes" ) {
    // 		cout << "composite" << endl;
    // 		return 0;
    // 	}
    // }
    // cout << "prime" << endl;
    return 0;
}