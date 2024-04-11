#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int n;
const int maxN = 1005;
int x[maxN], y[maxN];
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];
    while (true) {
        bool ok = false;
        for (int i = 2; i <= n; i++) {
            if (abs(x[i] + y[i]) % 2 != abs(x[1] + y[1]) % 2) {
                ok = true;
                break;
            }
        }
        if (ok) {
            vector < int > a;
            for (int i = 1; i <= n; i++) {
                if (abs(x[i] + y[i]) % 2 == 0) a.push_back(i);
            }
            cout << a.size() << '\n';
            for (int v : a) cout << v << " ";
            return 0;
        }
        if (abs(x[1] + y[1]) % 2 == 1) {
            for (int i = 1; i <= n; i++) {
                y[i] -= 1;
            }
        }
        bool ok2 = false;
        for (int i = 1; i <= n; i++) {
            if (abs(x[i]) % 2 != abs(x[1]) % 2) {
                ok2 = true;
                break;
            }
        }
        if (ok2) {
            vector < int > a;
            for (int i = 1; i <= n; i++) {
                if (abs(x[i]) % 2 == 0) a.push_back(i);
            }
            cout << a.size() << '\n';
            for (int v : a) cout << v << " ";
            return 0;
        }
        for (int i = 1; i <= n; i++) {
            if (abs(x[i]) % 2 == 0) x[i] /= 2;
            else x[i] = (x[i] - 1) / 2;
            if (abs(y[i]) % 2 == 0) y[i] /= 2;
            else y[i] = (y[i] - 1) / 2;
        }
    }
    return 0;
}