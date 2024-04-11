#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <complex>
#include <ios>
#include <iomanip>

using namespace std;

typedef long double ld;
typedef complex<ld> pnt;

const int maxn = 1<<19;
const ld PI = acos(-1.0);

int n, m;
pnt T[2 * maxn], L[2 * maxn];

void init(int cur, int lt, int rt) {
    L[cur] = pnt(1, 0);
    if (lt + 1 == rt) T[cur] = pnt(1, 0);
    else {
        int mid = (lt + rt) / 2;
        init(2 * cur, lt, mid);
        init(2 * cur + 1, mid, rt);
        T[cur] = T[2 * cur] + T[2 * cur + 1];
    }
}

void push(int cur, int lt, int rt) {
    T[cur] *= L[cur];
    if (lt + 1 != rt) {
        L[2 * cur] *= L[cur];
        L[2 * cur + 1] *= L[cur];
    }
    L[cur] = 1;
}

void updl(int cur, int lt, int rt, int p, int v) {
    if (lt + 1 == rt) {
        ld len = abs(T[cur]);
        T[cur] *= (len + v) / len;
    } else {
        int mid = (lt + rt) / 2;
        push(2 * cur, lt, mid);
        push(2 * cur + 1, mid, rt);
        if (p < mid) updl(2 * cur, lt, mid, p, v);
        else updl(2 * cur + 1, mid, rt, p, v);
        T[cur] = T[2 * cur] + T[2 * cur + 1];
    }
}

void updr(int cur, int lt, int rt, int ql, int qr, int v) {
    push(cur, lt, rt);
    if (rt <= ql || lt >= qr) return;
    else if (lt >= ql && rt <= qr) {
        L[cur] = pnt(cos(v * PI / 180), -sin(v * PI / 180));
        push(cur, lt, rt);
    } else {
        int mid = (lt + rt) / 2;
        updr(2 * cur, lt, mid, ql, qr, v);
        updr(2 * cur + 1, mid, rt, ql, qr, v);
        T[cur] = T[2 * cur] + T[2 * cur + 1];
    }
}

int main() {
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    init(1, 0, n);

    for (int i = 0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        y--;
        if (x == 1) updl(1, 0, n, y, z);
        else updr(1, 0, n, y, n, z);
        cout << fixed << setprecision(10) << T[1].real() << ' ' << T[1].imag() << '\n';
    }
}