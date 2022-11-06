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

pair < string, string > cur;
string a;

int main()
{
    srand( time( 0 ) );
    // freopen( "input.txt", "r", stdin );
    // freopen( "output.txt", "w", stdout );
    // ios_base::sync_with_stdio(false);
    cin >> cur.f >> cur.s;
    int n;
    cin >> n;
    cout << cur.f << ' ' << cur.s << endl;
    while ( n-- ) {
    	cin >> a;
    	if ( cur.f == a )
    		cur.f = "";
    	else
    		cur.s = "";
    	cin >> a;
    	if ( cur.f == "" )
    		cur.f = a;
    	else
    		cur.s = a;
    	cout << cur.f << ' ' << cur.s << endl;
    }
    return 0;
}