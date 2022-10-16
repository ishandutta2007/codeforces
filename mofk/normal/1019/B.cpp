#include <bits/stdc++.h>

using namespace std;

int n;
int a[200005];

void answer(int x) {
    cout << "! " << x << endl;
    exit(0);
}

void ask(int x) {
    cout << "? " << x << endl;
    int y; cin >> y;
    a[x] = y;
    a[x + 4 * n] = y;
}

void solve(int l, int r, int u, int v) {
    int dif1 = a[l] - a[u], dif2 = a[r] - a[v];
    if (1LL * dif1 * dif2 > 0) return;
    int lo = 0, hi = n - 1;
    while (lo < hi) {
        int mid = lo + hi + 1 >> 1;
        ask(l + mid);
        ask(u + mid);
        int dif = a[l + mid] - a[u + mid];
        if (dif == 0) answer(l + mid);
        else if (1LL * dif * dif1 < 0) hi = mid - 1;
        else lo = mid;
    }
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    if (n % 4 != 0) answer(-1);
    n /= 4;
    ask(1);
    ask(1 + n);
    ask(1 + n + n);
    ask(1 + n + n + n);
    if (a[1] == a[1 + 2 * n]) answer(1);
    if (a[1 + n] == a[1 + 3 * n]) answer(1 + n);
    solve(1, 1 + n, 1 + 2 * n, 1 + 3 * n);
    solve(1 + n, 1 + 2 * n, 1 + 3 * n, 1 + 4 * n);
    answer(-1);
    return 0;
}