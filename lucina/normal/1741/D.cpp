#include<bits/stdc++.h>
using namespace std;
const int nax = 3e5 + 10;
const int INF = 1e9;
int n;
int a[nax];

int solve(int l, int r) {
    if (l == r) return 0;
    int mid = l + r >> 1;
    int s1 = 0, s2 = 0;

    for (int i = l ; i <= mid ; i ++) {
        if (a[i] <= mid) s1 += 1;
    }
    for (int i = mid + 1 ; i <= r ; ++ i) {
        if (a[i] <= mid) s2 += 1;
    }
    if (s1 && s2) {
        return -INF;
    }
    int res = 0;
    if (s2) {
        for (int i = l ; i <= mid ; ++ i) {
            swap(a[i], a[mid + (i - l + 1)]);
        }
        res += 1;
    }
    res += solve(l, mid);
    res += solve(mid + 1, r);
    return res;
}

void solve_test_case() {
    cin >> n;
    for (int i = 1 ; i <= n ; ++ i)
        cin >> a[i];
    cout << max(-1, solve(1, n)) << '\n';
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int T;

    for (cin >> T ; T -- ;) {
        solve_test_case();
    }
}