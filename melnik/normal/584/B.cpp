#include <iostream>
#include <fstream>
#include <stdio.h>
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
#include <cstdlib>
#include <algorithm>
#include <math.h>
#include <iomanip>
#include <time.h>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const ll inf = 1e9 + 7;

ll bin ( ll zn, ll st ) {
	if ( st == 0 )
		return 1;
	if ( st % 2 == 1 )
		return bin ( zn, st - 1 ) * zn % inf;
	else {
		ll b = bin ( zn, st / 2 );
		return b * b % inf;
	}
}
int main()
{
    int n, z = 1;
    ll kol = 0, prev;
    cin >> n;
    kol = 20 * bin( 27, n - 1 );
    n--;
    while ( n-- ){
        kol += ( bin( 7, z ) * 20 ) % inf * bin ( 27, n ) % inf;
        kol %= inf;
        z++;
    }
    cout << kol;
    return 0;
}