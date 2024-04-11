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

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple 

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;
const ll base = inf + 7;
const ld pi = 3.1415926535897932384626433832795;

int n, ans = 0;
vec< int > a;

void go(int v) {
    if(2 * v + 1 <= n) {
    
        go(v << 1);
        go(v << 1 | 1);

        int t = max(a[v << 1], a[v << 1 | 1]);

        a[v << 1] = a[v << 1 | 1] = 0;
        a[v] = max(a[v] - t, 0);

        ans += t;
    }
}

bool solve() {
    
    scanf("%d", &n);

    a.resize(n + 1);

    if(n < 3 || n % 2 == 0) {
        puts("-1");
        return true;
    }

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
    }

    go(1);

    cout << ans + a[1] << '\n';

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}