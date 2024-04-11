#include <bits/stdc++.h>

using namespace std;
int n;
long long mx, m[200005];
vector<long long> v[200005];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        int sz;
        cin >> sz;
        while (sz--) {
            long long x;
            cin >> x;
            m[i] = max(m[i], x);
            v[i].push_back(x);
        }
        mx = max(mx, m[i]);
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) ans += (mx - m[i]) * v[i].size();
    cout << ans << endl;
    return 0;
}