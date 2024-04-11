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

int gcd(int x, int y) {
    return (x == 0?y : gcd(y % x, x));
}

bool solve() {
    
    int a, b, n, g;

    scanf("%d %d", &a, &b);

    g = gcd(a, b);

    vec< int > t;
    for(int i = 1;i * i <= g;i++) {
        if(g % i == 0) {
            t.push_back(i);
            t.push_back(g / i);
        }
    }

    sort(ALL(t));
    t.resize(unique(ALL(t)) - t.begin());

    scanf("%d", &n);
    int l, r, bl, br, bm, bp;

    for(;n;n--) {
        scanf("%d %d", &l, &r);
    
        bl = 0, br = (int)t.size() - 1;

        while(br - bl > 1) {
            bm = (bl + br) >> 1;
            if(t[bm] <= r) bl = bm;
            else br = bm - 1;
        }

        bp = (t[br] <= r?br : bl);

        if(l <= t[bp]) printf("%d\n", t[bp]);
        else puts("-1");
    }

    return true;
}

int main() {

    //while(solve());
    solve();

    return 0;
}