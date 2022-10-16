#include <bits/stdc++.h>

using namespace std;

///vl bai gi day
///doi ti minh ve ra
///de bai ambiguous vl
///hinh nhu thu tu thuc hien eo quan trong lam :|

pair <int, int> d[] = { {0, -1}, {0, 1}, {-1, 0}, {1, 0} };
int n, t;
int cnt[5005][5005];
int offs = 2505;

pair <int, int> operator + (pair <int, int> a, pair <int, int> b) {
    return {a.first + b.first, a.second + b.second};
}

int main(void) {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> t;
    cnt[offs][offs] = n;
    queue <pair <int, int> > todo;
    if (n >= 4) todo.push({0, 0});
    int mx = 0;
    while (!todo.empty()) {
        auto x = todo.front(); todo.pop();
        mx = max(mx, x.first);
        if (cnt[x.first+offs][x.second+offs] >= 4) {
            int add = cnt[x.first+offs][x.second+offs] / 4;
            cnt[x.first+offs][x.second+offs] %= 4;
            for (int i = 0; i < 4; ++i) {
                auto y = x + d[i];
                cnt[y.first+offs][y.second+offs] += add;
                if (cnt[y.first+offs][y.second+offs] >= 4 && cnt[y.first+offs][y.second+offs] - add < 4) todo.push(y);
            }
        }
    }
    while (t--) {
        int x, y;
        cin >> x >> y;
        x+=offs; y+=offs;
        if (x < 0 || x > 5000 || y < 0 || y > 5000) cout << 0 << '\n';
        else cout << (cnt[x][y]) << '\n';
    }
    return 0;
}

///