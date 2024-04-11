#include <bits/stdc++.h>
using namespace std;

const int N = 100005, D = 350;

int n, w, a, b, mx = 0;
long long coe[N];
vector<int> eve[N];

struct line {
    int a;
    long long b;

    line(int _a = 0, long long _b = 0) : a(_a), b(_b) {}

    long long at(int x) {
        return 1LL * a * x + b;
    }

    double intersect(const line &oth) const {
        return 1.0 * (b - oth.b) / (oth.a - a);
    }
};

struct convex_hull {
    vector<line> con;
    int opt, pt;

    void push(line cur) {
        while (con.size() >= 2 && con[con.size() - 2].intersect(cur) <= con[con.size() - 2].intersect(con.back())) {
            con.pop_back();
        }
        con.push_back(cur);
    }

    pair<long long, int> get_ans() {
        while (pt + 1 < con.size() && con[pt].at(opt) <= con[pt + 1].at(opt)) {
            pt++;
        }
        return {con[pt].at(opt), con[pt].a};
    }

    void build(int l, int r) {
        con.clear(); pt = 0;
        for (int i = l; i < r; i++) {
            push(line(i, coe[i]));
        }
    }
} cht[D];

int get_index(int u) {
    return u / D;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> w;
    for (int i = 0; i < n; i++) {
        cin >> a >> b; ++b;
        mx = max(b, mx);
        eve[b].push_back(a);
    }
    for (int i = 0; i < N; i += D) {
        cht[i / D].build(i, min(i + D, N));
    }
    for (int i = 0; i <= mx; i++) {
        for (int &v : eve[i]) {
            n--;
            int ind = v / D;
            for (int j = 0; j < ind; j++) {
                cht[j].opt++;
            }
            for (int j = ind * D; j <= v; j++) {
                coe[j] += j;
            }
            cht[ind].build(ind * D, min((ind + 1) * D, N));
        }
        pair<long long, int> ans = {-1, 0};
        for (int j = 0; j < N; j += D) {
            ans = max(ans, cht[j / D].get_ans());
        }
        cout << ans.first + 1LL * i * n * w << " " << ans.second << '\n';
    }
}