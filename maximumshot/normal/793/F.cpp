#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e5 + 5;
int const SQRT = 320;

int n, m;
vec< int > g[N];
vec< int > tree[4 * N];

void merge(int v) {
    int ls = (int)tree[v * 2 + 1].size();
    int rs = (int)tree[v * 2 + 2].size();
    int i = 0;
    int j = 0;
    while(i < ls && j < rs) {
        if(tree[v * 2 + 1][i] < tree[v * 2 + 2][j]) {
            tree[v].push_back(tree[v * 2 + 1][i++]);
        }else {
            tree[v].push_back(tree[v * 2 + 2][j++]);
        }
    }
    while(i < ls) {
        tree[v].push_back(tree[v * 2 + 1][i++]);
    }
    while(j < rs) {
        tree[v].push_back(tree[v * 2 + 2][j++]);
    }
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        tree[v] = g[tl];
    }else {
        int tm = (tl + tr) / 2;
        build(v * 2 + 1, tl, tm);
        build(v * 2 + 2, tm + 1, tr);
        merge(v);
    }
}

int get(int v, int tl, int tr, int l, int r, int x) {
    if(l <= tl && tr <= r) {
        int idx = upper_bound(ALL(tree[v]), x) - tree[v].begin() - 1;
        if(idx >= 0 && idx < (int)tree[v].size()) {
            return tree[v][idx];
        }else {
            return -1;
        }
    }else {
        int tm = (tl + tr) / 2;
        int res = -1;
        if(l <= tm) {
            res = max(res, get(v * 2 + 1, tl, tm, l, r, x));
        }
        if(r > tm) {
            res = max(res, get(v * 2 + 2, tm + 1, tr, l, r, x));
        }
        return res;
    }
}

int mex[N];

int main() {

    scanf("%d %d", &n, &m);

    for(int l, r, i = 0;i < m;i++) {
        scanf("%d %d", &l, &r);
        l--;
        r--;
        g[l].push_back(r);
    }

    for(int i = 0;i < n;i++) {
        sort(ALL(g[i]));
    }

    build(0, 0, n - 1);

    for(int mx, cur, i = 0;i < n;i++) {
        if(i % SQRT == 0) {
            cur = -1;
            mx = i + SQRT - 1;
        }
        int idx = upper_bound(ALL(g[i]), mx) - g[i].begin() - 1;
        if(idx >= 0 && idx < (int)g[i].size()) {
            cur = max(cur, g[i][idx]);
        }
        mex[i] = idx;
    }

    int q;
    scanf("%d", &q);

    for(int x, y, iter = 0;iter < q;iter++) {
        scanf("%d %d", &x, &y);
        x--, y--;

        int firstBlock = x / SQRT;
        int lastBlock = y / SQRT;
        int prev = x;
        int start = x;

        while(x / SQRT == firstBlock) {
            int next = get(0, 0, n - 1, prev, x, y);
            if(next > x) {
                prev = x;
                x = next;
            }else {
                break;
            }
        }

        if(x / SQRT != firstBlock) {
            while(x / SQRT != lastBlock) {
                int next = mex[x];
                if(next > x) {
                    x = next;
                    next = get(0, 0, n - 1, (x / SQRT) * SQRT, x, y);
                    if(next > x) {
                        x = next;
                    }else {
                        break;
                    }
                }else {
                    break;
                }
            }
        }

        prev = x;

        while(1) {
            int next = get(0, 0, n - 1, start, x, y);
            if(next > x) {
                prev = x;
                x = next;
            }else {
                break;
            }
        }

        printf("%d\n", x + 1);
    }

    return 0;
}