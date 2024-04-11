
#include <bits/stdc++.h>

#define ll long long
using namespace std;

// i 1 2 3 ... i-1 i+1 i+2 ... n

// distance between x and y (assume x < y)
// if x and y are from [1, ..., i-1]. No change in distance.
// if x > i, no change.

// if y = i, distance is x.     (changed from i - x)
// increase of x - (i - x) = 2x - i.
// if x = i, distance is y - 1. (changed from y - i)
// increase of y - 1 - y + i = i - 1.
// if x < i, y > i, distance is decreased by 1.

// initially, set p_1, ..., p_n all to p_1.
// for each (x, y) = sorted(x_k, x_{k+1}):
// increase p_x by x - 1.
// increase p_y by 2x - y.
// decrease the range [x + 1, y - 1] by 1.

const int N = 2e5 + 5;
int n, m;
int x[N];
ll p[N];
ll segtree[4 * N];

void segadd(int i, int l, int r, int L, int R, ll x) {
    if(l > R || r < L) return;
    if(l >= L && r <= R) {
        segtree[i] += x;
        return;
    }
    int m = l + (r - l) / 2;
    segadd(2 * i + 1, l, m, L, R, x);
    segadd(2 * i + 2, m + 1, r, L, R, x);
}
ll segval(int i, int l, int r, int I) {
    if(l == r && l == I) {
        return segtree[i];
    }
    int m = l + (r - l) / 2;
    if(I <= m) {
        return segtree[i] + segval(2 * i + 1, l, m, I);
    }else {
        return segtree[i] + segval(2 * i + 2, m + 1, r, I);
    }
}

void upd(int x, int y) {
    if(x == y) return;
    if(x > y) swap(x, y);
    p[x] += x - 1;
    p[y] += 2 * x - y;
    if(x + 2 <= y) {
        segadd(0, 1, n, x + 1, y - 1, -1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> x[i];
        if(i > 0) {
            p[1] += abs(x[i] - x[i - 1]);
        }
    }
    for(int i = 2; i <= n; i++) {
        p[i] = p[1];
    }
    for(int i = 1; i < m; i++) {
        upd(x[i], x[i - 1]);
    }
    for(int i = 1; i <= n; i++) {
        cout << (p[i] + segval(0, 1, n, i)) << " ";
    }
    cout << endl;
}