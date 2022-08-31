#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, q;
const int maxN = (int)1e5 + 100;
int a[2][maxN];
int calc(int r, int c) {
    int f = 0;
    if (a[r ^ 1][c] && a[r][c]) f++;
    for (int d = c - 1; d <= c; d++) {
        int x = d;
        if (x < 0 || x == n) continue;
        if (a[0][x] && !a[1][x] && a[1][x + 1] && !a[0][x + 1]) f++;
        if (!a[0][x] && a[1][x] && !a[1][x + 1] && a[0][x + 1]) f++;
    }
    return f;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> q;
    int cnt = 0;
    for (int i = 0; i < q; i++) {
        int r, c;
        cin >> r >> c;
        r--;
        c--;
        int d = calc(r, c);
        cnt -= d;
        a[r][c] = 1 ^ a[r][c];
        d = calc(r, c);
        cnt += d;
        if (cnt) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}