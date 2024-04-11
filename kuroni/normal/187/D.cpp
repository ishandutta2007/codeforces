#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

const int N = 1E5 + 5, INF = 1E9 + 7;

int n, g, r, q, u, cyc;
long long sum[N], tim[N];

struct SCover {
    int l, r, ind;

    SCover(int _l = 0, int _r = 0, int _ind = 0) : l(_l), r(_r), ind(_ind) {}

    inline bool operator<(const SCover &oth) const {
        return l != oth.l ? l < oth.l : r < oth.r;
    }
};
set<SCover> seg;

void add_segment(SCover u) {
    if (u.l > u.r) {
        add_segment(SCover(u.l, cyc - 1, u.ind));
        add_segment(SCover(0, u.r, u.ind));
        return;
    }
    auto it = seg.upper_bound(u);
    if (it != seg.begin()) {
        it = prev(it);
    }
    while (it != seg.end()) {
        if (it->r < u.l) {
            it = next(it);
        } else if (it->l > u.r) {
            break;
        } else {
            SCover tmp = *it;
            it = seg.erase(it);
            if (tmp.l < u.l) {
                seg.insert(SCover(tmp.l, u.l - 1, tmp.ind));
            } else if (tmp.r > u.r) {
                seg.insert(SCover(u.r + 1, tmp.r, tmp.ind));
            }
        }
    }
    seg.insert(u);
}

int index(int u) {
    auto it = seg.upper_bound(SCover(u, INF, 0));
    if (it == seg.begin()) {
        return -1;
    } else {
        it = prev(it);
        if (it->l <= u && u <= it->r) {
            return it->ind;
        } else {
            return -1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> g >> r;
    cyc = g + r;
    for (int i = 0; i <= n; i++) {
        cin >> sum[i + 1];
        sum[i + 1] += sum[i];
    }
    for (int i = n; i >= 1; i--) {
        int tmp = ((-sum[i] % cyc) + cyc) % cyc;
        int ind = index(tmp);
        if (ind == -1) {
            tim[i] = sum[n + 1] - sum[i];
        } else {
            tim[i] = ((sum[ind] - sum[i] - 1) / cyc + 1) * cyc + tim[ind];
        }
        add_segment(SCover((g + tmp) % cyc, (cyc - 1 + tmp) % cyc, i));
    }
    cin >> q;
    while (q--) {
        cin >> u;
        long long ans = u - u % cyc; u %= cyc;
        int ind = index(u);
        if (ind == -1) {
            ans += u + sum[n + 1];
        } else {
            ans += ((u + sum[ind] - 1) / cyc + 1) * cyc + tim[ind];
        }
        cout << ans << '\n';
    }
}