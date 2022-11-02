#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#include <ios>

using namespace std;

const int maxn = 1<<17;
const int inf = 1e9;

int n, a[maxn], b[maxn], c[maxn], d[maxn];
int sx[maxn], cx, sy[maxn], cy;

vector<int> tree[2 * maxn];
int mi[2 * maxn];

queue<int> que;
int par[maxn];

void add(int cur, int lt, int rt, int i) {
    if (lt + 1 == rt) {
        tree[cur].push_back(i);
        mi[cur] = min(mi[cur], b[i]);
    } else {
        int mid = (lt + rt) / 2;
        if (a[i] < mid) add(2 * cur, lt, mid, i);
        else add(2 * cur + 1, mid, rt, i);
        mi[cur] = min(mi[2 * cur], mi[2 * cur + 1]);
    }
}

bool cmp(int i1, int i2) {
    return b[i1] > b[i2];
}

void upd(int cur, int lt, int rt, int i) {
    //cout << cur << ' ' << lt << ' ' << rt << ' ' << i << ' ' << mi[cur] << ' ' << c[i] << ' ' << d[i] << endl;
    if (lt >= c[i]) return;
    if (mi[cur] >= d[i]) return;

    if (lt + 1 == rt) {
        //cout << tree[cur].size() << ' ' << tree[cur].back() << endl;
        while (!tree[cur].empty() && b[tree[cur].back()] < d[i]) {
            //cout << tree[cur].back() << endl;
            par[tree[cur].back()] = i;
            que.push(tree[cur].back());
            tree[cur].pop_back();
        }
        mi[cur] = tree[cur].empty() ? inf : b[tree[cur].back()];
    } else {
        int mid = (lt + rt) / 2;
        upd(2 * cur, lt, mid, i);
        upd(2 * cur + 1, mid, rt, i);
        mi[cur] = min(mi[2 * cur], mi[2 * cur + 1]);
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    sx[cx++] = 0, sy[cy++] = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i] >> d[i];
        sx[cx++] = a[i];
        sy[cy++] = b[i];
    }

    sort(sx, sx + cx);
    cx = unique(sx, sx + cx) - sx;

    sort(sy, sy + cy);
    cy = unique(sy, sy + cy) - sy;

    for (int i = 0; i < 2 * maxn; i++) mi[i] = inf;

    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(sx, sx + cx, a[i]) - sx;
        b[i] = lower_bound(sy, sy + cy, b[i]) - sy;
        c[i] = upper_bound(sx, sx + cx, c[i]) - sx;
        d[i] = upper_bound(sy, sy + cy, d[i]) - sy;

        add(1, 0, cx, i);
    }

    for (int i = 0; i < 2 * maxn; i++)
        sort(tree[i].begin(), tree[i].end(), cmp);

    c[n] = d[n] = 1;
    que.push(n);
    memset(par, -1, sizeof(par));
    while (!que.empty()) {
        int x = que.front(); que.pop();
        upd(1, 0, cx, x);
    }

    if (par[n - 1] == -1) {
        cout << "-1\n";
        return 0;
    }

    vector<int> ans;
    int cur = n - 1;
    while (cur != n) {
        ans.push_back(cur);
        cur = par[cur];
    }

    cout << ans.size() << '\n';
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] + 1 << ' ';
    cout << '\n';
}