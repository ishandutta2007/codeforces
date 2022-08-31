#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 2e6 + 10;
int n;
int a[maxN];
int nxt[maxN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i == 1 || a[i] != a[i - 1]) {
            nxt[a[i]] = i;
        }
    }
    nxt[maxN - 1] = n + 1;
    for (int i = maxN - 2; i >= 0; i--) {
        if (nxt[i] == 0) {
            nxt[i] = nxt[i + 1];
        }
    }
    ll M = 2;

    while (a[1] < (M - 1) * (M - 1)) M++;
    for (;; M++) {
        ll at_least = 0;
        ll at_most = 1e18;
        int ptr = 1;
        ll cur = M;
        while (true) {
            int nptr;
            if (a[n] < a[ptr] + cur) {
                nptr = n + 1;
            } else {
                nptr = nxt[a[ptr] + cur];
            }
            //ptr .. nptr - 1 in cur
            at_least = max(at_least, (cur - 1) * (cur - 1) - a[ptr]);
            at_most = min(at_most, (cur - 1) * cur - a[nptr - 1]);
            if (at_least > at_most) break;
            if (nptr == n + 1) {
                ptr = n + 1;
                break;
            }
            ll d = a[nptr] - a[nptr - 1];
            d -= (cur - 1);
            while (d > 2 * (cur)) {
                d -= (2 * (cur));
                cur++;
            }
            cur++;
            ptr = nptr;
        }
        if (ptr == n + 1) {
            cout << at_least << '\n';
            break;
        }
    }
    return 0;
}