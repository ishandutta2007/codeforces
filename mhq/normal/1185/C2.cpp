#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n, m;
const int maxN = 2 * (int)1e5 + 100;
int cnt[maxN];
int t[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    int total = 0;
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        int need = max(0, total - m + t[i]);
        int f = 0;
        for (int j = 100; j >= 1; j--) {
            if (need == 0) break;
            if (j * cnt[j] >= need) {
                f += (need + j - 1) / j;
                break;
            }
            need -= cnt[j] * j;
            f += cnt[j];
        }
        total += t[i];
        cnt[t[i]]++;
        cout << f << " ";
    }
    return 0;
}