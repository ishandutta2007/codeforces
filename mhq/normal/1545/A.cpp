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
        int n;
        cin >> n;
        vector<pair<int,int>> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        int r = 0;
        bool ok = true;
        while (r < a.size()) {
            int nr = r;
            while (nr < a.size() && a[nr].first == a[r].first) nr++; nr--;
            int f[2] = {0, 0};
            for (int x = r; x <= nr; x++) {
                f[x % 2]++;
                f[a[x].second % 2]--;
            }
            if (f[0] != 0 || f[1] != 0) {
                ok = false;
                break;
            }
            r = nr + 1;
        }
        if (ok) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}