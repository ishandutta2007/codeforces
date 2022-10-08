
#include <bits/stdc++.h>

#define ll long long
using namespace std;

const int M = 998244353;
const int N = 505;
int n;
int c[N], k[N];
ll dp[N][N];
// minimum color segtree
int tree[4 * N];

void build(int i, int l, int r) {
    if(l == r) {
        tree[i] = c[l];
        return;
    }
    int m = l + (r - l) / 2;
    build(2 * i + 1, l, m);
    build(2 * i + 2, m + 1, r);
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}

int getMin(int i, int l, int r, int L, int R) {
    if(L <= l && r <= R) {
        return tree[i];
    }else if(l > R || r < L) {
        return N;
    }
    int m = l + (r - l) / 2;
    return min(getMin(2 * i + 1, l, m, L, R),
               getMin(2 * i + 2, m + 1, r, L, R));
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n >> n;
    for(int i = 0; i < n; i++) {
        cin >> c[i];
        k[c[i]] = i;
    }
    build(0, 0, n - 1);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            dp[i][j] = 1;
        }
    }

    for(int d = 1; d < n; d++) {
        for(int i = 0; i + d < n; i++) {
            int j = i + d;
            int C = getMin(0, 0, n - 1, i, j);
            dp[i][j] = 0;
            ll num1 = 0, num2 = 0;
            for(int l = i; l <= k[C]; l++) {
                num1 += (i <= l - 1 ? dp[i][l - 1] : 1) * (l <= k[C] - 1 ? dp[l][k[C] - 1] : 1);
                num1 %= M;
            }
            for(int r = k[C]; r <= j; r++) {
                num2 += (k[C] + 1 <= r ? dp[k[C] + 1][r] : 1) * (r + 1 <= j ? dp[r + 1][j] : 1);
                num2 %= M;
            }
            dp[i][j] = (num1 * num2) % M;
        }
    }
    cout << dp[0][n - 1] << endl;
}