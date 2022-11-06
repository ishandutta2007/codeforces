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

int main()
{
    int n, t;
    cin >> n >> t;
    if ( n == 1 && t < 10 ){
        cout << t;
        return 0;
    } else {
        if ( n == 1 ) {cout << -1;
        return 0;}
    }
    cout << t;
    if ( t == 10 ) t = 2; else t = 1;
    for ( ; n > t; n-- )
        cout << 0;
    return 0;
}