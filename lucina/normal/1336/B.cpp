#include<bits/stdc++.h>
using namespace std;
int const nax = 3e5 + 10;


using ll = long long ;
const ll inf = 1e17;

int r[nax], g[nax], b[nax];
int nr, ng, nb;

int bs (int * x, int val, int sz) {
    int l = 1, r = sz;

    int ans = -1;

    while (l <= r) {
        int mid = l + r >> 1;
        if (x[mid] <= val) {
            ans = mid;
            l = mid + 1;
        } else r = mid - 1;
    }

    return ans;
}

int bs_gt (int * x, int val, int sz) {
    int l = 1, r = sz;

    int ans = -1;

    while (l <= r) {
        int mid = l + r >> 1;
        if (x[mid] >= val) {
            ans = mid;
            r = mid - 1;
        } else l = mid + 1;
    }

    return ans;
}

ll sq (ll x) {
    return x * x;
}

ll calc (ll a, ll b, ll c) {
    return sq(a - b) + sq(b - c) + sq(c - a);
}

ll solve() {
    scanf("%d %d %d", &nr, &ng, &nb);

    for (int i = 1 ; i <= nr ; ++ i)
        scanf("%d", r + i);

    for (int i = 1 ; i <= ng ; ++ i)
        scanf("%d", g + i);

    for (int i = 1 ; i <= nb ; ++ i)
        scanf("%d", b + i);

    sort(r + 1, r + nr + 1);
    sort(g + 1, g + ng + 1);
    sort(b + 1, b + nb + 1);

    /// if r is greatest

    ll ans = LLONG_MAX;

    for (int i = 1 ; i <= nr ; ++ i) {
        int x, y;

        x = bs(g, r[i], ng);
        y = bs_gt(b, r[i], nb);

        if (x != -1 && y != -1) {
            ans = min(ans, calc(r[i], g[x], b[y]));
        }

        x = bs_gt(g, r[i], ng);
        y = bs(b, r[i], nb);

        if (x != -1 && y != -1) {
            ans = min(ans, calc(r[i], g[x], b[y]));
        }
    }

    /// green as middle

    for (int i = 1 ; i <= ng ; ++ i) {
        int x, y;

        x = bs(r, g[i], nr);
        y = bs_gt(b, g[i], nb);

        if (x != -1 && y != -1) {
            ans = min(ans, calc(g[i], r[x], b[y]));
        }

        x = bs_gt(r, g[i], nr);
        y = bs(b, g[i], nb);

        if (x != -1 && y != -1) {
            ans = min(ans, calc(g[i], r[x], b[y]));
        }
    }

    for (int i = 1 ; i <= nb ; ++ i) {
        int x, y;

        x = bs(r, b[i], nr);
        y = bs_gt(g, b[i], ng);

        if (x != -1 && y != -1) {
            ans = min(ans, calc(b[i], r[x], g[y]));
        }

        x = bs_gt(r, b[i], nr);
        y = bs(g, b[i], ng);

        if (x != -1 && y != -1) {
            ans = min(ans, calc(b[i], r[x], g[y]));
        }
    }


    return ans;

}

int main () {
    int T;

    for (scanf("%d", &T) ; T -- ;) {
        printf("%lld\n", solve());
    }
}
/*
    Good Luck
        -Lucina
*/