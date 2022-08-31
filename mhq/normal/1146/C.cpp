#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
   //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        int mx = 0;
        for (int i = 0; i < 9; i++) {
            vector < int > f[2];
            for (int j = 1; j <= n; j++) {
                if ((j >> i) & 1) f[1].push_back(j);
                else f[0].push_back(j);
            }
            if (f[0].empty() || f[1].empty()) continue;
            cout << f[0].size() << " " << f[1].size() << " ";
            for (int v : f[0]) cout << v << " ";
            for (int v : f[1]) cout << v << " ";
            cout << endl;
            int ans;
            cin >> ans;
            mx = max(mx, ans);
        }
        cout << "-1 " << mx << endl;
    }
    return 0;
}