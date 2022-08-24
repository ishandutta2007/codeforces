#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector < int > f(n);
        bool ok = true;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            x += i;
            x %= n;
            if (x < 0) x += n;
            if (f[x] > 0) {
                ok = false;
            }
            f[x]++;
        }
        if (ok)cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}