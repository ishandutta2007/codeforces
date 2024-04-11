#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 505;
int a[maxN];
int b[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
//    freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        if (n % 2 == 1) {
            if (a[(n + 1) / 2] != b[(n + 1) / 2]) {
                cout << "No\n";
                continue;
            }
        }
        int le = n / 2;
        int ri = n / 2 + 1;
        if (n % 2 == 1) {
            le = (n + 1) / 2;
            ri = (n + 1) / 2;
        }
        bool ok = true;
        vector < pair < int, int > > all1, all2;
        while (le > 0) {
            if (a[le] <= a[ri]) all1.emplace_back(a[le], a[ri]);
            else all1.emplace_back(a[ri], a[le]);
            if (b[le] <= b[ri]) all2.emplace_back(b[le], b[ri]);
            else all2.emplace_back(b[ri], b[le]);
            le--;
            ri++;
        }
        sort(all1.begin(), all1.end());
        sort(all2.begin(), all2.end());
        ok = (all1 == all2);
        if (!ok) {
            cout << "No\n";
        }
        else {
            cout << "Yes\n";
        }
    }
    return 0;
}