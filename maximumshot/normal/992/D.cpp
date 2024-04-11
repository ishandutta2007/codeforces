#ifdef debug
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) begin(x), end(x)

typedef unsigned int ui;
typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< long long, long long > pll;

const int inf = 1e9;
const ll inf64 = 1e18;

const int N = 2e5 + 5;

int n, k;
int a[N];
vec< int > p;

int main() {

#ifdef debug
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &k);

    p.push_back(0);

    ll res = 0;

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        if(a[i] > 1) p.push_back(i);
        else if(k == 1) res++;
    }

    p.push_back(n + 1);

    for(int rit = 0;rit + 1 < (int)p.size();rit++) {
        double big_mul = 1.0;
        ll mul = 1;
        ll sum = 0;
        for(int lit = rit - 1;lit >= 0;lit--) {
            mul *= a[p[lit + 1]];
            big_mul *= a[p[lit + 1]];
            if(big_mul > 4e18) break;
            sum += a[p[lit + 1]];
            if(lit + 2 <= rit) sum += p[lit + 2] - p[lit + 1] - 1;
            if(mul % k) continue;
            ll x = mul / k - sum;
            ll hl = p[lit + 1] - p[lit] - 1;
            ll hr = p[rit + 1] - p[rit] - 1;
            if(x < 0 || x > hl + hr) continue;
            ll tl = max(0ll, x - hr);
            ll tr = min(hl, x);
            if(tl <= tr)
            res += tr - tl + 1;
        }
    }

    printf("%lld\n", res);

    return 0;
}