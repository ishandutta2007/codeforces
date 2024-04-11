#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);

    int q;
    cin >> q;
    vector<int> a;
    while (q--) {
        string s;
        cin >> s;
        if (s[0] == 's') {
            ll r = 0;
            for (int i = 2; i < int(a.size()); i += 5)
                r += a[i];
            cout << r << '\n';
        } else {
            int x;
            cin >> x;
            auto i = lower_bound(a.begin(), a.end(), x);
            if (s[0] == 'a')
                a.insert(i, x);
            else
                a.erase(i);
        }
    }
}