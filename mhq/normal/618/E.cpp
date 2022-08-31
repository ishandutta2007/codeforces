#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const ld pi = acos(-1.0);
const int maxN = 3 * (int)1e5 + 100;
ld X[4 * maxN], Y[4 * maxN];
int add[4 * maxN];
int n, m;
void build(int v, int tl, int tr) {
    if (tl == tr) {
        X[v] = 1; Y[v] = 0;
        return;
    }
    int tm = (tl + tr) / 2;
    build(2 * v, tl, tm);
    build(2 * v + 1, tm + 1, tr);
    X[v] = X[2 * v] + X[2 * v + 1];
    Y[v] = Y[2 * v] + Y[2 * v + 1];
}

// cos(ang) -sin(ang)      X
void process(int v, int ang) {
    ld real_ang = ang * pi / 180;
    ld nX = X[v] * cos(real_ang) + Y[v] * sin(real_ang);
    ld nY = -X[v] * sin(real_ang) + Y[v] * cos(real_ang);
    X[v] = nX; Y[v] = nY;
}

void push(int v, int tl, int tr) {
    process(v, add[v]);
    if (tl != tr) {
        add[2 * v] += add[v];
        add[2 * v] %= 360;
        add[2 * v + 1] += add[v];
        add[2 * v + 1] %= 360;
    }
    add[v] = 0;
}
void upd(int v, int tl, int tr, int l, int r, int ang) {
    if (l <= tl && tr <= r) {
        add[v] += ang;
        add[v] %= 360;
        push(v, tl, tr);
        return;
    }
    push(v, tl, tr);
    if (tl > r || tr < l) return;
    int tm = (tl + tr) / 2;
    upd(2 * v, tl, tm, l, r, ang);
    upd(2 * v + 1, tm + 1, tr, l, r, ang);
    X[v] = X[2 * v] + X[2 * v + 1];
    Y[v] = Y[2 * v] + Y[2 * v + 1];
}

void updLen(int v, int tl, int tr, int pos, int by) {
    push(v, tl, tr);
    if (pos < tl || pos > tr) return;
    if (tl == tr) {
        ld len = sqrt(X[v] * X[v] + Y[v] * Y[v]);
        X[v] /= len; X[v] *= (len + by);
        Y[v] /= len; Y[v] *= (len + by);
        return;
    }
    int tm = (tl + tr) / 2;
    updLen(2 * v, tl, tm, pos, by);
    updLen(2 * v + 1, tm + 1, tr, pos, by);
    X[v] = X[2 * v] + X[2 * v + 1];
    Y[v] = Y[2 * v] + Y[2 * v + 1];
}

int len[maxN], ang[maxN];
void stupidLen(int x, int y) {
    len[x] += y;
}
void stupidAng(int x, int phi) {
    for (int i = x; i <= n; i++) {
        ang[i] += phi;
    }
}
pair < ld, ld > calc() {
    ld totX = 0; ld totY = 0;
    for (int i = 1; i <= n; i++) {
        totX += len[i] * cos(ang[i] * pi / 180);
        totY += len[i] * sin(-ang[i] * pi / 180);
    }
    return {totX, totY};
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    build(1, 1, n);
    for (int i = 1; i <= n; i++) len[i] = 1;
    while (m--) {
        int tp, y, z;
        cin >> tp >> y >> z;
        if (tp == 1) {
            updLen(1, 1, n, y, z);
            //stupidLen(y, z);
        }
        else {
            upd(1, 1, n, y, n, z);
            //stupidAng(y, z);
        }
        //assert(abs(X[1] - calc().first) < 1e-4);
        //assert(abs(Y[1] - calc().second) < 1e-4);
        cout << fixed << setprecision(10) << X[1] << " " << Y[1] << '\n';
    }
    return 0;
}