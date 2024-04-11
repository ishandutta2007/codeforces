#include <bits/stdc++.h>
using namespace std;
struct qu{
    int xa, ya, xb, yb, id;
};
int n, m, q;
char a[505][505];
vector < qu > t;
bool ans[6 * (int)1e5 + 5];
bitset < 505 > dpl[505][505];
bitset < 505 > dpr[505][505];
bitset < 505 > nu;
void solve (vector < qu > t, int l, int r) {
    if (l > r) return ;
    int mid = (l + r) / 2;
    for (int i = 1; i <= n; i++) {
        for (int j = l; j <= mid; j++) {
            dpl[i][j] &= nu;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = mid; j <= r; j++) {
            dpr[i][j] &= nu;
        }
    }
    vector < qu > t1, t2, t3;
    for (int i = 0; i < t.size(); i++) {
        if (t[i].yb < mid) {
            t1.push_back(t[i]);
        }
        else if (t[i].ya > mid) {
            t2.push_back(t[i]);
        }
        else t3.push_back(t[i]);
    }
    for (int i = 1; i <= n; i++) {
        if (a[i][mid] == '.') {
            dpr[i][mid][i] = 1;
            dpr[i][mid] |= dpr[i - 1][mid];
        }
    }
    for (int i = n; i >= 1; i--) {
        if (a[i][mid] == '.') {
            dpl[i][mid][i] = 1;
            dpl[i][mid] |= dpl[i + 1][mid];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = mid + 1; j <= r; j++) {
            if (a[i][j] == '.')
                dpr[i][j] = dpr[i - 1][j] | dpr[i][j - 1];
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = mid - 1; j >= l; j--) {
            if (a[i][j] == '.') dpl[i][j] = dpl[i + 1][j] | dpl[i][j + 1];
        }
    }
    for (int i = 0; i < t3.size(); i++) {
        int xa = t3[i].xa; int ya = t3[i].ya;
        int xb = t3[i].xb; int yb = t3[i].yb;
        int id = t3[i].id;
        ans[id] = (dpl[xa][ya] & dpr[xb][yb]).any();
    }
    solve(t1, l, mid - 1);
    solve(t2, mid + 1, r);
}
int main() {
    ios_base::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    cin >> q;
    for (int i = 1; i <= q; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        qu s = qu{a, b, c, d, i};
        t.push_back(s);
    }
    solve(t, 1, m);
    for (int i = 1; i <= q; i++) {
        if (ans[i] == true) {
            cout << "Yes" << '\n';
        }
        else cout << "No" << '\n';
    }
    return 0;
}