#include <cstdio>
#include <iostream>
#include <algorithm>
#include <ios>

using namespace std;

const int MAXN = 3005;

int n, m, a[MAXN], b[MAXN];

bool check(int num) {
    int p = m-1;
    for (int i=n-1-num; i>=0; i--) {
        if (a[i] > b[p]) return 0;
        p--;
    }
    return 1;
}

int main() {
    ios :: sync_with_stdio(0);

    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> m;
    for (int i=0; i<n; i++) cin >> a[i];
    for (int i=0; i<m; i++) cin >> b[i];

    sort(a, a + n);
    sort(b, b + m);

    int lo = 0, hi = MAXN;

    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << '\n';
    return 0;
}