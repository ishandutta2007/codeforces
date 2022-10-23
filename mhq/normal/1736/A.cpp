#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifdef DEBUG
    freopen("input.txt", "r", stdin);
#endif
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int cnt0 = 0;
        int cnt1 = 0;
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (a[i] != b[i]) {
                if (a[i] == 0) cnt0++;
                else cnt1++;
            }
        }
        if (cnt0 == 0 || cnt1 == 0) {
            cout << max(cnt0, cnt1) << '\n';
        }
        else {
            cout << abs(cnt0 - cnt1) + 1 << '\n';
        }

    }
    return 0;
}