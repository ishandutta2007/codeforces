#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cassert>
#include <ios>

using namespace std;

#define A first
#define B second

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 100100;

int n, x1[maxn], y1[maxn], x2[maxn], y2[maxn];
vector<pii> hor[maxn], ver[maxn];

int xc[2 * maxn], yc[2 * maxn];
int xs, ys;

int xn[2 * maxn];
int bit[2 * maxn];

void upd(int i, int v) {
    for (i++; i < 2 * maxn; i += i & -i) bit[i] += v;
}

int qry(int i) {
    int ret = 0;
    for (i++; i > 0; i -= i & -i) ret += bit[i];
    return ret;
}

int getx(int x) { return lower_bound(xc, xc + xs, x) - xc; }
int gety(int y) { return lower_bound(yc, yc + ys, y) - yc; }

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
        if (y1[i] == y2[i]) {
            yc[ys++] = y1[i];
            xc[xs++] = min(x1[i], x2[i]);
            xc[xs++] = max(x1[i], x2[i]) + 1;
        } else {
            assert(x1[i] == x2[i]);
            xc[xs++] = x1[i];
            yc[ys++] = min(y1[i], y2[i]);
            yc[ys++] = max(y1[i], y2[i]) + 1;
        }
    }

    sort(xc, xc + xs); xs = unique(xc, xc + xs) - xc;
    sort(yc, yc + ys); ys = unique(yc, yc + ys) - yc;

    for (int i = 0; i < n; i++) {
        if (y1[i] == y2[i]) {
            y1[i] = gety(y1[i]);
            if (x1[i] > x2[i]) swap(x1[i], x2[i]);
            hor[getx(x1[i])].push_back(pii(y1[i], 1));
            hor[getx(x2[i] + 1)].push_back(pii(y1[i], -1));
        } else {
            x1[i] = getx(x1[i]);
            if (y1[i] > y2[i]) swap(y1[i], y2[i]);
            ver[x1[i]].push_back(pii(gety(y1[i]), 1));
            ver[x1[i]].push_back(pii(gety(y2[i] + 1), -1));
        }
    }

    for (int i = 0; i < xs; i++) {
        sort(hor[i].begin(), hor[i].end());
        sort(ver[i].begin(), ver[i].end());
    }

    ll ans = 0;
    for (int i = 0; i < xs; i++) {
        if (i) ans += ll(qry(ys)) * (xc[i] - xc[i - 1]);
        for (pii p : hor[i]) {
            int a = bool(xn[p.A]);
            xn[p.A] += p.B;
            int b = bool(xn[p.A]);
            upd(p.A + 1, b - a);
        }

        int cur = 0;
        for (int j = 0; j < ver[i].size(); j++) {
            if (j && cur) ans += yc[ver[i][j].A] - yc[ver[i][j-1].A] - (qry(ver[i][j].A) - qry(ver[i][j-1].A));
            cur += ver[i][j].B;
        }
    }

    cout << ans << '\n';
}