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

char t[maxn];
char s[50];

int main()
{
    srand( time( 0 ) );
//    freopen( "input.txt", "r", stdin );
//    freopen( "output.txt", "w", stdout );
//    ios_base::sync_with_stdio(false);
    gets( t );
    gets( s );
    int n = strlen( t );
    int k = strlen( s );
    int ans = 0;
    for ( int j = 0; j < n - k + 1; j++ ) {
        int kol = 0;
        for ( int i = 0; i < k; i++ ) {
            kol += t[j + i] == s[i];
        }
        if ( kol == k ) {
            ans++;
            t[j + k - 1] = '#';
        }
    }
    cout << ans;
    return 0;
}