#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n, l;
        cin >> n >> l;
        vector<int> a(n + 2);
        a[0] = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        a[n + 1] = l;
        vector<ld> tim1(n + 2);
        vector<ld> tim2(n + 2);
        for (int i = 1; i <= n + 1; i++) {
            tim1[i] = tim1[i - 1] + ((ld)a[i] - a[i - 1]) / i;
        }
        for (int i = n; i >= 0; i--) {
            tim2[i] = tim2[i + 1] + ((ld)a[i + 1] - a[i]) / (n + 1 - i);
        }
        for (int i = 1; i <= n + 1; i++) {
            if (tim1[i] >= tim2[i]) {
                int f1 = i;
                int f2 = n + 2 - i;
                ld p = tim2[i] - tim1[i - 1] + (ld)a[i] / f2 + (ld)a[i - 1] / f1;
                ld x = (p / ((ld)1 / f1 + (ld)1 / f2));
                cout << fixed << setprecision(12) << (x - a[i - 1]) / f1 + tim1[i - 1] << '\n';
                break;
            }
        }
    }
    return 0;
}