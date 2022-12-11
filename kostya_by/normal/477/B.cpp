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

int n, k;


void solve()
{
    cin >> n >> k;
    cout << k * ( 6 * n - 1 ) << "\n";
    for ( int i = 0; i < n; i++ ) cout << k * ( 6 * i + 1 ) << " " << k * ( 6 * i + 2 ) << " " << k * ( 6 * i + 3 ) << " " << k * ( 6 * i + 5 ) << "\n";   
}

int main (int argc, const char * argv[])
{
    time_t start = clock();
    int t = 1;
    for ( int i = 0; i < t; i++ ) solve();
    cerr << fixed << setprecision( 6 ) << "Time: " << 1.0 * ( clock() - start ) / CLOCKS_PER_SEC << "\n";
    return 0;
}