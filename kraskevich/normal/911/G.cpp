#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;

const int N = 101;
const int B = 300;

struct Block {
    list<int> ps[N];
    int l;
    int r;

    void move(int ql, int qr, int x, int y) {
        if (x == y || qr < l || r < ql)
            return;
        if (ql <= l && r <= qr)
            ps[y].splice(ps[y].end(), ps[x]);
        else
            for (auto it = ps[x].begin(); it != ps[x].end();) {
                auto cur = it++;
                if (ql <= *cur && *cur <= qr)
                    ps[y].splice(ps[y].end(), ps[x], cur);
            }
    }
};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a)
        cin >> x;
    vector<Block> bs;
    for (int i = 0; i < n; i += B) {
        Block b;
        b.l = i;
        b.r = min(n - 1, i + B - 1);
        for (int j = i; j < min(n, i + B); j++)
            b.ps[a[j]].insert(b.ps[a[j]].end(), j);
        bs.push_back(b);
    }
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r, x, y;
        cin >> l >> r >> x >> y;
        for (auto& b : bs)
            b.move(l - 1, r - 1, x, y);
    }
    vector<int> ans(n);
    for (const auto& b : bs)
        for (int i = 0; i < N; i++)
            for (int p : b.ps[i])
                ans[p] = i;
    for (int x : ans)
        cout << x << " ";
    cout << endl;
}