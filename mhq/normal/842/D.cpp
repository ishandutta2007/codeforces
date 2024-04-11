#include <bits/stdc++.h>
using namespace std;
const int maxN = (1 << 19) + 4;
int n, m;
int b[maxN];
struct node {
    int next[2];
    int path;
    node() {
        for (int i = 0; i < 2; i++) next[i] = -1;
        path = 0;
    }
};
node t[19 * maxN + 3];
int sz = 1;
void add(int x) {
    int v = 0;
    for (int j = 18; j >= 0; j--) {
        int bit = (x >> j) & 1;
        if (t[v].next[bit] == -1) {
            t[v].next[bit] = sz;
            sz++;
        }
        v = t[v].next[bit];
        t[v].path++;
    }
}
void solve(int x) {
    int mex = 0;
    int v = 0;
    for (int j = 18; j >= 0; j--) {
        int bit = (x >> j) & 1;
        int to = t[v].next[bit];
        if (to == -1) {
            cout << mex << '\n';
            return ;
        }
        if (t[to].path == (1 << j)) {
            mex += (1 << j);
            v = t[v].next[1 ^ bit];
            continue;
        }
        else v = to;
    }
    cout << mex << '\n';
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    int x;
    int curxor = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(b, b + n);
    n = unique(b, b + n) - b;
    for (int i = 0; i < n; i++) {
        add(b[i]);
    }
    for (int i = 0; i < m; i++) {
        cin >> x;
        curxor = x ^ curxor;
        solve(curxor);
    }
    return 0;
}