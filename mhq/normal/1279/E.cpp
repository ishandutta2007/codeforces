#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
ll k;
const int maxN = 52;
ll ways[maxN];
ll fact[maxN];
int p[maxN];
bool used[maxN];
bool was[maxN];
const ll INF = 2e18;
ll safe_mult(ll a, ll b) {
    if (a == 0 || b == 0) return 0;
    if (a > (INF + b - 1) / b) return INF;
    return a * b;
}
ll safe_sum(ll a, ll b) {
    ll s = a + b;
    if (s >= INF) return INF;
    return s;
}
ll go(int cut) {
    for (int i = 0; i < n; i++) {
        used[i] = false;
        was[i] = false;
    }
    for (int i = 0; i <= cut; i++) {
        if (used[p[i]]) return 0;
        used[p[i]] = true;
    }
    int cur = 0;
    ll coef = 1;
    while (true) {
        int at_most = p[cur];
        for (int j = cur; j <= at_most && j <= cut; j++) {
            if (p[j] > at_most) return 0;
        }
        if (at_most <= cut) {
            int vis = 1;
            int who = p[cur];
            while (who != cur) {
                vis++;
                who = p[who];
            }
            if (vis != at_most - cur + 1) return 0;
            cur = at_most + 1;
            if (cur > cut) {
                return safe_mult(coef, ways[n - cut - 1]);
            }
        }
        else {
            // at_most > cut
            for (int j = cur; j <= cut; j++) {
                if (was[j]) continue;
                int gg = j;
                while (!was[gg]) {
                    if (gg > cut) break;
                    was[gg] = true;
                    gg = p[gg];
                    if (gg == j) return 0;
                }
            }
            int comps = (at_most - cut);
            coef = safe_mult(coef, fact[comps - 1]);
            coef = safe_mult(coef, ways[n - at_most - 1]);
            return coef;
        }
    }

}
void solve() {
    cin >> n >> k;
    if (k > ways[n]) {
        cout << -1 << '\n';
        return ;
    }
    k--;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            p[i] = j;
            ll tot = go(i);
            if (k >= tot) {
                k -= tot;
            }
            else {
                break;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << p[i] + 1 << " ";
    }
    cout << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    fact[0] = 1;
    for (int i = 1; i < maxN; i++) fact[i] = safe_mult(i, fact[i - 1]);
    ways[0] = 1;
    ways[1] = 1;
    for (int i = 2; i < maxN; i++) {
        ways[i] = ways[i - 1];
        for (int take = 2; take <= i; take++) {
            ways[i] = safe_sum(ways[i], safe_mult(fact[take - 2], ways[i - take]));
        }
    }
    int tst;
    cin >> tst;
    while (tst--) solve();
    return 0;
}