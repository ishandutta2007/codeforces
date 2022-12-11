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

int k, n[ 3 ], t[ 3 ], _time[ 3 ][ 1111 ], answer = 0;

int main (int argc, const char * argv[])
{
	cin >> k; 
    for ( int i = 0; i < 3; i++ ) cin >> n[i];
    for ( int i = 0; i < 3; i++ ) cin >> t[i];
    for ( int i = 0; i < k; i++ )
    {
        int current_time = 0;
        for ( int j = 0; j < 3; j++ )
        {
            int earlier_id = 0;
            for ( int k = 0; k < n[j]; k++ )
                if ( _time[j][k] < _time[j][ earlier_id ] )
                    earlier_id = k;
            current_time = max( current_time, _time[j][ earlier_id ] ) + t[j];
        }
        answer = current_time;
        for ( int j = 2; j >= 0; j-- )
        {
            int earlier_id = 0;
            for ( int k = 0; k < n[j]; k++ )
                if ( _time[j][k] < _time[j][ earlier_id ] )
                    earlier_id = k;
            _time[j][ earlier_id ] = current_time;
            current_time -= t[j];
        }
    }
    cout << answer << "\n";
    return 0;
}