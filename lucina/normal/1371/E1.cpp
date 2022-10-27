#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;
using ll = long long;

int n, p;
ll a[nax];

bool ok (ll x) {
    for (int i = 1 ; i <= n ; ++ i) {
        if (x + i - 1 < a[i])
            return false;
    }

    return true;
}

int main () {
    scanf("%d %d", &n, &p);
    /// p is prime

    for (int i = 1 ; i <= n; ++ i) {
        scanf("%lld", a + i);
    }

    sort(a + 1, a + 1 + n);

    /**
        binary search smallest x
    */

    ll l = 1, r = 1e12, x = -1;

    while (l <= r) {
        ll mid = l + r >> 1;
        if (ok(mid)) {
            x = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    assert(x > 0);

    fprintf(stderr, "x = %lld\n", x);

    for (int i = 1 ; i <= n ; ++ i) {
        ll t = a[i];
        a[i] = n - max(0LL, t - x);
    }

    reverse(a + 1, a + 1 + n);

    for (int i = 1 ; i <= n; ++ i) {
        a[i] -= (i - 1);
    }

    reverse(a + 1, a + 1 + n);



    int lim = p - a[p];
    auto nxt_p = [&] (int f) {
        return p * ((f - 1) / p + 1);
    };
    for (int i = p + p ; i <= n ; i += p) {
        lim = min(lim, int(nxt_p(a[i]) - a[i]));
    }




    set<int> setik;

    for (int j = 0 ; j < lim ; ++ j)
        setik.insert(j);


    for (int j = 1 ; j <= n ; ++ j) {
        if (j % p == 0) continue;
        int q = nxt_p(a[j]);
        if (q > j) continue;
        int to = a[j] + lim - 1;
        if (q >= a[j] && to >= q) {
            int w = q - a[j];
            if (setik.find(w) != setik.end())
                setik.erase(setik.find(w));
        }
    }

    printf("%d\n", int(setik.size()));

    for (int i : setik)
        printf("%d ", x + i);

}
/*
    Song of leaving home.
*/