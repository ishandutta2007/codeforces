#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

inline ll f(ll x) {
    return (x >= 0?x : -x);
}

int const N = 200005;

bool solve() {

    int n, k, x;
    ll a[N];

    scanf("%d %d %d", &n, &k, &x);

    int fl = 0;

    set< pair< ll, int > > q;

    for(int y, i = 0;i < n;i++) {
        scanf("%d", &y);
        a[i] = y;
        if(a[i] < 0) fl ^= 1;
        q.insert({f(y), i});
    }

    for(int iter = 0;iter < k;iter++) {
        int id = q.begin()->second;
        q.erase(q.begin());
        if(fl) {
            if(a[id] >= 0) a[id] += x;
            else a[id] -= x;
        }else {
            if(a[id] >= 0) a[id] -= x, fl ^= (a[id] < 0);
            else a[id] += x, fl ^= (a[id] >= 0);
        }
        q.insert({f(a[id]), id});
    }

    for(int i = 0;i < n;i++) {
        printf("%I64d ", a[i]);
    }

    printf("\n");

    return true;
}

int main() {

#ifdef MY
    while(solve());
#else
    solve();
#endif

    return 0;
}