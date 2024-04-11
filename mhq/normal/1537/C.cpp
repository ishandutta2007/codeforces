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
        vector<int> h(n);
        for (int& v : h) cin >> v;
        sort(h.begin(), h.end());
        if (n == 2) {
            cout << h[0] << " " << h[1] << '\n';
            continue;
        }
        int x = 0;
        for (int i = 0; i + 1 < n; i++) {
            if (h[i + 1] - h[i] < h[x + 1] - h[x]) x = i;
        }
        for (int i = x + 1; i < n; i++) cout << h[i] << " ";
        for (int i = 0; i <= x; i++) cout << h[i] << " ";
        cout << '\n';
    }
    return 0;
}