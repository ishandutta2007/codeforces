#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef long double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 1e5 + 5;

int n, k;
int a[N];
vec< int > pos[N];
int f[N];

vec< int > tree[4 * N];

void merge(int v) {
    int ls = (int)tree[v << 1].size();
    int rs = (int)tree[v << 1 | 1].size();
    int i = 0;
    int j = 0;
    while(i < ls && j < rs) {
        if(tree[v << 1][i] < tree[v << 1 | 1][j]) {
            tree[v].push_back(tree[v << 1][i++]);
        }else {
            tree[v].push_back(tree[v << 1 | 1][j++]);
        }
    }
    while(i < ls) tree[v].push_back(tree[v << 1][i++]);
    while(j < rs) tree[v].push_back(tree[v << 1 | 1][j++]);
}

void build(int v, int tl, int tr) {
    if(tl == tr) {
        tree[v].push_back(f[tl]);
    }else {
        int tm = (tl + tr) >> 1;
        build(v << 1, tl, tm);
        build(v << 1 | 1, tm + 1, tr);
        merge(v);
    }
}

int get(int v, int tl, int tr, int l, int r) {
    if(l <= tl && tr <= r) {
        return upper_bound(ALL(tree[v]), r) - tree[v].begin();
    }else {
        int tm = (tl + tr) >> 1;
        int res = 0;
        if(l <= tm) res += get(v << 1, tl, tm, l, r);
        if(r > tm) res += get(v << 1 | 1, tm + 1, tr, l, r);
        return res;
    }
}

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    scanf("%d %d", &n, &k);

    for(int i = 1;i <= n;i++) {
        scanf("%d", &a[i]);
        f[i] = n + 1;
        pos[a[i]].push_back(i);
    }

    for(int x = 0;x < N;x++) {
        for(int i = 0;i + k < (int)pos[x].size();i++) {
            f[pos[x][i]] = pos[x][i + k];
        }
    }

    build(1, 1, n);

    int q;
    int last = 0;

    scanf("%d", &q);

    for(int l, r, x, y, iter = 0;iter < q;iter++) {
        scanf("%d %d", &x, &y);
        l = ((x + last) % n) + 1;
        r = ((y + last) % n) + 1;
        if(l > r) swap(l, r);
        last = r - l + 1 - get(1, 1, n, l, r);
        printf("%d\n", last);
    }

    return 0;
}