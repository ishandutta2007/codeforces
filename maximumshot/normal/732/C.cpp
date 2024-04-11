#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()
#define mp make_pair
#define mt make_tuple

typedef pair< int, int > pii;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

bool solve() {

    vec<ll> a(3);

    ll n = 0;

    for (int i = 0; i < 3; i++) {
        cin >> a[i];
        n = max(n, a[i]);
    }

    ll res = -1, nn = n;
    for(int delt = -2;delt <= 2;delt++) {
        n = nn + delt;
        if(n <= 0) continue;
        if (n == 1) {
            int ok = 1;
            for(int j = 0;j < 3;j++) {
                if(a[j] > 1) ok = 0;
            }
            if(ok) {
                int le = 4;
                int ri = -4;
                int tot = 0;
                for (int j = 0; j < 3; j++)
                    if (a[j] == 1)
                        le = min(le, j),
                                ri = max(ri, j), tot++;
                if (res == -1 || res > ri - le + 1 - tot) res = ri - le + 1 - tot;
            }
        } else {
            for (int i = 0; i <= 3; i++) {
                for (int j = 0; j <= 3; j++) {
                    vec<ll> b(3);
                    for (int it = 0; it < 3; it++)
                        b[it] = n - 2;
                    for (int it = i; it < 3; it++) {
                        b[it]++;
                    }
                    for (int it = 0; it <= j; it++) {
                        if (it < 3)
                            b[it]++;
                    }
                    int ok = 1;
                    for (int it = 0; it < 3; it++) {
                        if (b[it] < a[it]) ok = 0;
                    }
                    if (ok) {
                        ll tot = 0;
                        for (int it = 0; it < 3; it++) tot += b[it] - a[it];
                        if (res == -1 || res > tot)
                            res = tot;
                    }
                }
            }
        }
    }

    cout << res << "\n";

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