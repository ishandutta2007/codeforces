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
        
    int n, k;
    ull x;

    cin >> n >> k >> x;

    vec< ull > a(n);

    for(int y, i = 0;i < n;i++) {
        scanf("%d", &y);
        a[i] = y;
    }

    sort(ALL(a));

    vec< ull > preff(n), suff(n);

    ull t = 0;

    for(int i = 0;i < n;i++) {
        t |= a[i];
        preff[i] = t;
    }

    t = 0;
    for(int i = n - 1;i >= 0;i--) {
        t |= a[i];
        suff[i] = t;
    }

    ull ans = 0;

    for(int i = 0;i < n;i++) {
        t = 0;
        if(i > 0) t |= preff[i - 1];
        if(i + 1 < n) t |= suff[i + 1];
        ull v = a[i];
        for(int j = 0;j < k;j++) v *= x;
        t |= v;
        ans = max(ans, t);
    }

    cout << ans << '\n';

    return true;
}

int main() {
    
    //while(solve());
    solve();  

    return 0;
}