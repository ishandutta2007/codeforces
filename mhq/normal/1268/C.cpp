#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 2e5 + 100;
int p[maxN];
ll inv[maxN];
int fenw[maxN];
void upd(int v) {
    while (v <= n) {
        fenw[v]++;
        v = (v | (v - 1)) + 1;
    }
}

int get(int r) {
    int ans = 0;
    while (r > 0) {
        ans += fenw[r];
        r &= (r - 1);
    }
    return ans;
}

int get(int l, int r) {
    return get(r) - get(l - 1);
}
int pos[maxN];

multiset < int > sm, bg;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    for (int i = 1; i <= n; i++) {
        inv[i] = inv[i - 1] + get(pos[i] + 1, n);
        upd(pos[i]);
    }
    ll val = 0;
    ll sum_small = 0;
    for (int i = 1; i <= n; i++) {
        int who = pos[i];
        val += who;
        int need_size = (i + 1) / 2;
        sm.insert(who);
        sum_small += who;
        while (sm.size() > need_size) {
            auto it = (prev(sm.end()));
            bg.insert(*it);
            sum_small -= *it;
            sm.erase(*it);
        }
        while (!sm.empty() && !bg.empty()) {
            int mx1 = *(prev(sm.end()));
            int mn1 = *bg.begin();
            if (mn1 < mx1) {
                sm.erase(sm.find(mx1));
                bg.erase(bg.find(mn1));
                sm.insert(mn1);
                bg.insert(mx1);
                sum_small += mn1 - mx1;
            }
            else {
                break;
            }
        }
        ll tot = 0;
        int med = *prev(sm.end());
        int half = i / 2;
        if (i % 2 == 1) {
            tot = val - 2 * sum_small - (1LL * half * (half + 1)) + med;
        }
        else {
            tot = val - 2 * sum_small - (1LL * half * (half));
        }
        cout << tot + inv[i] << " ";
    }
    return 0;
}