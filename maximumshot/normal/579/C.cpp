#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <tuple>
#include <complex>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;

bool solve() {
    
    ld a, b;

    cin >> a >> b;

    if(a < b) {
        puts("-1");
        return true;
    }

    ld d = b, ans = 1e18;

    // k % 2 == 0

    ll k = (a - b) / (2.0 * b);

    ans = min(ans, (a - b) / ld(2 * k));

    k = (a + b) / (2.0 * b);

    ans = min(ans, (a + b) / ld(2 * k));

    cout.precision(10);
    cout << fixed;

    cout << ans << '\n';

    return true;
}

int main() {
    
    //while(solve());
    solve();  

    return 0;
}