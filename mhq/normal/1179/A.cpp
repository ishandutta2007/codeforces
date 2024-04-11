#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
const int maxN = 3 * (int)1e5 + 100;
int q;
int ans[maxN][2];
int n;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n >> q;
    deque < int > f;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        f.push_back(x);
    }
    for (int i = 1; i <= 2 * n; i++) {
        int a1 = f.front();
        f.pop_front();
        int a2 = f.front();
        f.pop_front();
        ans[i][0] = a1;
        ans[i][1] = a2;
        if (a1 < a2) swap(a1, a2);
        f.push_front(a1);
        f.push_back(a2);
    }
    int l = 2 * n + 1;
    for (int i = 0; i < q; i++) {
        ll m;
        cin >> m;
        if (m <= 2 * n) {
            cout << ans[m][0] << " " << ans[m][1] << '\n';
        }
        else {
            ll s = m - 2 * n - 1;
            cout << f.front() << " " << f[(s % (n - 1)) + 1] << '\n';
        }
    }
    return 0;
}