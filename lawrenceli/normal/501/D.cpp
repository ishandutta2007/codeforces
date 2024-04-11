#include <bits/stdc++.h>

using namespace std;

const int MAXN = 200100;

int n, p[2][MAXN], q[MAXN], bit[MAXN];

int query(int i) {
    int ret = 0;
    for (i++; i>0; i-=i&-i) ret += bit[i];
    return ret;
}

void update(int i, int v) {
    for (i++; i<=n; i+=i&-i) bit[i] += v;
}

int main() {
    ios_base::sync_with_stdio(0);
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i=0; i<2; i++) {
        memset(bit, 0, sizeof(bit));
        for (int j=0; j<n; j++) update(j, 1);
        for (int j=0; j<n; j++) {
            cin >> p[i][j];
            int x = p[i][j];
            p[i][j] = query(x)-1;
            update(x, -1);
        }
    }

    for (int i=n-1; i>=0; i--) {
        q[i] += p[0][i]+p[1][i];
        int j = n-1-i;
        if (q[i]>j) {
            if (i>0) q[i-1]++;
            q[i] -= j+1;
        }
        assert(q[i] <= j);
    }

    memset(bit, 0, sizeof(bit));
    for (int i=0; i<n; i++) update(i, 1);
    for (int i=0; i<n; i++) {
        int lo = 0, hi = n-1;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (query(mid)-1 >= q[i]) hi = mid;
            else lo = mid+1;
        }
        cout << lo << ' ';
        update(lo, -1);
    }
}