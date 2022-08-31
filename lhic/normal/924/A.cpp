#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;


ll a[60];

int main() {
#ifdef PAUNSVOKNO
    freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false); cout.setf(ios::fixed); cout.precision(20); cout.tie(nullptr); cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (char c : s) {
            a[i] = a[i] * 2 + (c == '#');
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if ((a[i] & a[j]) && a[i] != a[j]) {
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";
}