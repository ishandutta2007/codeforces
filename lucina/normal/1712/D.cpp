#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
int n, k;
int a[nax];
int b[nax];

/**
    two cases
    1) if first k smallest element is adjacent,
    we can make it to min(1e9, a[k + 1]) * 2)

    2) if first k smallest is not adjacent,
    we can make it to min(a[n], a[k + 1] * 2)
    In this case, can we do better?
    sacrifice one element to min(1e9, a[k] * 2)
*/

void solve() {
    cin >> n >> k;
    int mx = 0;
    for (int i = 1 ; i <= n ; ++ i) {
        cin >> a[i];
        b[i] = a[i];
        if (i > 0)
        mx = max(mx, min(a[i], a[i - 1]));
    }
    sort(b + 1, b + 1 + n);
    vector <int> idx;
    static int c[nax];
    bool adj = false;
    for (int i = 1 ; i <= n ; ++ i) {
        if (a[i] <= b[k]) {
            if (!idx.empty() && k > 1 && idx.back() + 1 == i) mx = 1e9;
            idx.push_back(i);
        }
        c[i] = a[i];
    }
    const int INF = 1e9;

    for (int j : idx) {
        if (j > 1) mx = max(mx, a[j - 1]);
        if (j < n) mx = max(mx, a[j + 1]);
    }
    int ans = -1;
    b[n + 1] = INF;

    /**
        ...., calm down
        1) The shortest path will be at most (b[k + 1] * 2)
        2) Let's say we replace some of first k element and it happened to be adjacent to each other
        The answer is basically min(INF, b[k + 1] * 2)
        3) Let's say non of the first k-element are adjacent
        The restriction of b[k + 1] still hold, we need to find best adjacent element?

        Let's say we want to place something adjacent to b[n]

        Now, the weight is basically b[n] and we need to min it with b[k]
    */
    ans = max(ans, min(mx, b[k + 1] * 2));

    ans = max(ans, min(b[n], b[k] * 2));
    if (k > 1) ans = max(ans, min(INF, b[k] * 2));

    cout << ans << '\n';
}

 main() {
    cin.tie(0)->sync_with_stdio(false);

    int T;
    for (cin >> T ; T -- ;) {
        solve();
    }
}