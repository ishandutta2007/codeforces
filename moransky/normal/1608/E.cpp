// Skyqwq
#include <bits/stdc++.h>

#define pb push_back
#define fi first
#define se second
#define mp make_pair

using namespace std;

typedef pair<int, int> PII;
typedef long long LL;

template <typename T> bool chkMax(T &x, T y) { return (y > x) ? x = y, 1 : 0; }
template <typename T> bool chkMin(T &x, T y) { return (y < x) ? x = y, 1 : 0; }

template <typename T> void inline read(T &x) {
    int f = 1; x = 0; char s = getchar();
    while (s < '0' || s > '9') { if (s == '-') f = -1; s = getchar(); }
    while (s <= '9' && s >= '0') x = x * 10 + (s ^ 48), s = getchar();
    x *= f;
}

const int N = 3e5 + 5;

int n, t[3], ans, p[3], m, ret[N];
 
struct E{
    int x, y, id;
} e[3][N], g[3][N], px[3][N], py[3][N];

bool inline cmpX(E a, E b) {
    return a.x < b.x;
}

bool inline cmpY(E a, E b) {
    return a.y < b.y;
}

void inline tr(int k) {
    for (int i = 1; i <= k; i++)
        ret[i] = g[0][i].id;
    int p = g[0][k].x + 1, cnt = 0, U, D; 
    for (int i = 1; i <= m; i++) {
        if (g[1][i].x >= p) {
            cnt++;
            ret[cnt + k] = g[1][i].id;
            if (cnt == k) break;
        }
    }
    cnt = 0;
    for (int i = m; i; i--) {
        if (g[2][i].x >= p) {
            cnt++;
            D = g[2][i].y;
            ret[cnt + k * 2] = g[2][i].id;
            if (cnt == k) break;
        }
    }
}


bool inline chk(int k) {
    int p = g[0][k].x + 1;
    int U, D, cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (g[1][i].x >= p) {
            cnt++;
            U = g[1][i].y;
            if (cnt == k) break;
        }
    }
    if (cnt != k) return 0;
    cnt = 0;
    for (int i = m; i; i--) {
        if (g[2][i].x >= p) {
            cnt++;
            D = g[2][i].y;
            if (cnt == k) break;
        }
    }
    if (cnt != k) return 0;
    return U < D;
}



void inline solve() {
    for (int i = 1; i <= m; i++) {
        g[0][i] = px[p[0]][i];
        g[1][i] = py[p[1]][i];
        g[2][i] = py[p[2]][i];
    }
    //sort(g[0] + 1, g[0] + 1 + m, cmpX);
    //sort(g[1] + 1, g[1] + 1 + m, cmpY);
    //sort(g[2] + 1, g[2] + 1 + m, cmpY);
    int l = ans, r = m;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (chk(mid)) l = mid;
        else r = mid - 1;
    }
    if (chk(r) && chkMax(ans, r))
        tr(r);
}

void inline tr2(int k) {
    int p = g[0][k].x + 1, q = g[2][m - k + 1].x - 1;
    for (int i = 1; i <= k; i++)
        ret[i] = g[0][i].id, ret[i + k] = g[2][m - k + i].id;
    int U, D, cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (g[1][i].x >= p && g[1][i].x <= q) {
            cnt++;
            ret[cnt + k * 2] = g[1][i].id;
            if (cnt == k) break;
        }
    }
}


bool inline ck2(int k) {
    int p = g[0][k].x + 1, q = g[2][m - k + 1].x - 1;
    int U, D, cnt = 0;
    for (int i = 1; i <= m; i++) {
        if (g[1][i].x >= p && g[1][i].x <= q) {
            cnt++;
            if (cnt == k) break;
        }
    }
    if (cnt != k) return 0;
    return 1;
}

void inline solve2() {
    //sort(g[0] + 1, g[0] + 1 + m, cmpX);
    //sort(g[1] + 1, g[1] + 1 + m, cmpX);
    //sort(g[2] + 1, g[2] + 1 + m, cmpX);
    for (int i = 1; i <= m; i++) {
        g[0][i] = px[p[0]][i];
        g[1][i] = px[p[1]][i];
        g[2][i] = px[p[2]][i];
    }
    int l = ans, r = m;
    while (l < r) {
        int mid = (l + r + 1) >> 1;
        if (ck2(mid)) l = mid;
        else r = mid - 1;
    }
    if (ck2(r) && chkMax(ans, r))
        tr2(r);
}


void inline work() {
    for (int i = 0; i < 3; i++) {
        sort(px[i] + 1, px[i] + 1 + m, cmpX);
        sort(py[i] + 1, py[i] + 1 + m, cmpY);
    }
    p[0] = 0, p[1] = 1, p[2] = 2;
    do {
        solve();
    } while (next_permutation(p, p + 3));
}

void inline WK() {
    for (int i = 0; i < 3; i++) {
        sort(px[i] + 1, px[i] + 1 + m, cmpX);
        sort(py[i] + 1, py[i] + 1 + m, cmpY);
    }
    p[0] = 0, p[1] = 1, p[2] = 2;
    do {
        solve2();
    } while (next_permutation(p, p + 3));
}

void inline dododo() {
    for (int i = 0; i < 3; i++) {
        sort(px[i] + 1, px[i] + 1 + m, cmpX);
        sort(py[i] + 1, py[i] + 1 + m, cmpY);
    }
    WK();
    work();
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < 3; j++)
            px[j][i].x *= -1, py[j][i].x *= -1;
    work();
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < 3; j++)
            px[j][i].y *= -1, py[j][i].y *= -1;
    work();
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < 3; j++)
            px[j][i].x *= -1, py[j][i].x *= -1;
    work();
}

int main() {
   read(n); m = n / 3;
    for (int i = 1; i <= n; i++) {
        int x, y, c; read(x), read(y), read(c);
        c--;
        e[c][++t[c]] = (E) { x, y, i };
    }
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < 3; j++)
            px[j][i] = py[j][i] = e[j][i];
    
    dododo();

    for (int i = 1; i <= m; i++)
        for (int j = 0; j < 3; j++)
            swap(e[j][i].x, e[j][i].y);
    for (int i = 1; i <= m; i++)
        for (int j = 0; j < 3; j++)
            px[j][i] = py[j][i] = e[j][i];
    dododo();
    printf("%d\n", ans * 3);
    //for (int i = 1; i <= ans * 3; i++) printf("%d ", ret[i]);
    return 0;
}