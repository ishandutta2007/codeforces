#include <bits/stdc++.h>

using namespace std;

#define vec vector
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
typedef double ld;
typedef pair< int, int > pii;
typedef pair< ll, ll > pll;

int const inf = 1000 * 1000 * 1000;
ll const inf64 = 1ll * inf * inf;

int const N = 2e5 + 5;
int const SQRT = 450;

int n, q;
int p[N];

int f[SQRT + 10][N + 10];
int pr[SQRT + 10][SQRT + 10];

int get(int bl, int p) {
    if(p < 0) return 0;
    int res = 0;
    if(p / SQRT > 0) {
        res += pr[bl][p / SQRT - 1];
    }
    res += f[bl][p];
    return res;
}

int get(int bl, int l, int r) {
    if(l > r) return 0;
    return get(bl, r) - get(bl, l - 1);
}

void upd(int bl, int pos, int val) {
    for(int i = pos / SQRT;i < SQRT;i++) {
        pr[bl][i] += val;
    }
    for(int i = pos;i <= n && i / SQRT == pos / SQRT;i++) {
        f[bl][i] += val;
    }
}

ll res = 0;

void change(int pos, int x) {
    int y = p[pos];
    upd(pos / SQRT, y, -1);
    upd(pos / SQRT, x, 1);
    p[pos] = x;
    for(int j = pos + 1;j <= n && pos / SQRT == j / SQRT;j++) {
        res -= (p[j] != -1) & (y > p[j]);
        res += (p[j] != -1) & (x > p[j]);
    }
    for(int j = pos - 1;j >= 1 && pos / SQRT == j / SQRT;j--) {
        res -= (p[j] != -1) & (p[j] > y);
        res += (p[j] != -1) & (p[j] > x);
    }
    for(int bl = pos / SQRT + 1;bl <= n / SQRT;bl++) {
        if(y < x) {
            res += get(bl, y, x - 1);
        }else {
            res -= get(bl, x, y - 1);
        }
    }
    for(int bl = pos / SQRT - 1;bl >= 0;bl--) {
        if(x < y) {
            res += get(bl, x + 1, y);
        }else {
            res -= get(bl, y + 1, x);
        }
    }
}

int main() {

#ifdef maximumSHOT
    freopen("input.txt", "r", stdin);
#endif

    ios_base::sync_with_stdio(0);

    cin >> n >> q;

    for(int i = 1;i <= n;i++) {
        p[i] = i;
        upd(i / SQRT, i, 1);
    }

    for(int x, y, l, r, iter = 0;iter < q;iter++) {
        cin >> l >> r;
        if(l > r) swap(l, r);
        if(l < r) {
            x = p[l];
            y = p[r];
            change(l, y);
            change(r, x);
        }
        cout << res << "\n";
    }

    return 0;
}