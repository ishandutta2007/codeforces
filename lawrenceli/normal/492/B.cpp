#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int ll

const int MAXN = 1005;

int n, l, a[MAXN];

bool check(int d) {
    int r = -1;
    for (int i=0; i<n; i++) {
        if (a[i]-d > r+1) return 0;
        r = a[i]+d;
    }
    return r >= l;
}

main() {
    if (fopen("input.txt", "r")) freopen("input.txt", "r", stdin);

    cin >> n >> l; l *= 2;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        a[i] *= 2;
    }
    sort(a, a+n);

    int lo = 0, hi = 2e9;
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        if (check(mid)) hi = mid;
        else lo = mid+1;
    }

    cout << fixed << setprecision(10) << double(lo)/2;
}