#include<bits/stdc++.h>
using namespace std;
int const nax = 2e5 + 10;

struct seg_node {
    pair <int, int> mn;
    seg_node() {mn = make_pair(0, 0);}
    seg_node (pair <int, int> _mn) : mn(_mn) {}
};
seg_node operator +(const seg_node &a, const seg_node &b) {
    return seg_node(min(a.mn, b.mn));
}

seg_node sg[nax << 2];


void update(int v, int x, int y, int pos, pair <int, int> val) {
    if (x == y) {
        sg[v] = seg_node(val);
    } else {
        int mid = x + y >> 1;
        if (pos <= mid) update(v << 1, x, mid, pos, val);
        else update(v << 1 | 1, mid + 1, y, pos, val);
        sg[v] = sg[v << 1] + sg[v << 1 | 1];
    }
}

seg_node query(int v, int x, int y, int l, int r) {

    if (l == x && r == y) return sg[v];
    int mid = x + y >> 1;
    if (r <= mid) return query(v << 1, x, mid, l, r);
    if (l > mid) return query(v << 1 | 1, mid + 1, y, l, r);
    return query(v << 1, x, mid, l, mid) + query(v << 1 | 1, mid + 1, y, mid + 1, r);
}

int n, m;
int a[nax];

void solve() {
    cin >> n >> m;

    set <int> setik;

    auto is_local_min = [&](int i) -> bool {
        return query(1, 1, n, 1, i).mn == make_pair(a[i], i);
    };

    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        update(1, 1, n, i, make_pair(a[i], i));
        if (is_local_min(i)) {
            setik.insert(i);
        }
    }
    for (int i = 1 ; i <= m ; ++ i) {
        int x, d;
        cin >> x >> d;
        a[x] -= d;
        update(1, 1, n, x, make_pair(a[x], x));

        if (is_local_min(x)) {
            setik.insert(x);
        }
        auto where = next(setik.find(x));
        vector <int> to_erase;
        while (where != setik.end()) {
            int p = *where;
            if (!is_local_min(p)) to_erase.push_back(p);
            else break;
            where = next(where);

        }
        for (int j : to_erase) setik.erase(j);
        cout << setik.size() << ' ';
    }
    cout << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;

    for (cin >> T ; T -- ;) {
        solve();
    }
}