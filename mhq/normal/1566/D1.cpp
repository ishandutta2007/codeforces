#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 305;
int a[maxN * maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n * m; i++) {
            cin >> a[i];
        }
        int s = n * m;
        int cnt = 0;
        for (int i = 1; i <= s; i++) {
            for (int j = i + 1; j <= s; j++) {
                if (a[i] < a[j]) cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}