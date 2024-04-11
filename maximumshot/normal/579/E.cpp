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

#include <time.h>

using namespace std;

#define vec vector
#define mp make_pair
#define mt make_tuple
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll inf = 1000000000ll;
const ll inf64 = inf * inf;

vec< ld > a, b;
int n;

ld A(ld x) {
    return (x < 0?-x : x);
}

ld f(ld x) {
    b = a;
    for(int i = 1;i <= n;i++) b[i] = ld(a[i] - x);
    
    vec< ld > mx(n + 1, 0), mn(n + 1, 0);
    ld ans = -1e18;
    ld sum = 0;
    for(int i = 1;i <= n;i++) {
        sum += b[i];
        ans = max(ans, A(sum - mx[i - 1]));
        ans = max(ans, A(sum - mn[i - 1]));
        mx[i] = max(mx[i - 1], sum);
        mn[i] = min(mn[i - 1], sum);
    }
    return ans;
}

bool solve() {

    scanf("%d", &n);

    a.resize(n + 1);
    for(int i = 1;i <= n;i++) {
        int x;
        scanf("%d", &x);
        a[i] = x;
    }

    ld l, r, m1, m2, ans = 1e18;

    l = -1e5;
    r = +1e5;

    ld t = clock();

    while((double)clock() - t < 1.9 * CLOCKS_PER_SEC && r - l > 1e-12) {
        m1 = l + (r - l) / 3.0;
        m2 = r - (r - l) / 3.0;
        ld v1, v2;
        v1 = f(m1);
        v2 = f(m2);
        if(v1 <= v2) r = m2;
        else l = m1;
    }

    ans = f((l + r) / 2.0);

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