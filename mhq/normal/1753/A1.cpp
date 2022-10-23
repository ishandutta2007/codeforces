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
        vector<int> a(n + 1);
        int s = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            s += a[i];
        }
        if (s % 2 != 0) {
            cout << -1 << '\n';
        }
        else {
            vector<int> segs;
            int need = 0;
            for (int i = 1; i <= n; i += 2) {
                segs.emplace_back(i);
                if (a[i] != a[i + 1]) {
                    segs.emplace_back(i + 1);
                }
            }
            segs.emplace_back(n + 1);
            cout << segs.size() - 1<< '\n';
            for (int i = 0; i + 1 < segs.size(); i++) {
                cout << segs[i] << " " << segs[i + 1] - 1 << '\n';
            }
        }
    }
    return 0;
}