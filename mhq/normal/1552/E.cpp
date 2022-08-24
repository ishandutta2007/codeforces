#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
typedef long long ll;
int n, k;
const int maxN = 105;
int x[maxN][maxN];
int sz[maxN];
int a[maxN], b[maxN];
bool used[maxN];
void solve(int from, int to) {
    int cur = k - 1;
    for (int len = 0; len < to - from + 1; len++) {
        int best = -1;
        for (int i = from; i <= to; i++) {
            if (used[i]) continue;
            if (best == -1 || (x[best][cur] < x[i][cur])) best = i;
        }
        assert(best != -1);
        used[best] = true;
        a[best] = x[best][cur];
        b[best] = x[best][cur + 1];
        cur--;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (int i = 1; i <= n * k; i++) {
        int clr;
        cin >> clr;
        sz[clr]++;
        x[clr][sz[clr]] = i;
    }
    for (int i = 1; i <= n; i += k - 1) {
        solve(i, min(i + k - 2, n));
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " " << b[i] << '\n';
    }
    return 0;
}