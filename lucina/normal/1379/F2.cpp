#include<bits/stdc++.h>
using namespace std;
int const nax = 4e5 + 10;

struct node_t {
    int lowest_L;
    int highest_R;
    bool result;

    node_t (int lowest_L = nax, int highest_R = -1, bool result = false) :
        lowest_L(lowest_L), highest_R(highest_R) , result(result) {}
};

node_t operator + (const node_t &l, const node_t &r) {
    node_t res;
    res.result = l.result | r.result;
    if (l.lowest_L <= r.highest_R) res.result = true;
    res.lowest_L = min(l.lowest_L, r.lowest_L);
    res.highest_R = max(l.highest_R, r.highest_R);
    return res;
}

node_t sg[nax << 2];

set <int> keep[nax];

void update (int v, int x, int y, int pos) {
    if (x == y) {
        node_t& a = sg[v];
        if (pos % 2) {
            a = node_t(keep[x].empty() ? nax : *keep[x].begin(), -1, false);
        } else {
            a = node_t(nax, keep[x].empty() ? -1 : *keep[x].rbegin(), false);
        }
    } else {
        int mid = x + y >> 1;
        if (pos <= mid) update(v << 1, x, mid, pos);
        else update(v << 1 | 1, mid + 1, y, pos);
        sg[v] = sg[v << 1] + sg[v << 1 | 1];
    }
}

int n, m, q;

int main () {
    cin.tie(0)->sync_with_stdio(false);

    cin >> n >> m >> q;

    for (; q -- ;) {
        int x, y;
        cin >> x >> y;
        if (keep[x].count(y)) {
            keep[x].erase(keep[x].find(y));
        } else keep[x].insert(y);
        update(1, 1, 2 * n, x);

        cout << (sg[1].result ? "NO" : "YES") << '\n';
    }
}
/*
    not ryza again.
*/