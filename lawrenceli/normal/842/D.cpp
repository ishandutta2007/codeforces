#include <bits/stdc++.h>

using namespace std;

const int maxn = 1 << 19;

int n, m;
bool ar[maxn];
int tree[2 * maxn];

void init() {
    for (int i = 2 * maxn - 1; i > 0; i--) {
        if (i >= maxn) tree[i] = ar[i - maxn];
        else tree[i] = tree[2 * i] + tree[2 * i + 1];
    }
}

int qry(int x) {
    int cur = 1;
    int k = 18;
    while (cur < maxn) {
        //cout << cur << endl;
        if (!(x & 1 << k)) {
            if (tree[2 * cur] < (1 << k)) cur = 2 * cur;
            else cur = 2 * cur + 1;
        } else {
            if (tree[2 * cur + 1] < (1 << k)) cur = 2 * cur + 1;
            else cur = 2 * cur;
        }
        k--;
    }
    return (cur - maxn) ^ x;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        ar[x] = 1;
    }

    init();

    int x = 0;
    for (int i = 0; i < m; i++) {
        int y; cin >> y;
        x ^= y;
        cout << qry(x) << '\n';
    }
}