#include <bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 200000 + 5;
bool reb(int n, vector<int> v, int k) {
    vector<int> p;
    for (int i = 1; i <= n; i += 1) {
        int x = v[i];
        if (x != k) {
            p.push_back(x);
        }
    }
    vector<int> q = p;
    reverse(q.begin(), q.end());
    for (int i = 0; i < q.size(); i += 1) {
        if (p[i] != q[i]) return 0;
    }
    return 1;
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i += 1)
        cin >> a[i];
    for (int i = 1; i <= n / 2; i += 1) {
        if (a[i] != a[n + 1 - i]) {
            int A = reb(n, a, a[i]);
            int B = reb(n, a, a[n + 1 - i]);
            if (A || B) {
                cout << "YES\n";
                return;
            }
            else {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int T = 1;
    cin >> T;
    while (T--) {
        solve();
    }
}