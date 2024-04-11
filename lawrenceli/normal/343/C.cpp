#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MAXN = 100010;
const ll INF = 1e15;

int n, m, lt, rt;
ll h[MAXN], p[MAXN], lo, hi;

bool pos(ll mid) {
    lt = 0;
    for (int i=0; i<n; i++) {
        if (h[i] - p[lt] > mid) return 0;
        if (p[lt] <= h[i]) {
            rt = lt;
            while (rt < m && (p[rt] <= h[i] || 2*(h[i]-p[lt]) + p[rt]-h[i] <= mid || 2*(p[rt]-h[i]) + h[i]-p[lt] <= mid)) rt++;
            lt = rt;
        } else {
            while (lt < m && p[lt] - h[i] <= mid) lt++;
        }
        if (lt == m) return 1;
    }
    return 0;
}

int main() {
    if (fopen("input.txt", "r")) {
        freopen("input.txt", "r", stdin);
    }
    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> h[i];
    for (int i=0; i<m; i++) cin >> p[i];
    lo = 0, hi = INF;
    while (lo < hi) {
        ll mid = (lo + hi) / 2;
        if (pos(mid)) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << endl;
}