#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;
struct fenwick {
    int n;
    vector <int> bit;
    fenwick(int n):  n(n), bit(n + 1, 0) {}
    void update(int pos, int val) {
        for (; pos <= n ; pos += pos & -pos) bit[pos] += val;
    }
    int sum(int pos) {
        int res = 0;
        for (; pos > 0 ; pos -= pos & -pos) res += bit[pos];
        return res;
    }
    int sum(int l, int r) {
        return sum(r) - (l > 0 ? sum(l - 1) : 0);
    }
};

int n, q;


int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n >> q;
    fenwick sum_x(n), sum_y(n);
    vector <int> cnt_x(n + 1), cnt_y(n + 1);

    while (q -- ) {
        int t; cin >> t;
        if (t == 3) {
            int x1, x2, y1, y2;
            cin >> x1 >> y1 >> x2 >> y2;
            bool sum = (sum_x.sum(x1, x2) == x2 - x1 + 1) || (sum_y.sum(y1, y2) == y2 - y1 + 1);
            cout << (!sum ? "No" : "Yes") << '\n';
        } else {
            int x, y;
            cin >> x >> y;
            if (t == 2) t = -1;
            cnt_x[x] += t;
            cnt_y[y] += t;
            if (cnt_x[x] == 0) sum_x.update(x, -1);
            if (t == 1 && cnt_x[x] == 1) sum_x.update(x, 1);
            if (cnt_y[y] == 0) sum_y.update(y, -1);
            if (t == 1 && cnt_y[y] == 1) sum_y.update(y, 1);
        }
    }
}