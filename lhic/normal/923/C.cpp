#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using namespace std;

const int MAXN = 400002;
const int B = 30;
const int NODES = MAXN * B;


int cnt[NODES];
int e[NODES][2];
int a[MAXN];
int nd = 2;

int main() {
#ifdef BZ
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cout.tie(nullptr); cin.tie(nullptr);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        int cur = 1;
        for (int j = B - 1; j >= 0; --j) {
            int d = (x >> j) & 1;
            if (e[cur][d] == 0) {
                e[cur][d] = nd++;
            }

            cur = e[cur][d];
            ++ cnt[cur];
        }
    }

    for (int i = 0; i < n; ++i) {
        int cur = 1;
        int x = a[i];

        int ans = 0;
        for (int j = B - 1; j >= 0; --j) {
            int d = (x >> j) & 1;
            if (cnt[e[cur][d]] == 0) {
                d ^= 1;
                ans += (1 << j);
            }

            cur = e[cur][d];
            --cnt[cur];
        }

        cout << ans << " ";
    }
}