#include <iostream>
#include <stdio.h>
#include <math.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <tuple>
#include <stack>
#include <set>
#include <map>
#include <queue>

using namespace std;

#define vec vector
#define mp make_pair
#define mt make_tuple
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;

bool solve() {

    int n, ans = 0;

    cin >> n;

    for(int i = 0;(1 << i) <= n;i++) {
        if((1 << i) & n) ans++;
    } 

    cout << ans << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}