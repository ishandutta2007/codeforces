#include <bits/stdc++.h>

using namespace std;

const int N = 100005, P = 257, M = 1e9 + 7;

int lazy[3 * N];
int tree[3 * N];
char tab[N];
int n, m, k;
int what, d, a, b;
int pot[N], oneHash[N];

void build(int node, int a, int b) {
    if (a == b) {
        tree[node] = tab[a];
        lazy[node] = -1;
        return;
    }
    lazy[node] = -1;
    build(2 * node, a, (a + b) / 2);
    build(2 * node + 1, (a + b) / 2 + 1, b);
    tree[node] = ((long long)tree[2 * node] * pot[(b - a + 1) / 2] + tree[2 * node + 1]) % M;
}

void update(int node, int a, int b, int x, int y, int value) {
    if (lazy[node] != -1) {
        tree[node] = (long long)oneHash[b - a + 1] * lazy[node] % M;
        if (a < b) {
            lazy[2 * node] = lazy[node];
            lazy[2 * node + 1] = lazy[node];
        }
        lazy[node] = -1;
    }
    if (x > b || y < a) {
        return;
    }
    if (x <= a && b <= y) {
        tree[node] = (long long)oneHash[b - a + 1] * value % M;
        if (a < b) {
            lazy[2 * node] = value;
            lazy[2 * node + 1] = value;
        }
    } else {
        update(2 * node, a, (a + b) / 2, x, y, value);
        update(2 * node + 1, (a + b) / 2 + 1, b, x, y, value);
        tree[node] = ((long long)tree[2 * node] * pot[(b - a + 1) / 2] + tree[2 * node + 1]) % M;
    }
}

int intersection(int x, int y, int a, int b) {
    if (y < a || x > b) {
        return 0;
    }
    return min(y, b) - max(x, a) + 1;
}

int query(int node, int a, int b, int x, int y) {
    if (lazy[node] != -1) {
        tree[node] = (long long)oneHash[b - a + 1] * lazy[node] % M;
        if (a < b) {
            lazy[2 * node] = lazy[node];
            lazy[2 * node + 1] = lazy[node];
        }
        lazy[node] = -1;
    }
    if (x > b || y < a) {
        return 0;
    }
    if (x <= a && b <= y) {
        return tree[node];
    } else {
        int r1 = query(2 * node, a, (a + b) / 2, x, y);
        int r2 = query(2 * node + 1, (a + b) / 2 + 1, b, x, y);

        return ((long long)r1 * pot[intersection(x, y, (a + b) / 2 + 1, b)] + r2) % M;
    }
}

int getHash(int from, int to) {
    if (to < from) {
        return 0;
    }
    int x = query(1, 0, (1 << 17) - 1, from, to);
    return x;
}

void insert(int d, int from, int to) {
    update(1, 0, (1 << 17) - 1, from, to, d);
}

int main() {

    scanf("%d %d %d", &n, &m, &k);
    m += k;
    scanf("%s", &tab[1]);

    for (int i = 1; i <= n; i++) {
        tab[i] -= 48;
    }

    pot[0] = 1;
    for (int i = 1; i <= n; i++) {
        pot[i] = (long long)pot[i - 1] * P % M;
    }

    oneHash[1] = 1;
    for (int i = 2; i <= n; i++) {
        oneHash[i] = ((long long)oneHash[i - 1] * P + 1) % M;
    }

    build(1, 0, (1 << 17) - 1);

    for (int i = 1; i <= m; i++) {
        scanf("%d %d %d %d", &what, &a, &b, &d);
        if (what == 1) {
            insert(d, a, b);
        } else {
            printf(getHash(a, b - d) == getHash(a + d, b) ? "YES\n" : "NO\n");
        }
    }

    return 0;
}