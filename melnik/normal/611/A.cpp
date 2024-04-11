#include <iostream>
#include <fstream>
#include <list>
#include <stack>
#include <deque>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <ext\hash_set>
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

string e;

int main()
{
    srand( time( 0 ) );
   // freopen( "input.txt", "r", stdin );
  //  freopen( "output2.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    int n, j;
    cin >> n;
    n--;
    cin >> e;
    cin >> e;
    if ( e[0] == 'w' ) {
        int day = 3;
        int ans = 0;
        for ( j = 0; j < 366; j++ ) {
            day++;
            day %= 7;
            if ( day == n ) ans++;
        }
        cout << ans;
        return 0;
    }

    n++;
    if ( n <= 29 ) {
        cout << 12;
        return 0;
    }
    if ( n == 30 ) {
        cout << 11;
        return 0;
    }
    if ( n == 31 ) {
        cout << 7;
        return 0;
    }
    return 0;
}