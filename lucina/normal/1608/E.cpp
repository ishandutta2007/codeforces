#include<bits/stdc++.h>
using namespace std;
const int nax = 2e5 + 10;


template <typename T = int>
struct Fenwick {
    vector <T> bit;
    int n;

    Fenwick(int n) : n(n) {
        bit.resize(n + 1, 0);
        n += 1;
    }

    void update(int i, T val) {
        for (; i < n ; i += i & -i) bit[i] += val;
    }

    T get(int i) {
        T res = 0;
        for (; i > 0 ; i -= i & -i) res += bit[i];
        return res;
    }

    T get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }

    int lift_idx(T k) {
        /**
         find first position which sum >= k
        */
        int cur = 0, pos = 0;
        for (int j = std::__lg(n) ; j >= 0 ; -- j) {
            if (pos + (1 << j) < n && cur + bit[pos + (1 << j)] < k) {
                pos += 1 << j;
                cur += bit[pos];
            }
        }
        return pos + (cur < k);
    }
};

int n;
int solve(vector <array <int, 3>> a) {
    sort(a.begin(), a.end());
    vector <int> com_x, com_y;
    for (int i = 0 ; i < n ; ++ i) {
        com_x.push_back(a[i][0]);
        com_y.push_back(a[i][1]);
    }
    sort(com_x.begin(), com_x.end());
    sort(com_y.begin(), com_y.end());
    com_x.erase(unique(com_x.begin(), com_x.end()), com_x.end());
    com_y.erase(unique(com_y.begin(), com_y.end()), com_y.end());
    for (int i = 0 ; i < n ; ++ i) {
        a[i][0] = lower_bound(com_x.begin(), com_x.end(), a[i][0]) - com_x.begin() + 1;
        a[i][1] = lower_bound(com_y.begin(), com_y.end(), a[i][1]) - com_y.begin() + 1;
    }
    int ans = 0;

    for (int col = 0 ; col < 3 ; ++ col) {
        vector <Fenwick<int>> f(2, Fenwick(n + 2));
        vector <Fenwick<int>> g(2, Fenwick(n + 2));
        int m = com_x.size();
        int map_to[3]{};
        map_to[col] = 2;
        map_to[(col + 1) % 3] = 1;
        map_to[(col + 2) % 3 ] = 0;
        //printf("DEBUG\n");
        for (int i = 0 ; i < n ; ++ i) {
            auto [x, y, c] = a[i];
          //  printf("x y c %d %d %d\n", x, y, c);
            c = map_to[c];
            if (c < 2) f[c].update(y, 1), g[c].update(x, 1);
        }
//        printf("_______________\n");

        int cnt_col = 0;
        for (int x = 1, ptr = 0 ; x <= m ; ++ x) {
            while (ptr < n && a[ptr][0] <= x) {
                auto [x, y, c] = a[ptr];
                c = map_to[c];
                if (c < 2) f[c].update(y, -1), g[c].update(x, -1);
                else cnt_col += 1;
                ptr ++;
            }
            if (cnt_col > 0) {
                for (int i = 0 ; i < 2 ; ++ i) {
                    if (f[i].get(n) < cnt_col) continue;
                    int where = f[i].lift_idx(cnt_col);
                    int cnt_other = f[i ^ 1].get(where + 1, n);
                    if (cnt_other >= cnt_col) {
                        ans = max(ans, 3 * cnt_col);
                    }
                }
                for (int i = 0 ; i < 2 ; ++ i) {
                    if (g[i].get(n) < cnt_col) continue;
                    int where = g[i].lift_idx(cnt_col);
                    int cnt_other = g[i ^ 1].get(where + 1, n);
                    if (cnt_other >= cnt_col)
                        ans = max(ans, 3 * cnt_col);
                }
            }
        }
    }
    return ans;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    cin >> n;
    vector <array <int, 3>> a(n);
    for (int i = 0 ; i < n ; ++ i) {
        for (int j = 0 ; j < 3 ; ++ j) {
            cin >> a[i][j];
        }
        a[i][2] -= 1;
    }
    int ans = 0;
    for (int i = 0 ; i < 2 ; ++ i) {
        ans = max(ans, solve(a)); //(x, y) (-y, -x)
        for (int j = 0 ; j < n ; ++ j) {
            swap(a[j][0], a[j][1]);
        }
        ans = max(ans, solve(a)); //(y, x) (-x, -y)
        for (int j = 0 ; j < n ; ++ j)
            a[j][0] *= -1, a[j][1] *= -1;
    }

    cout << ans << '\n';
}