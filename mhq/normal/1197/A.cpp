#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    int tst;
    cin >> tst;
    while (tst--) {
        int n;
        cin >> n;
        vector < int > a(n);
        for (int& v : a) cin >> v;
        sort(a.begin(), a.end());
        for (int k = 1; ; k++) {
            if (a.size() < k + 2 || a[n - 2] < k + 1) {
                cout << k - 1 << '\n';
                break;
            }
        }
    }
    return 0;
}